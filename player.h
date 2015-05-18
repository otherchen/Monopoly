#ifndef PLAYER_H
#define PLAYER_H

//#include "money_action.h"
#include <string>

using namespace std;

struct Coordinates{
	int x;
	int y;
};

class Player {

	private:
	    string playerName;
	    char gamePiece;
	    int moneyAmount;
	    int location;
	    bool indexOfProperties[40];	  
	    bool alive;  
	    string gamePieceName;
	    Coordinates pixelLocation;
	    

	public:
	    //constructors
	    Player();
	    Player(int money);

	    //functions to set values
	    void setPlayerName(string inputName);
	    void setGamePiece(char inputPiece);
	    void setOwnedProperty(int inputIndex, bool isOwned); 
	    void setLocation(int spaceNum); 
	    void setGamePieceName(string inputPieceName);
	    void setPixelLocation(Coordinates tempLocation); 
	    void setMoneyAmount(int inputNum); 
	
	    //functions to get values
	    string getPlayerName();
	    char getGamePiece();
	    int getMoneyAmount();
	    bool getOwnedProperty(int inputIndex);
	    int getLocation();
	    bool isAlive();
	    string getGamePieceName();
	    Coordinates getPixelLocation();

	    //other functions
	    void give_money(int amount);
	    void take_money(int amount);
	    void move_player(int amount);
	    void reset();	    

};
#endif
