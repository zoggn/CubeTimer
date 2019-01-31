/*
	* Need for make new scrambles
*/
#include "Arduino.h"

class Scrambles {

  	int randMove = 0; //need to store random number -_-
  	int randPow = 0; //need to store random alg pow -_- x2
  	int previousMove,previousPow;

  	String moves[6] = {"R","L","U","D","F","B"};
  	String ALG_POWES[3] = {"","'","2"};

	public: String getScramble(int scrSize, boolean needSpace){
		String scramble = "";

		int i = 0;
		while(i < scrSize){
      		randPow = random(3);
      		delay(50); //need for prevent the same numbers
      		randMove = random(6);

      		if(isInvalid(previousMove,randMove)){
            	   continue;
      		}

          scramble += moves[randMove] + ALG_POWES[randPow];
          if(needSpace == true){ // need for small displays
            scramble += ' ';
          }

      		previousMove = randMove;
      		i++;
		}

		return scramble;
	}

private: boolean isInvalid(int prev, int current){
if(prev == current){
    return true;
  } else if(prev == 0 && current == prev + 1){
    return true;
  } else if(prev == 1 && current == prev - 1){
    return true;
  } else if(prev == 2 && current == prev + 1){
    return true;
  } else if(prev == 3 && current == prev - 1){
    return true;
  } else if(prev == 4 && current == prev + 1){
    return true;
  } else if(prev == 5 && current == prev - 1){
    return true;
  } else {
    return false;
  }
}

};
