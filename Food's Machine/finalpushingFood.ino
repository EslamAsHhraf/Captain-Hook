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
void pistonMotor(bool dir, float t = 1)
{
    digitalWrite(pistonHolder1, dir);
    digitalWrite(pistonHolder2, !dir);
    delay(1000 * t);
    digitalWrite(pistonHolder1, 0);
    digitalWrite(pistonHolder2, 0);
}

void stepper_motion(float s, float e)
{
    myStepper.step((e - s) * 150.0 / 360);
    pos = e;
}

void choose_ingredient(float order, int quantity)
{
    delay(2000);

    Serial.print("current position : ");
    Serial.println(pos);
    Serial.print("current order : ");
    Serial.println(order);
    stepper_motion(pos, order * stepSize);
    delay(1000);
    pistonMotor(1, 0.5);
    delay(1000);
    if (order == 5.5 || order == 7)
        stepper_motion(pos, pos - 23);
    else
        stepper_motion(pos, pos + 28);
    Serial.print("order after shifting : ");
    Serial.println(order);
    delay(1000);
    for (int i = 0; i < quantity; i++)
    {
        Serial.println("piston moves forward ");
        pistonMotor(1);
        delay(1000);
        Serial.println("piston moves backward ");
        pistonMotor(0);
        delay(1000);
    }
    pistonMotor(1, 0.5);
    delay(1000);
    if (order == 5.5 || order == 7)
        stepper_motion(pos, pos + 23);
    else
        stepper_motion(pos, pos - 28);
    delay(1000);
    pistonMotor(0, 0.7);
    delay(1000);
    Serial.println("end of operation ");
    stepper_motion(pos, 0);
}