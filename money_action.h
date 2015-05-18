#ifndef MONEY_ACTION_H
#define MONEY_ACTION_H

#include "player.h"
#include "bank.h"
#include "action.h"

class MoneyAction : public Action {

	private:
	int money;

	public:
	//constructors
	MoneyAction(string nameChoice, int moneyInput);
	MoneyAction(string nameChoice);
	MoneyAction();

	//other functions
	void pay_money(Player *player1, Player *player2, int amount);
	int get_money();
	void setPlayers(Player *player1, Player *player2);
	void executeAction(Player* player1, Player* player2, int amount);
	void giveBank(Player* player1, Bank* bank1, int amount);
	void takeBank(Player* player1, Bank* bank1, int amount);
	
};
#endif
