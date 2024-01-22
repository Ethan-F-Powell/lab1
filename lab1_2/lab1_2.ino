/******************************************************************************
FILENAME:     lab_1_1.ino 
COURSE:       MREN 178
LAB:          1
STUDENT(S):   [STUDENT NAMES AND IDS HERE] 
DATE:         

ATTRIBUTIONS: [LIST ANY EXTERNAL CONTIBUTORS/CONTRIBUTIONS HERE] 

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
int nums[5];
int i;


void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.setCursor(0,0);
  lcd.print("number:");
  y  = 100;
  i = 0;
}

void loop() {
  int x;
  x = analogRead (0);
  lcd.setCursor(0,1);
  lcd.print(y);
  lcd.print("      ");


  if (x < 900) {
  Serial.print("analog: ");
  Serial.println(x);

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
    if(i<5){
      nums[i]=y;
      i++;
    }
    else {
      Serial.println("the array is full");
      lcd.setCursor(0, 0);
      lcd.print("array is full");

      delay(1000);

      lcd.setCursor(0, 0);
      lcd.print("number:       ");
    }
    Serial.print("The values in the array are:");
    for (int k=0;k<i;k++){
      Serial.print(nums[k]);
      Serial.print(",");
    
    }
     Serial.println();
    


  }
  Serial.print("value: ");
  Serial.println(y);
  delay(300);
  }

 
}
