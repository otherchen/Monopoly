#ifndef CARD_MOVE_H
#define CARD_MOVE_H

#include "card.h"

class CardMove : public Card {

	private:
	string cardText;
	int locationNum;

	public:
	CardMove();
	void setAmount(int num);
	void setCardText(string text1);
	void cardAction(Bank* bank1, Player* player1);
	string getCardText(int num);

};
#endif
