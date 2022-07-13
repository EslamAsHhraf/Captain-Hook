#include <stdint.h>
#include <Stepper.h>
/*
-ve for down
+ve for up
+ve clockwise
-ve anticlockwise
*/

#define WATER 11*15
#define OIL 15*15
#define NON_KNIFE 1*15
#define KNIFE 19*15 + 15
#define SERVE 6*15
#define A2LB 8*15
 
int  length_of_move =  5;
int  stepsPerRevolution = 200;
int  PAN_LENGTH =  length_of_move * stepsPerRevolution - 30;
int  GROUND_LENGTH = length_of_move * stepsPerRevolution + 60;
int  A2LB_LENGTH = length_of_move * stepsPerRevolution - 205;
int  NON_KNIFE_HEIGHT = length_of_move * stepsPerRevolution - 40;
int  KNIFE_HEIGHT =  200;
int  deleiverHeight = length_of_move * stepsPerRevolution - 140;
bool haveKnife = false;

#define stepSize 45
#define stepsPerRevolutionFat7y 150

//pins
#define pistonHolder1 A1
#define pistonHolder2 A0
#define pump A3
#define Kettle A5
#define knifePin A4

//food types
#define MAKE_FRIED_FRIES 0
#define MAKE_RICE 1
#define MAKE_NOODLES 2
#define MAKE_SALAD 3
#define MAKE_SALAD_SOUP 4
#define MAKE_TEA 5

//ingrediants locations
#define POTATOS 1.4
#define RICE 0.9
#define NOODLES 0.2
#define CUCUMBER 3.9
#define CARROT 2.7
#define ZUGHINI 5.5
#define SUGAR 7
#define TEA 5.6

#define interval 10000   //10 sec
#define TEA_TIME 10000   //10 sec

int order;
int quantity;
int sugar_quantity;

int water_free;
int oil_free;
int drink_free;
int pan_in_knife;
int pan_in_non_knife;

unsigned long water_finish_time;
unsigned long oil_finish_time;
unsigned long drink_finish_time;

float pos;

int Current_Location;

Stepper myStepper(stepsPerRevolutionFat7y, 10, 11, 12, 13);
Stepper ARM(stepsPerRevolution, 6, 7, 8, 9);
Stepper Base(stepsPerRevolution, 5, 4, 3, 2);

//==================================================================================================================================================================

int read_input()
{ 
  if (Serial.available() < 2) 
      return 0;
      
    order = Serial.read() - 48;
    quantity = Serial.read() - 48;

    if (order == MAKE_TEA && Serial.available())
      sugar_quantity = Serial.read() - 48;

     Serial.flush();
     return 1;
}

//fetches the pan and go to a specific location and prepares for ingredient
//if pan is already in location just go to location
void fetchAndGo(int destination)
{
  if(destination == KNIFE)
  {
    if(!pan_in_knife)
    {
      move_arm(NON_KNIFE);
      emsk(GROUND_LENGTH);
      move_arm(KNIFE);
      sybKnife();
      emskKnife();
      pan_in_non_knife = LOW;
    }
    else
    {
      emskKnife();
      pan_in_knife = LOW;
    }
   

  }
  else
  {
    if(!pan_in_non_knife)
    {
      move_arm(KNIFE);
      emskKnife();
      fixHeigth();
      sybNonKnife();
      emskNonKnife();
      pan_in_knife = LOW;
    }
    else
    {
      emskNonKnife();
      pan_in_non_knife = LOW;
    }
  }  
}

void checkAndServe()
{
  if(!water_free && millis() >= water_finish_time)
  {
    move_arm(WATER);
    emsk(PAN_LENGTH);
    move_arm(SERVE);
    syb(deleiverHeight);
    delay(3000);
    returnPan();
    water_free = HIGH;
  }
  if(!oil_free && millis() >= oil_finish_time)
  {
    move_arm(OIL);
    emsk(PAN_LENGTH);
    move_arm(SERVE);
    syb(deleiverHeight);
    delay(3000);
    returnPan();
    oil_free = HIGH;
  }

   if(!drink_free && millis() >= drink_finish_time)
     pour_water();
}

//return to the empty position, if both are empty return to NON_KNIFE by default
void returnPan()
{
  emsk(deleiverHeight);
  if(!pan_in_non_knife)
  {
    sybNonKnife();
    pan_in_non_knife = HIGH;
  }
  else
  {
    sybKnife();
    pan_in_knife = HIGH;
  }
}

