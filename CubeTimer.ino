#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <GyverButton.h>

#include "src/ScrambleTools.h"

/* Scramble settings */
  #define scrSize 20 //Define scramble size fo 3x3
  Scrambles newScr;
/* End Settings */


/* Timer variables */
   int timerMode = 0;

   unsigned long msTime=0; // время интервала, милисекунды  
   int secTime = 0;
   byte  minTime=0;  // время интервала, минуты
   byte  decMinTime=0;  // время интервала, десятки минуты
   unsigned long prevTime;  // предыдущее значение времени 
   unsigned long curentTime;  // текущее значение времени
/* End */

/* Misc definitions */
  #define firstButt 5
  #define secondButt 4
  #define thirdButt 14

  GButton butt1(firstButt);
  GButton butt2(secondButt);
  GButton resetButt(thirdButt);

  #define NODEMCU
/* End */

/* Disp Settings */
  #define SDA 0
  #define SCL 2

  LiquidCrystal_I2C lcd(0x27, 16, 2);
/* End */
void setup() {
  Serial.begin(115200);
  randomSeed(analogRead(0));

#ifdef NODEMCU
  attachInterrupt(digitalPinToInterrupt(firstButt), isr, CHANGE);
  attachInterrupt(digitalPinToInterrupt(secondButt), isr, CHANGE);
  attachInterrupt(digitalPinToInterrupt(thirdButt), isr, CHANGE);
#else
  attachInterrupt(firstButt, isr, CHANGE);
  attachInterrupt(secondButt, isr, CHANGE);
  attachInterrupt(thirdButt, isr, CHANGE);
#endif
  butt1.setDebounce(25);
  butt2.setDebounce(25);
  resetButt.setDebounce(25);

  Wire.begin(SDA,SCL);
  lcd.begin();
  lcd.backlight();

  lcd.setCursor(0,0);
}

void loop() { 
  if ( butt1.isPress() == true && butt2.isPress() == true ) {
    timerMode = !timerMode;
  }

  if(resetButt.isPress() == true && timerMode != 1){
    msTime = 0;
    secTime = 0;
    minTime = 0;
    decMinTime = 0;
    lcd.clear();
    }

  if ( timerMode == 0 ) {
    prevTime= millis();
  }
  else {  
    curentTime = millis();
    msTime += curentTime - prevTime; 
    if ( msTime > 999 ) {  
      msTime -= 1000;
      secTime ++; 
      if ( secTime > 59 ) {
        secTime -= 60;
        minTime ++;
      }      
    }                
    prevTime= curentTime;
  }

   lcd.setCursor(0,1);
   if(minTime < 1){
      lcd.print(secTime);lcd.print(".");lcd.print(msTime);
      Serial.print(secTime);Serial.print(".");Serial.println(msTime);
   } else {
      lcd.print(minTime);lcd.print(":");lcd.print(secTime);lcd.print(".");lcd.print(msTime);
      Serial.print(minTime);Serial.print(":");Serial.print(secTime);Serial.print(".");Serial.println(msTime);
   }
   
}

void isr(){
  butt1.tick();
  butt2.tick();
  resetButt.tick();
}
