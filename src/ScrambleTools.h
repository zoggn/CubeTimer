/* 
	* Need for make new scrambles
*/
#include "Arduino.h"

class Scrambles {
  
	String moves[18] =  {"U","L","F","R","B","D", 
					  "U'", "L'", "F'", "R'", "B'", "D'", 
					  "U2","L2","F2","R2","B2", "D2"};

	public: String getScramble(int scrSize){
		int i = 0;
		String scramble = "";

		while(i < scrSize){
      int randNumber = random(17);
			scramble += moves[randNumber] + ' ';
			i++; 
		}

		return scramble;
	}

};
