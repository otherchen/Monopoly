#include "player.h"

Player::Player(){
	moneyAmount = 2500;
	location = 0;
	for(int i = 0; i < 40; i++){
		indexOfProperties[i] = false;
	}
	alive = true;

	playerName = "John";
	gamePieceName = "soccer.png";
	pixelLocation.x = 594;
	pixelLocation.y = 590;
}

Player::Player(int money){
	moneyAmount = money;
	location = 0;
	for(int i = 0; i < 40; i++){
		indexOfProperties[i] = false;
	}
	alive = true;

	playerName = "John";
}

void Player::setPixelLocation(Coordinates tempLocation){
	pixelLocation = tempLocation;
} 

Coordinates Player::getPixelLocation(){
	return pixelLocation;
}

void Player::setPlayerName(string inputName){
	playerName = inputName;
}

void Player::setGamePiece(char inputPiece){
	gamePiece = inputPiece;
}

void Player::setGamePieceName(string inputPieceName){
	gamePieceName = inputPieceName;
}

void Player::setLocation(int spaceNum){
	location = spaceNum;
	
}

string Player::getPlayerName(){
	return playerName;
}

char Player::getGamePiece(){
	return gamePiece;
}

void Player::give_money(int amount){
	moneyAmount = moneyAmount + amount;
}

int Player::getMoneyAmount(){
	return moneyAmount;
}

void Player::take_money(int amount){
	moneyAmount = moneyAmount - amount;
}

void Player::move_player(int amount){
	location = (location + amount) % 40;
}

int Player::getLocation(){
	return location;
}

string Player::getGamePieceName(){
	return gamePieceName;
}

void Player::setOwnedProperty(int inputIndex, bool isOwned){
	indexOfProperties[inputIndex] = isOwned;
}

bool Player::getOwnedProperty(int inputIndex){
	return indexOfProperties[inputIndex];
}

bool Player::isAlive(){
	return alive;
}

void Player::reset(){
	moneyAmount = 0;
	location = 0;
	gamePiece = ' ';
	alive = false;
}

void Player::setMoneyAmount(int inputNum){
	moneyAmount = inputNum;
}
