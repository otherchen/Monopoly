#include "money_action.h"

MoneyAction::MoneyAction(string nameChoice, int moneyInput) : Action(nameChoice){
	money = moneyInput;
}

MoneyAction::MoneyAction(string nameChoice) : Action(nameChoice){
	money = 0;
}

MoneyAction::MoneyAction() : Action(){
	money = 0;
}

void MoneyAction::pay_money(Player *player1, Player *player2, int amount){
	player1->take_money(amount);	
	player2->give_money(amount);
}

int MoneyAction::get_money(){
	return money;
}

void MoneyAction::executeAction(Player* player1, Player* player2, int amount){
	player1->take_money(amount);
	player2->give_money(amount);
}

void MoneyAction::giveBank(Player* player1, Bank* bank1, int amount){
	player1->take_money(amount);
	bank1->give_money(amount);
}

void MoneyAction::takeBank(Player* player1, Bank* bank1, int amount){
	bank1->take_money(amount);
	player1->give_money(amount);
}


