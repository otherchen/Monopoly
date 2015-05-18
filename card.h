#ifndef CARD_H
#define CARD_H

#include <string>
#include "bank.h"
#include "player.h"

class Card {

	private:
	string name;

	public:
	Card();
	virtual void setAmount(int num) = 0;
	virtual void setCardText(string text1) = 0;
	virtual void cardAction(Bank* bank1, Player* player1) = 0;
	virtual string getCardText(int num) = 0;

};
#endif