//===================================================================ARM===========================================================================================
void move_arm(int location)
{
  location -= Current_Location;
  // go to the location via stepper Base
  Base.step(location);
  
  Current_Location += location;
   delay(1000);
}

// function to get the pan
 void emsk(int L){
    Base.step(20);
    delay(1000);
    ARM.step(-L);
    Base.step(-20);
    delay(1000);
    ARM.step(L);
    delay(1000);
}

// function to left the pan

 void syb(int L){
    ARM.step(-L);     
    delay(1000);
    if (haveKnife)
    {
      Base.step(-20);
    } else {
      Base.step(20);
    }
    delay(1000);
    ARM.step(L);
    delay(1000);
    if (haveKnife)
    {
      Base.step(20);
    } else {
      Base.step(-20);
    }
    haveKnife = false;
  }

void fixHeigth() {
  if (Current_Location == NON_KNIFE) {
    Base.step(40);
    Current_Location += 40;
    delay(500);
    ARM.step(GROUND_LENGTH - NON_KNIFE_HEIGHT);
    delay(500);
  } else if (Current_Location == KNIFE) {
    Base.step(-40);
    Current_Location -= 40;
    delay(500);
    ARM.step(GROUND_LENGTH - KNIFE_HEIGHT);
    delay(500);
  }
}

void emskNonKnife(){
    move_arm(NON_KNIFE);
    Base.step(20);
    delay(1000);
    ARM.step(-GROUND_LENGTH);
    Base.step(-20);
    delay(2000);
    ARM.step(NON_KNIFE_HEIGHT);
    delay(1000);
}

void emskKnife(){
    move_arm(OIL);
    delay(1000);
    Base.step(40);
    Current_Location += 40;
    delay(1000);
    ARM.step(-GROUND_LENGTH);
    move_arm(KNIFE);
    delay(4000);

    ARM.step(KNIFE_HEIGHT);
    haveKnife = true;
  
}

void a2lb(int L) {
    // go away to catch
    Base.step(20);
    delay(100);

    //down to esmsk
    ARM.step(-L);
    delay(1000);
    // go left
    Base.step(-20);
    delay(1000);
    //up 45 lenght

    ARM.step(120); //up
    delay(2000);
    
    Base.step(-150); //right
    delay(200);

    //finished then back to origin position
    Base.step(150); //left
    delay(200);

    ARM.step(-120); //down
    delay(2000);

    // go away to left
    Base.step(20);
    delay(100);

    //up
    ARM.step(L);
    delay(1000);

       // go away to left
    Base.step(-20);
    delay(100);

}

//some nonsense
  void nodd(){
    move_arm(3);
    Base.step(20);
    delay(1000);
    Base.step(-20);
    delay(1000);
    Base.step(20);
    delay(1000);
    Base.step(-20);
    delay(1000);
}

void sybNonKnife(){
    move_arm(SERVE);
    delay(1000);
    Base.step(-60);
    Current_Location -=60;
    delay(1000);
    ARM.step(-(GROUND_LENGTH- NON_KNIFE_HEIGHT));
    delay(1000);
    move_arm(NON_KNIFE);
    Base.step(10);
    delay(3000);
    ARM.step(-NON_KNIFE_HEIGHT);
    delay(1000);
    Base.step(20);
    delay(1000);
    ARM.step(GROUND_LENGTH);
    delay(1000);
    Base.step(-20);
}

void sybKnife(){
    move_arm(OIL);
    delay(1000);
    Base.step(40);
    Current_Location +=40;
    delay(1000);
    ARM.step(-(GROUND_LENGTH - 170));
    delay(1000);
    move_arm(KNIFE);
    delay(2000);
    ARM.step(-170);
    delay(1000);
    
    Base.step(35);
    delay(1000);
    ARM.step(GROUND_LENGTH);
    delay(1000);
    Base.step(-35);
    haveKnife = false;
}

//==============================================================FAT7Y=============================================================================================
void pistonMotor(bool dir,float t=1)
{
  digitalWrite(pistonHolder1,dir);
  digitalWrite(pistonHolder2,!dir);
  delay(1000*t);
  digitalWrite(pistonHolder1,0);
  digitalWrite(pistonHolder2,0);
}

void stepper_motion(float s,float e)
{
  myStepper.step((e-s)*150.0/360);
  pos=e;
}

