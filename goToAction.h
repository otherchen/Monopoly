#ifndef GOTOACTION_H
#define GOTOACTION_H

#include "action.h"
#include "player.h"

class GoToAction : public Action {

	private:
	int spaceLocation;

	public:
	GoToAction();
	void executeAction(Player* player1, Player* player2, int amount);

};
#endif
