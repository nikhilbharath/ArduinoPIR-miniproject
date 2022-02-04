
// This miniproject is to demostrate the working of PIR sensor with
// Arduino board using an electrical appliances

#include <avr/io.h>


long unsigned int halt = 500;

boolean flag = true;
boolean flag1;

const int signal1 = A0;
float signal, op, analog;
int a = 12;
int b = 13;
int c = 3;

void setup(){
  Serial.begin(9600);
  pinMode(a, INPUT);
  pinMode(b, OUTPUT);
  pinMode(c,OUTPUT);
  digitalWrite(b, HIGH);
  pinMode(signal1, INPUT);

  while (digitalRead(a) == HIGH) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("SENSOR ACTIVE");
}
void read_write(){
  analog = analogRead(signal1);
  signal = analog / 2.0479;
  op=analog*4.883;
  if (signal >= 25)
  {
    analogWrite(c,50);

  }
  if (signal >= 30)
   {
    analogWrite(c,100);

  }
  if (signal >= 35)
   {
    analogWrite(c,150);

  }
  if (signal >= 40)
   {
    analogWrite(c,200);

  }
  if (signal >= 45)
   {
    analogWrite(c,255);

  }
 }
void iterate(){
  if(digitalRead(a) == HIGH){
    read_write();
    if(flag){

      flag = false;
      Serial.print(millis()/1000);
      delay(50);
    }
    flag1 = true;
  }

  if(digitalRead(a) == LOW){
    digitalWrite(c,LOW);
    if(flag1){
      lowIn = millis();
      flag1 = false;
    }


    if(!flag && millis() - lowIn > halt){

      flag = true;
      Serial.print((millis() - halt)/1000);
      delay(50);
    }
  }
  delay(1000);
  Serial.print(signal);
  Serial.println();
  delay(1000);
  Serial.print(analog);
  Serial.println();
  delay(1000);
}