void choose_ingredient(float order,int quantity)
{
  delay(2000);
  
      Serial.print("current position : ");
      Serial.println(pos);
      Serial.print("current order : ");
      Serial.println(order);
      stepper_motion(pos,order*stepSize);
      delay(1000);
      pistonMotor(1,0.5);
       delay(1000);
      if(order==5.5||order==7)
          stepper_motion(pos,pos-23);
      else
          stepper_motion(pos,pos+28);
      Serial.print("order after shifting : ");
      Serial.println(order);
      delay(1000);
      for(int i=0;i<quantity;i++)
  {
      Serial.println("piston moves forward ");
         pistonMotor(1);
      delay(1000);
      Serial.println("piston moves backward ");
      pistonMotor(0);
      delay(1000);

    }
    pistonMotor(1,0.5);
      delay(1000);
      if(order==5.5||order == 7)
          stepper_motion(pos,pos+23);
      else
          stepper_motion(pos,pos-28);
      delay(1000);
      pistonMotor(0,0.7);
       delay(1000);
  Serial.println("end of operation ");
  stepper_motion(pos,0);
}

//===================================================================KETTLE=========================================================================================
void pour_water()
{
   digitalWrite(Kettle, HIGH);
   digitalWrite(pump, LOW);
   delay(5000);
   digitalWrite(pump, HIGH);
   drink_free = HIGH;
}
//==================================================================MAKE FUNCTIONS=====================================================================================
void make_tea()
{
  drink_free = LOW;
  digitalWrite(Kettle, LOW);
  drink_finish_time = millis() + TEA_TIME;
  choose_ingredient(TEA, quantity);
  choose_ingredient(SUGAR, sugar_quantity);
}


void make_fried_fries()
{
  oil_free=LOW;
  fetchAndGo(NON_KNIFE);
  choose_ingredient(POTATOS, quantity);
  fixHeigth();
  
  move_arm(OIL);
  syb(PAN_LENGTH);
  oil_finish_time = millis() + interval;
}

void make_riceORnoodles(int food)
{
  water_free=LOW;
  fetchAndGo(NON_KNIFE);
  choose_ingredient(food, quantity);
  fixHeigth();
  
  move_arm(WATER);
  syb(PAN_LENGTH);
  water_finish_time = millis() + interval;
}

void make_salad()
{
  fetchAndGo(KNIFE);
  digitalWrite(knifePin, LOW);

  choose_ingredient(CARROT, quantity);
  choose_ingredient(CUCUMBER, quantity);
  delay(5000);
  digitalWrite(knifePin, HIGH);
  fixHeigth();
  
  move_arm(SERVE);
  syb(deleiverHeight);
  //a2lb
  delay(3000);
  returnPan();
}

void make_salad_soup()
{
  water_free=LOW;
  fetchAndGo(KNIFE);
  digitalWrite(knifePin, LOW);

  choose_ingredient(CARROT, quantity);
  choose_ingredient(ZUGHINI, quantity);
  delay(5000);
  digitalWrite(knifePin, HIGH);
  fixHeigth();
  
  move_arm(WATER);
  syb(PAN_LENGTH);
  water_finish_time = millis() + interval;
}

//==========================================================SETUP===============================================================================================
void setup() {
  Serial.begin(9600);  

  pinMode(pump, OUTPUT);
  pinMode(Kettle, OUTPUT);
  pinMode(knifePin, OUTPUT);

  myStepper.setSpeed(20);
  pinMode(pistonHolder1,OUTPUT);
  pinMode(pistonHolder2,OUTPUT);

  ARM.setSpeed(50);
  Base.setSpeed(5);

  water_free = HIGH;
  oil_free = HIGH;
  drink_free = HIGH;

  //initially pans are in place
  pan_in_knife = HIGH;
  pan_in_non_knife = HIGH;

  pos = 0;
  Current_Location = 0;

  digitalWrite(Kettle, HIGH);
  digitalWrite(pump,HIGH);
  digitalWrite(knifePin, HIGH);
}

//==================================================================================================================================================================
//                                                                    MAIN LOOP
//==================================================================================================================================================================
void loop() {  

  int orderAvailable = read_input();

  if(orderAvailable)
  {
    if( order == MAKE_FRIED_FRIES && oil_free)
        make_fried_fries();
        
    else if( (order == MAKE_RICE || order == MAKE_NOODLES) && water_free)
        make_riceORnoodles(order);
        
    else if( order == MAKE_SALAD_SOUP && water_free)
        make_salad_soup();
        
    else if( order == MAKE_SALAD && water_free) 
        make_salad();
        
    else if( order == MAKE_TEA && drink_free)
        make_tea();
  }

  checkAndServe();
}
