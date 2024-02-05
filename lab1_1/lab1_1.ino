/******************************************************************************
FILENAME:     lab1_1.ino 
COURSE:       MREN 178
LAB:          1
STUDENTS:    [Ahnaaf Khan 20397194, Ethan Powell 20415905] 
DATE:         Feb 2024

ATTRIBUTIONS: None.  
******************************************************************************/
// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to      
const int pin_RS = 8; 
const int pin_EN = 9; 
const int pin_d4 = 4; 
const int pin_d5 = 5; 
const int pin_d6 = 6; 
const int pin_d7 = 7; 
const int pin_BL = 10; 
LiquidCrystal lcd(pin_RS,  pin_EN,  pin_d4,  pin_d5,  pin_d6,  pin_d7);
int y;

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.setCursor(0,0);
  lcd.print("number:");
  y  = 100;
}

void loop() {
  int x;
  x = analogRead (0);
  Serial.println(x);
  lcd.setCursor(0,1);
  lcd.print(y);

  if (x < 900) {
     if (x < 60) { //right click
      ++y;
  }
  else if (x < 200) { //up click
    y += 10;
  
  }
  else if (x < 400){ //down button
    y -= 10;
  }
  else if (x < 600){ //left button
    --y;
  }
  else if (x < 800){ //select
    lcd.print ("Select");
  }
  delay(500);
  }

 
}
