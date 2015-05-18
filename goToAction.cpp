#include "goToAction.h"

GoToAction::GoToAction() : Action(){
	spaceLocation = 0;
}

void GoToAction::executeAction(Player* player1, Player* player2, int amount){
	player1->setLocation(amount);
}

