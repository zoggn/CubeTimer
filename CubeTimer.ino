#include "src/ScrambleTools.h"

/* Settings */
#define scrSize 20 //Define scramble size fo 3x3
/* End Settings */

Scrambles newScr;

void setup() {
  Serial.begin(115200);
    randomSeed(analogRead(0));

}

void loop() {
  delay(10000);
  Serial.println(newScr.getScramble(scrSize));


}
