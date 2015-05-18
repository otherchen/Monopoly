#include "move_action.h"

MoveAction::MoveAction(string nameChoice, int amountInput) : Action(nameChoice){
	amount = amountInput;
}

MoveAction::MoveAction(string nameChoice) : Action(nameChoice){
	amount = 0;
}

MoveAction::MoveAction() : Action (){
	amount = 0;
}

void MoveAction::set_amount(int amountInput){
	amount = amountInput;
}

void MoveAction::move_amount(Player *player, int amountInput){
	player->move_player(amountInput);
}

int MoveAction::get_amount(){
	return amount;
}

void MoveAction::executeAction(Player* player1, Player* player2, int amount){
	//does nothing
}

