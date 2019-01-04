#include "src/ScrambleTools.h"

/* Scramble settings */
  #define scrSize 20 //Define scramble size fo 3x3
  Scrambles newScr;
/* End Settings */


/* Timer variables */
  boolean statusFlag = false;

/* End */



/* Misc definitions */
  #define firstButt 16
  #define secondButt 5
  boolean buttonState = false;
/* End */

/* Disp Settings */
  #define SDA 4
  #define SCL 0
/* End */
void setup() {
  Serial.begin(115200);
    //randomSeed(analogRead(0));
  pinMode(firstButt,INPUT_PULLUP);
  pinMode(secondButt,INPUT_PULLUP);
}

void loop() {
  delay(5000);


}
