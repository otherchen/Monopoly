#ifndef ACTION_H
#define ACTION_H

#include <string>
#include "player.h"
using namespace std;

class Action {

	private:
	    string name;

	public:
	    //constructors
	    Action();
	    Action(string inputName);

	    //This class is abstract and cannot be compiled
	    virtual void executeAction(Player* player1, Player* player2, int amount) = 0;
};
#endif
