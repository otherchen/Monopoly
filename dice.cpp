#include "dice.h"
#include <cstdlib>
#include <ctime>

Dice::Dice(){
	sides = 6;
}

int Dice::rollDice(){

	int roll = 0;
	roll = rand() % sides + 1;
	
	return roll;
}
