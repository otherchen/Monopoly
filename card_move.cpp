#include "card_move.h"

CardMove::CardMove() : Card(){
	cardText = "Card Name";
	locationNum = -1;
}

void CardMove::setAmount(int num){
	locationNum = num;
}

void CardMove::setCardText(string text1){
	cardText = text1;
}

void CardMove::cardAction(Bank* bank1, Player* player1){
	player1->setLocation(locationNum);
}

string CardMove::getCardText(int num){
	return cardText;
}
