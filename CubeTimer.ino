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

  GButton butt1(firstButt);
  GButton butt2(secondButt);

  #define NODEMCU
/* End */

/* Disp Settings */
  #define SDA 4
  #define SCL 0
/* End */
void setup() {
  Serial.begin(115200);

#ifdef NODEMCU
  attachInterrupt(digitalPinToInterrupt(firstButt), isr, CHANGE);
  attachInterrupt(digitalPinToInterrupt(secondButt), isr, CHANGE);
#else
  attachInterrupt(firstButt, isr, CHANGE);
  attachInterrupt(secondButt, isr, CHANGE);
#endif
  

  butt1.setDebounce(25);
  butt2.setDebounce(25);
  
}

void loop() {   
  if ( butt1.isPress() == true && butt2.isPress() == true ) {
    if ( timerMode == 0) {
      timerMode = 1;
    } else {     
      timerMode = 0;     
    }
  }
  
  /*if(butt1.isDouble() == true){
    msTime = 0;
    secTime = 0;
    minTime = 0;
    decMinTime = 0;
  }*/

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


   Serial.print(secTime);Serial.print(".");Serial.println(msTime);
}

void isr(){
  butt1.tick();
  butt2.tick();
}
