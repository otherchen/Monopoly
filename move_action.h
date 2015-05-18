#ifndef MOVE_ACTION_H
#define MOVE_ACTION_H

#include "player.h"
#include "action.h"

class MoveAction : public Action {

	private:
	int amount;    

	public:
	//constructors
	MoveAction(string nameChoice, int amountInput);
	MoveAction(string nameChoice);
	MoveAction();

	//other functions
	void set_amount(int amountInput);
	void move_amount(Player *player, int amountInput);
	int get_amount();
	void executeAction(Player* player1, Player* player2, int amount);
};
#endif
