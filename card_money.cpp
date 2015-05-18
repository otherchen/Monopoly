#include "card_money.h"

CardMoney::CardMoney() : Card(){
	cardText = "Card Name";
	moneyAmount = 0;
}

void CardMoney::setAmount(int num){
	moneyAmount = num;
}

void CardMoney::setCardText(string text1){
	cardText = text1;
}

void CardMoney::cardAction(Bank* bank1, Player* player1){
	bank1->take_money(moneyAmount);
	player1->give_money(moneyAmount);
}

string CardMoney::getCardText(int num){
	return cardText;
}
