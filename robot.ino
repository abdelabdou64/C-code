#include <Servo.h>
#include <LiquidCrystal.h>

Servo Xservo ;  // motor 1
Servo Yservo ;  // motor 2

// joystick variabls
int Xpin = A0 ; // joystick X direction
int Ypin = A1 ;  // joystick Y direction
int Spin = 2; // switch pin

 //Reading  variables
int Xval ; // reading the X value
int Yval ; // reading the Y value from the joystick
int Sval ; // 1 or 0
int dt ;
// survomotor variabls
int XSpin =9 ; // survo 1 :  direction X
int YSpin = 10 ; // survo 2 : direction Y
int buzzPin = 7; // sound buzz
int WVx ; // write  value for survo X
int WVy ; // write value for survo Y
//LCD variables
 int rs = 7 ;
 int en = 8 ;
 int d4 = 5 ;
 int d5 = 4 ;
 int d6 = 3 ;
 int d7 = 2 ;
// creating the object lcd
 LiquidCrystal lcd(rs,en,d4,d5,d6,d7);

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(Xpin,INPUT) ;
pinMode(Ypin,INPUT);
pinMode(Spin,INPUT);
digitalWrite(Spin,HIGH); // the way for Sxitch work

pinMode(XSpin,OUTPUT);
pinMode(YSpin,OUTPUT);
pinMode(buzzPin,OUTPUT);

Xservo.attach(XSpin);
Yservo.attach(YSpin);

lcd.begin(16,2);
}

void loop() {
  // put your main code here, to run repeatedly:
  Xval = analogRead(Xpin);
  WVx = (180./1023.)*Xval; // X angle that the survo wil go to

  lcd.setCursor(0,0);
  lcd.print("X = ");  lcd.print(WVx); // to show the X value in LCD


  Yval = analogRead(Ypin);
  WVy =(180./1023.)*Yval; // Y angle that the survo wil go to

  lcd.setCursor(0,1);
  lcd.print("Y = ");  lcd.print(WVy); // to show the Y value in LCD

  Sval = digitalRead(Spin);

  Xservo.write(WVx);
  Yservo.write(WVy);

  if(Sval == 0 )
    {
      digitalWrite(buzzPin,HIGH);

      lcd.setCursor(0,2);
      lcd.print("button clicked"); // to show if the joystick button is clicked
      delay(1000);
    }else {
      digitalWrite(buzzPin,LOW);
    }

  delay(dt);
  // to show the values in the serial monitor
  Serial.print("X value = ");
  Serial.print(Xval);
  Serial.print("Y value =");
  Serial.print(Yval);
  Serial.print("Switch state is ");
  Serial.print(Sval);
}
