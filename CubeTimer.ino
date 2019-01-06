#include <GyverButton.h>

#include "src/ScrambleTools.h"

/* Scramble settings */
  #define scrSize 20 //Define scramble size fo 3x3
  Scrambles newScr;
/* End Settings */


/* Timer variables */
   int timerMode = 0;

/* End */

/* Misc definitions */
  #define firstButt 5
  #define secondButt 4

  GButton butt1(firstButt);
  GButton butt2(secondButt);
  
/* End */

/* Disp Settings */
  #define SDA 4
  #define SCL 0
/* End */
void setup() {
  Serial.begin(115200);

  attachInterrupt(digitalPinToInterrupt(firstButt), isr, CHANGE);
  attachInterrupt(digitalPinToInterrupt(secondButt), isr, CHANGE);

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
    
  Serial.println(timerMode);
}

void isr(){
  butt1.tick();
  butt2.tick();
}
