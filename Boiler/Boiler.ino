#define lightSensor A0
#define pump 7
#define KettelMotorForward 6
#define KettelMotorBackward 5
#define makeTea 4

#define onTH 90
#define offTH 5
int sensorCurrent = 0, sensorPrevious = 0;
void setup() {
  pinMode(lightSensor, INPUT);
  pinMode(pump, OUTPUT);
  pinMode(KettelMotorForward, OUTPUT);
  pinMode(KettelMotorBackward, OUTPUT);
  pinMode(makeTea, INPUT);
  Serial.begin(9600);
  digitalWrite(KettelMotorForward,HIGH);
  digitalWrite(KettelMotorBackward,HIGH);
  digitalWrite(pump,HIGH);
}

void loop() {
  sensorCurrent = analogRead(lightSensor);
    if(digitalRead(makeTea) == HIGH && sensorCurrent < offTH){
      Serial.println("Kettel Started");
      digitalWrite(KettelMotorForward, LOW);
      delay(1000);
      digitalWrite(KettelMotorForward, HIGH);
      delay(1000);
      digitalWrite(KettelMotorBackward, LOW);
      delay(1000);
      digitalWrite(KettelMotorBackward, HIGH);
  }
  if(sensorCurrent < offTH && sensorPrevious > onTH){
    Serial.println("Pump Started");
    digitalWrite(pump, LOW);
    delay(8000);
    digitalWrite(pump, HIGH);
  }
  
  sensorPrevious = sensorCurrent;
}
