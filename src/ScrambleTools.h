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

	public: String getScramble(int scrSize){
		int previousIndex; //previous move
		String scramble = "";

		int i = 0;
		while(i < scrSize){
      		randMove = random(5);
      		delay(50); //need for prevent the same numbers
      		randPow = random(2);

      		if(previousMove == randMove){
      			randMove = random(5);
      		}
      		scramble += moves[randMove] + ALG_POWES[randPow] + ' ';
      		previousMove = randMove;
      		i++;
		}

		return scramble;
	}

};
