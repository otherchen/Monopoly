#ifndef CARD_MONEY_H
#define CARD_MONEY_H

#include "card.h"

class CardMoney : public Card {

	private:
	string cardText;
	int moneyAmount;

	public:
	CardMoney();
	void setAmount(int num);
	void setCardText(string text1);
	void cardAction(Bank* bank1, Player* player1);
	string getCardText(int num);

};
#endif
