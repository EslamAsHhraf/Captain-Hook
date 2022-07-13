

#include <Stepper.h>

/*
-ve for down
+ve for up
+ve anticlockwise
-ve clockwise
*/
#define WATER 11 * 15      // flame 1
#define OIL 15 * 15        // flame 2
#define NON_KNIFE 1 * 15   // source1
#define KNIFE 19 * 15 + 15 // source 2
#define SERVEWATER 7 * 15  // deliver 1
#define A2LB 9 * 15

int length_of_move = 5;
int stepsPerRevolution = 200;
int PAN_LENGTH = length_of_move * stepsPerRevolution - 30;
int GROUND_LENGTH = length_of_move * stepsPerRevolution + 60;
int A2LB_LENGTH = length_of_move * stepsPerRevolution - 205;
int NON_KNIFE_HEIGHT = length_of_move * stepsPerRevolution - 40; // source1 height Doneeee
int KNIFE_HEIGHT = 200;                                          // source 2 heigth
int deleiverHeight = length_of_move * stepsPerRevolution - 140;  // Done

int i;
int Current_Location = 0;

Stepper ARM(stepsPerRevolution, 6, 7, 8, 9);
Stepper Base(stepsPerRevolution, 5, 4, 3, 2);

// read the from the bm
uint8_t x;
uint8_t read_input()
{
    if (Serial.available() > 0)
    {
        x = Serial.read() - 48;
        return 1;
    }
    else
        return 0;
}

void setup()
{
    // set the speed at 60 rpm:
    ARM.setSpeed(5 0);
    Base.setSpeed(10);
    // initialize the serial port:
    Serial.begin(9600);

    emsk(GROUND_LENGTH);
}

int read;
void loop()
{

    //  uint8_t y = read_input();
    //  if (y) {
    //    Serial.println(x);
    //    Arm(x);
    //  }
}

void testEmsk()
{

    emskNonKnife();

    fixHeigth();

    sybSource2();

    move_arm(OIL);

    //  move_arm(OIL);

    //  syb(PAN_LENGTH);

    //  emskKnife();

    //  fixHeigth();

    //  move_arm(OIL);
}

void testUpandDown()
{

    ARM.step(-700);
    delay(2000);
    ARM.step(700);
}

void testLocations()
{

    // go to source 1
    move_arm(NON_KNIFE);

    testUpandDown();

    // go to SERVEWATER
    move_arm(SERVEWATER);

    testUpandDown();

    // go to A2LB
    move_arm(A2LB);

    testUpandDown();

    // go to flame 1
    move_arm(WATER);

    testUpandDown();

    // go to OIL
    move_arm(OIL);

    testUpandDown();

    // go to KNIFE
    move_arm(KNIFE);

    testUpandDown();
}

void move_arm(int location)
{
    location -= Current_Location;
    // go to the location via stepper Base
    Base.step(location);

    Current_Location += location;
    delay(1000);
}

// function to get the pan
void emsk(int L)
{
    Base.step(20);
    delay(1000);
    ARM.step(-L);
    Base.step(-20);
    delay(1000);
    ARM.step(L);
    delay(1000);
}

// function to left the pan

void syb(int L)
{
    ARM.step(-L);
    delay(1000);
    Base.step(20);
    delay(1000);
    ARM.step(L);
    delay(1000);
    Base.step(-20);
}

void fixHeigth()
{
    if (Current_Location == NON_KNIFE)
    {
        Base.step(40);
        Current_Location += 40;
        delay(500);
        ARM.step(GROUND_LENGTH - NON_KNIFE_HEIGHT);
        delay(500);
    }
    else if (Current_Location == KNIFE)
    {
        Base.step(-40);
        Current_Location -= 40;
        delay(500);
        ARM.step(GROUND_LENGTH - KNIFE_HEIGHT);
        delay(500);
    }
}

void emskNonKnife()
{
    move_arm(NON_KNIFE);
    Base.step(20);
    delay(1000);
    ARM.step(-GROUND_LENGTH);
    Base.step(-20);
    delay(2000);
    ARM.step(NON_KNIFE_HEIGHT);
    delay(1000);
}

void emskKnife()
{
    move_arm(OIL);
    delay(1000);
    Base.step(40);
    Current_Location += 40;
    delay(1000);
    ARM.step(-GROUND_LENGTH);
    move_arm(KNIFE);
    delay(4000);

    ARM.step(KNIFE_HEIGHT);
}

void a2lb(int L)
{
    // go away to catch
    Base.step(20);
    delay(100);

    // down to esmsk
    ARM.step(-L);
    delay(1000);
    // go left
    Base.step(-20);
    delay(1000);
    // up 45 lenght

    ARM.step(120); // up
    delay(2000);

    Base.step(-150); // right
    delay(200);

    // finished then back to origin position
    Base.step(150); // left
    delay(200);

    ARM.step(-120); // down
    delay(2000);

    // go away to left
    Base.step(20);
    delay(100);

    // up
    ARM.step(L);
    delay(1000);

    // go away to left
    Base.step(-20);
    delay(100);
}

// some nonsense
void nodd()
{
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

void sybSource1()
{
    move_arm(SERVEWATER);
    delay(1000);
    Base.step(-60);
    Current_Location -= 60;
    delay(1000);
    ARM.step(-(GROUND_LENGTH - NON_KNIFE_HEIGHT));
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

void sybSource2()
{
    move_arm(OIL);
    delay(1000);
    Base.step(40);
    Current_Location += 40;
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
}