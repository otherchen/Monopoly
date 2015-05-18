#include "Game_Board.h"
#include <cmath>
#include <iostream>

Game_Board::Game_Board(){
	
	//Use functions in Space class to initialize each space
	
	//Space 0
	spaces[0].setName("   GO!   ", "         ");
	spaces[0].setType("START");
	spaces[0].setPropertyCost(0);
	spaces[0].setFreeParking(0);
	spaces[0].setOccupied(true);
	spaces[0].setOwnership(-1);
	spaces[0].setMortgaged(false);
	spaces[0].setRent(0);
	spaces[0].setTax(0);
	spaces[0].setActionText("Pass Go! ", "Get $200 ");

	//Space 1
	spaces[1].setName("  Dorm   ", "  Room   ");
	spaces[1].setType("Property");
	spaces[1].setPropertyCost(60);
	spaces[1].setFreeParking(0);
	spaces[1].setOccupied(false);
	spaces[1].setOwnership(-1);
	spaces[1].setMortgaged(false);
	spaces[1].setRent(2);
	spaces[1].setTax(0);
	spaces[1].setActionText("         ", "   $60   ");

	//Space 2
	spaces[2].setName("Community", "  Chest  ");
	spaces[2].setType("Community Chest");
	spaces[2].setPropertyCost(0);
	spaces[2].setFreeParking(0);
	spaces[2].setOccupied(false);
	spaces[2].setOwnership(-1);
	spaces[2].setMortgaged(false);
	spaces[2].setRent(0);
	spaces[2].setTax(0);
	spaces[2].setActionText(" Draw a  " ,"  Card   ");

	//Space 3
	spaces[3].setName(" Leavey  ", " Library ");
	spaces[3].setType("Property");
	spaces[3].setPropertyCost(70);
	spaces[3].setFreeParking(0);
	spaces[3].setOccupied(false);
	spaces[3].setOwnership(-1);
	spaces[3].setMortgaged(false);
	spaces[3].setRent(4);
	spaces[3].setTax(0);
	spaces[3].setActionText("         ", "   $60   ");
	

	//Space 4
	spaces[4].setName(" College ", " Tuition ");
	spaces[4].setType("Tax");
	spaces[4].setPropertyCost(70);
	spaces[4].setFreeParking(0);
	spaces[4].setOccupied(false);
	spaces[4].setOwnership(-1);
	spaces[4].setMortgaged(false);
	spaces[4].setRent(4);
	spaces[4].setTax(200);
	spaces[4].setActionText("         ", "Pay $200 ");

	//Space 5
	spaces[5].setName(" Campus  ", " Cruiser ");
	spaces[5].setType("RailRoad");
	spaces[5].setPropertyCost(200);
	spaces[5].setFreeParking(0);
	spaces[5].setOccupied(false);
	spaces[5].setOwnership(-1);
	spaces[5].setMortgaged(false);
	spaces[5].setRent(25);
	spaces[5].setTax(0);
	spaces[5].setActionText("         ", "  $200   ");

	//Space 6
	spaces[6].setName(" Trojan  ", "  Hall   ");
	spaces[6].setType("Property");
	spaces[6].setPropertyCost(100);
	spaces[6].setFreeParking(0);
	spaces[6].setOccupied(false);
	spaces[6].setOwnership(-1);
	spaces[6].setMortgaged(false);
	spaces[6].setRent(6);
	spaces[6].setTax(0);
	spaces[6].setActionText("         ", "  $100   ");
	
	//Space 7
	spaces[7].setName(" Chance  ", "         ");
	spaces[7].setType("Chance");
	spaces[7].setPropertyCost(0);
	spaces[7].setFreeParking(0);
	spaces[7].setOccupied(false);
	spaces[7].setOwnership(-1);
	spaces[7].setMortgaged(false);
	spaces[7].setRent(0);
	spaces[7].setTax(0);
	spaces[7].setActionText(" Draw a  ", "  card   ");

	//Space 8
	spaces[8].setName("  Marks  ", "  Tower  ");
	spaces[8].setType("Property");
	spaces[8].setPropertyCost(100);
	spaces[8].setFreeParking(0);
	spaces[8].setOccupied(false);
	spaces[8].setOwnership(-1);
	spaces[8].setMortgaged(false);
	spaces[8].setRent(6);
	spaces[8].setTax(0);
	spaces[8].setActionText("         ", "  $100   ");

	//Space 9
	spaces[9].setName(" Pardee  ", " Tower   ");
	spaces[9].setType("Property");
	spaces[9].setPropertyCost(120);
	spaces[9].setFreeParking(0);
	spaces[9].setOccupied(false);
	spaces[9].setOwnership(-1);
	spaces[9].setMortgaged(false);
	spaces[9].setRent(8);
	spaces[9].setTax(0);
	spaces[9].setActionText("         ", "  $120   ");


	//Space 10
	spaces[10].setName(" SJACS!  ", "         ");
	spaces[10].setType("Jail");
	spaces[10].setPropertyCost(0);
	spaces[10].setFreeParking(0);
	spaces[10].setOccupied(false);
	spaces[10].setOwnership(-1);
	spaces[10].setMortgaged(false);
	spaces[10].setRent(0);
	spaces[10].setTax(0);
	spaces[10].setActionText("  Just   ", "Visiting ");

	//Space 11
	spaces[11].setName(" Silent  ", " Chapel  ");
	spaces[11].setType("Property");
	spaces[11].setPropertyCost(140);
	spaces[11].setFreeParking(0);
	spaces[11].setOccupied(false);
	spaces[11].setOwnership(-1);
	spaces[11].setMortgaged(false);
	spaces[11].setRent(10);
	spaces[11].setTax(0);
	spaces[11].setActionText("         ", "  $140   ");

	//Space 12
	spaces[12].setName("Bathroom ", "Janitors ");
	spaces[12].setType("Utility");
	spaces[12].setPropertyCost(150);
	spaces[12].setFreeParking(0);
	spaces[12].setOccupied(false);
	spaces[12].setOwnership(-1);
	spaces[12].setMortgaged(false);
	spaces[12].setRent(10);
	spaces[12].setTax(0);
	spaces[12].setActionText("         ", "  $150   ");


	//Space 13
	spaces[13].setName("McCarthy ", "  Quad   ");
	spaces[13].setType("Property");
	spaces[13].setPropertyCost(140);
	spaces[13].setFreeParking(0);
	spaces[13].setOccupied(false);
	spaces[13].setOwnership(-1);
	spaces[13].setMortgaged(false);
	spaces[13].setRent(10);
	spaces[13].setTax(0);
	spaces[13].setActionText("         ", "  $140   ");

	//Space 14
	spaces[14].setName(" Alumni  ", " House   ");
	spaces[14].setType("Property");
	spaces[14].setPropertyCost(160);
	spaces[14].setFreeParking(0);
	spaces[14].setOccupied(false);
	spaces[14].setOwnership(-1);
	spaces[14].setMortgaged(false);
	spaces[14].setRent(12);
	spaces[14].setTax(0);
	spaces[14].setActionText("         ", "  $160   ");

	//Space 15
	spaces[15].setName("LA Metro ", "         ");
	spaces[15].setType("RailRoad");
	spaces[15].setPropertyCost(200);
	spaces[15].setFreeParking(0);
	spaces[15].setOccupied(false);
	spaces[15].setOwnership(-1);
	spaces[15].setMortgaged(false);
	spaces[15].setRent(25);
	spaces[15].setTax(0);
	spaces[15].setActionText("         ", "  $200   ");

	//Space 16
	spaces[16].setName("  Fluor  ", "  Tower  ");
	spaces[16].setType("Property");
	spaces[16].setPropertyCost(180);
	spaces[16].setFreeParking(0);
	spaces[16].setOccupied(false);
	spaces[16].setOwnership(-1);
	spaces[16].setMortgaged(false);
	spaces[16].setRent(14);
	spaces[16].setTax(0);
	spaces[16].setActionText("         ", "  $180   ");

	//Space 17
	spaces[17].setName("Community", "  Chest  ");
	spaces[17].setType("Community Chest");
	spaces[17].setPropertyCost(0);
	spaces[17].setFreeParking(0);
	spaces[17].setOccupied(false);
	spaces[17].setOwnership(-1);
	spaces[17].setMortgaged(false);
	spaces[17].setRent(0);
	spaces[17].setTax(0);
	spaces[17].setActionText(" Draw a  ", "  Card   ");

	//Space 18
	spaces[18].setName("  Webb   ", "  Tower  ");
	spaces[18].setType("Property");
	spaces[18].setPropertyCost(180);
	spaces[18].setFreeParking(0);
	spaces[18].setOccupied(false);
	spaces[18].setOwnership(-1);
	spaces[18].setMortgaged(false);
	spaces[18].setRent(14);
	spaces[18].setTax(0);
	spaces[18].setActionText("         ", "  $180   ");

	//Space 19
	spaces[19].setName("  Lyon   ", " Center  ");
	spaces[19].setType("Property");
	spaces[19].setPropertyCost(200);
	spaces[19].setFreeParking(0);
	spaces[19].setOccupied(false);
	spaces[19].setOwnership(-1);
	spaces[19].setMortgaged(false);
	spaces[19].setRent(16);
	spaces[19].setTax(0);
	spaces[19].setActionText("         ", "  $200   ");

	//Space 20
	spaces[20].setName("Financial", "   Aid   ");
	spaces[20].setType("FreeParking");
	spaces[20].setPropertyCost(0);
	spaces[20].setFreeParking(0);
	spaces[20].setOccupied(false);
	spaces[20].setOwnership(-1);
	spaces[20].setMortgaged(false);
	spaces[20].setRent(0);
	spaces[20].setTax(0);
	spaces[20].setActionText("         ", "         ");

	//Space 21
	spaces[21].setName(" George  ", "Tirebiter");
	spaces[21].setType("Property");
	spaces[21].setPropertyCost(220);
	spaces[21].setFreeParking(0);
	spaces[21].setOccupied(false);
	spaces[21].setOwnership(-1);
	spaces[21].setMortgaged(false);
	spaces[21].setRent(18);
	spaces[21].setTax(0);
	spaces[21].setActionText("         ", "  $220   ");

	//Space 22
	spaces[22].setName(" Chance  ", "         ");
	spaces[22].setType("Chance");
	spaces[22].setPropertyCost(0);
	spaces[22].setFreeParking(0);
	spaces[22].setOccupied(false);
	spaces[22].setOwnership(-1);
	spaces[22].setMortgaged(false);
	spaces[22].setRent(0);
	spaces[22].setTax(0);
	spaces[22].setActionText(" Draw a  ", "  Card   ");

	//Space 23
	spaces[23].setName("Traveller", " Statue  ");
	spaces[23].setType("Property");
	spaces[23].setPropertyCost(220);
	spaces[23].setFreeParking(0);
	spaces[23].setOccupied(false);
	spaces[23].setOwnership(-1);
	spaces[23].setMortgaged(false);
	spaces[23].setRent(18);
	spaces[23].setTax(0);
	spaces[23].setActionText("         ", "  $220   ");

	//Space 24
	spaces[24].setName("Knight's ", " Bench   ");
	spaces[24].setType("Property");
	spaces[24].setPropertyCost(240);
	spaces[24].setFreeParking(0);
	spaces[24].setOccupied(false);
	spaces[24].setOwnership(-1);
	spaces[24].setMortgaged(false);
	spaces[24].setRent(20);
	spaces[24].setTax(0);
	spaces[24].setActionText("         ", "  $240   ");

	//Space 25
	spaces[25].setName("Lyft App ", "         ");
	spaces[25].setType("RailRoad");
	spaces[25].setPropertyCost(200);
	spaces[25].setFreeParking(0);
	spaces[25].setOccupied(false);
	spaces[25].setOwnership(-1);
	spaces[25].setMortgaged(false);
	spaces[25].setRent(25);
	spaces[25].setTax(0);
	spaces[25].setActionText("         ", "  $200   ");

	//Space 26
	spaces[26].setName("Cromwell ", "  Field  ");
	spaces[26].setType("Property");
	spaces[26].setPropertyCost(260);
	spaces[26].setFreeParking(0);
	spaces[26].setOccupied(false);
	spaces[26].setOwnership(-1);
	spaces[26].setMortgaged(false);
	spaces[26].setRent(22);
	spaces[26].setTax(0);
	spaces[26].setActionText("         ", "  $260   ");

	//Space 27
	spaces[27].setName(" V.K.C.  ", "Carillon ");
	spaces[27].setType("Property");
	spaces[27].setPropertyCost(260);
	spaces[27].setFreeParking(0);
	spaces[27].setOccupied(false);
	spaces[27].setOwnership(-1);
	spaces[27].setMortgaged(false);
	spaces[27].setRent(22);
	spaces[27].setTax(0);
	spaces[27].setActionText("         ", "  $260   ");

	//Space 28
	spaces[28].setName(" Laundry ", " Company ");
	spaces[28].setType("Utility");
	spaces[28].setPropertyCost(150);
	spaces[28].setFreeParking(0);
	spaces[28].setOccupied(false);
	spaces[28].setOwnership(-1);
	spaces[28].setMortgaged(false);
	spaces[28].setRent(10);
	spaces[28].setTax(0);
	spaces[28].setActionText("         ", "  $150   ");

	//Space 29
	spaces[29].setName(" Gallen  ", " Center  ");
	spaces[29].setType("Property");
	spaces[29].setPropertyCost(280);
	spaces[29].setFreeParking(0);
	spaces[29].setOccupied(false);
	spaces[29].setOwnership(-1);
	spaces[29].setMortgaged(false);
	spaces[29].setRent(22);
	spaces[29].setTax(0);
	spaces[29].setActionText("         ", "  $280   ");

	//Space 30
	spaces[30].setName("Caught by", " D.P.S.  ");
	spaces[30].setType("GoJail");
	spaces[30].setPropertyCost(0);
	spaces[30].setFreeParking(0);
	spaces[30].setOccupied(false);
	spaces[30].setOwnership(-1);
	spaces[30].setMortgaged(false);
	spaces[30].setRent(0);
	spaces[30].setTax(0);
	spaces[30].setActionText("         ", "         ");

	//Space 31
	spaces[31].setName("Heritage ", "  Hall   ");
	spaces[31].setType("Property");
	spaces[31].setPropertyCost(300);
	spaces[31].setFreeParking(0);
	spaces[31].setOccupied(false);
	spaces[31].setOwnership(-1);
	spaces[31].setMortgaged(false);
	spaces[31].setRent(26);
	spaces[31].setTax(0);
	spaces[31].setActionText("         ", "  $300   ");

	//Space 32
	spaces[32].setName("  McKay  ", " Center  ");
	spaces[32].setType("Property");
	spaces[32].setPropertyCost(300);
	spaces[32].setFreeParking(0);
	spaces[32].setOccupied(false);
	spaces[32].setOwnership(-1);
	spaces[32].setMortgaged(false);
	spaces[32].setRent(26);
	spaces[32].setTax(0);
	spaces[32].setActionText("         ", "  $300   ");

	//Space 33
	spaces[33].setName("Community", "  Chest  ");
	spaces[33].setType("Community Chest");
	spaces[33].setPropertyCost(0);
	spaces[33].setFreeParking(0);
	spaces[33].setOccupied(false);
	spaces[33].setOwnership(-1);
	spaces[33].setMortgaged(false);
	spaces[33].setRent(0);
	spaces[33].setTax(0);
	spaces[33].setActionText(" Draw a  ", "  Card   ");

	//Space 34
	spaces[34].setName(" Bovard  ", " Stage   ");
	spaces[34].setType("Property");
	spaces[34].setPropertyCost(320);
	spaces[34].setFreeParking(0);
	spaces[34].setOccupied(false);
	spaces[34].setOwnership(-1);
	spaces[34].setMortgaged(false);
	spaces[34].setRent(28);
	spaces[34].setTax(0);
	spaces[34].setActionText("         ", "  $320   ");

	//Space 35
	spaces[35].setName("   USC   ", " Shuttle ");
	spaces[35].setType("RailRoad");
	spaces[35].setPropertyCost(200);
	spaces[35].setFreeParking(0);
	spaces[35].setOccupied(false);
	spaces[35].setOwnership(-1);
	spaces[35].setMortgaged(false);
	spaces[35].setRent(25);
	spaces[35].setTax(0);
	spaces[35].setActionText("         ", "  $200   ");

	//Space 36
	spaces[36].setName(" Chance  ", "         ");
	spaces[36].setType("Chance");
	spaces[36].setPropertyCost(0);
	spaces[36].setFreeParking(0);
	spaces[36].setOccupied(false);
	spaces[36].setOwnership(-1);
	spaces[36].setMortgaged(false);
	spaces[36].setRent(0);
	spaces[36].setTax(0);
	spaces[36].setActionText(" Draw a  ", "  Card   ");

	//Space 37
	spaces[37].setName(" Trojan  ", " Shrine  ");
	spaces[37].setType("Property");
	spaces[37].setPropertyCost(350);
	spaces[37].setFreeParking(0);
	spaces[37].setOccupied(false);
	spaces[37].setOwnership(-1);
	spaces[37].setMortgaged(false);
	spaces[37].setRent(35);
	spaces[37].setTax(0);
	spaces[37].setActionText("         ", "  $350   ");

	//Space 38
	spaces[38].setName("Textbook ", "  Fees   "); 
	spaces[38].setType("Tax");
	spaces[38].setPropertyCost(0);
	spaces[38].setFreeParking(0);
	spaces[38].setOccupied(false);
	spaces[38].setOwnership(-1);
	spaces[38].setMortgaged(false);
	spaces[38].setRent(0);
	spaces[38].setTax(75);
	spaces[38].setActionText("         ", " Pay $75 ");

	//Space 39
	spaces[39].setName("Football ", "Coliseum ");
	spaces[39].setType("Property");
	spaces[39].setPropertyCost(400);
	spaces[39].setFreeParking(0);
	spaces[39].setOccupied(false);
	spaces[39].setOwnership(-1);
	spaces[39].setMortgaged(false);
	spaces[39].setRent(50);
	spaces[39].setTax(0);
	spaces[39].setActionText("         ", "  $400   ");       
	
	for(int i = 0; i < 40; i++){
	    spaces[i].setHouses(0);
	}
}

void Game_Board::move(int numPlayer, int amountInput){
	movement.move_amount(&(players[numPlayer]), amountInput);
}

void Game_Board::createPlayers(int numPlayers){
	players = new Player[numPlayers];
}

void Game_Board::setPlayerName(int playerNum, string inputName){
	players[playerNum].setPlayerName(inputName);
}

void Game_Board::setGamePiece(int playerNum, string inputPiece){
	players[playerNum].setGamePieceName(inputPiece);
}

string Game_Board::getPlayerName(int playerNum){
	return players[playerNum].getPlayerName();
}

string Game_Board::getGamePiece(int playerNum){
	return players[playerNum].getGamePieceName();
}

Player* Game_Board::getPlayer(int num){
	return &players[num];
}

int Game_Board::getPlayerLocation(int playerNum){
	return players[playerNum].getLocation();
}

int Game_Board::getPlayerMoney(int playerNum){
	return players[playerNum].getMoneyAmount();
}

string Game_Board::spaceType(int inputIndex){
	return spaces[inputIndex].getType();
}

int Game_Board::getSpaceOwnership(int spaceIndex){
	return spaces[spaceIndex].getOwnership();
}

int Game_Board::getSpacePropertyCost(int spaceIndex){
	return spaces[spaceIndex].getPropertyCost();
}

void Game_Board::setSpaceOwnership(int spaceIndex, int playerNum){
	spaces[spaceIndex].setOwnership(playerNum);
}

int Game_Board::getSpaceRent(int spaceIndex){
	return spaces[spaceIndex].getRent();
}

int Game_Board::getSpaceTax(int spaceIndex){
	return spaces[spaceIndex].getTax();
}

int Game_Board::getSpaceFreeParking(int spaceIndex){
	return spaces[spaceIndex].getFreeParking();
}

string Game_Board::getSpaceName(int spaceIndex, int index){
	return spaces[spaceIndex].getName(index);
}

void Game_Board::upgradeSpace(int spaceNum){
	spaces[spaceNum].upgrade();
}

bool Game_Board::isPlayerAlive(int playerNum){
	return players[playerNum].isAlive();
}

void Game_Board::playerLost(int playerNum){
	players[playerNum].reset();
}

//Display Game Board
void Game_Board::displayHorizontal(int firstSpace, int lastSpace, int numPlayers){

	int numSpaces = abs(lastSpace - firstSpace) + 1;

	//first line for all cards
	for(int i = 0; i < numSpaces; i++){
		cout << "----------";
	}
	
	cout << "-" << endl;

	//second line
	for(int i = 0; i < numSpaces; i++){

		Space current;

		if(firstSpace < lastSpace) {
			current = spaces[firstSpace + i];
		} else {
			current = spaces[firstSpace - i];
		}

		if(current.getType() == "Property"){ 
			cout << "|--"; 
			for(int x = 0; x < current.getHouses(); x++){
			    cout << "X";
			}
			for(int x = 0; x < 7-(current.getHouses()); x++){
			    cout << "-";
			} 
		} else {
			cout << "|" << current.getName(0);
		}
	}
	
	cout << "|" << endl;

	//third line
	for(int i = 0; i < numSpaces; i++){

		Space current;

		if(firstSpace < lastSpace) {
			current = spaces[firstSpace + i];
		} else {
			current = spaces[firstSpace - i];
		}

		if(current.getType() == "Property"){ 
			cout << "|" << current.getName(0);
		} else {
			cout << "|" << current.getName(1);
		}
	}
	
	cout << "|" << endl;

	//fourth line
	for(int i = 0; i < numSpaces; i++){

		Space current;

		if(firstSpace < lastSpace) {
			current = spaces[firstSpace + i];
		} else {
			current = spaces[firstSpace - i];
		}

		if(current.getType() == "Property"){ 
			cout << "|" << current.getName(1);
		} else {
			cout << "|" << "         ";
		}
	}
	
	cout << "|" << endl;

	//fifth line

	for(int i = 0; i < numSpaces; i++){

		int counter = 0;		

		if(firstSpace < lastSpace) {

		    cout << "|   ";
		    for(int j = 0; j < numPlayers; j++){
			if((firstSpace + i) == (players[j].getLocation())){
				cout << players[j].getGamePiece();
				counter++;
			}
		    }	
		    for(int x = 0; x < (6-counter); x++){
		        cout << " ";
		    }	

		} else {

		    cout << "|   ";
		    for(int j = 0; j < numPlayers; j++){
			if((firstSpace - i) == (players[j].getLocation())){
				cout << players[j].getGamePiece();
				counter++;
			}
		    }	
		    for(int x = 0; x < (6-counter); x++){
		        cout << " ";
		    }	

		}	
	}
	
	cout << "|" << endl;

	//sixth line
	for(int i = 0; i < numSpaces; i++){

		Space current;

		if(firstSpace < lastSpace) {
			current = spaces[firstSpace + i];
		} else {
			current = spaces[firstSpace - i];
		}

		if(current.getType() == "Property"){ 
			cout << "|" << current.getActionText(0);
		} else {
			cout << "|" << current.getActionText(0);
		}
	}
	
	cout << "|" << endl;

	//seventh line
	for(int i = 0; i < numSpaces; i++){

		Space current;

		if(firstSpace < lastSpace) {
			current = spaces[firstSpace + i];
		} else {
			current = spaces[firstSpace - i];
		}

		if(current.getType() == "Property"){ 
			cout << "|" << current.getActionText(1);
		} else {
			cout << "|" << current.getActionText(1);
		}
	}
	
	cout << "|" << endl;
	
	//eighth line
	for(int i = 0; i < numSpaces; i++){
		cout << "----------";
	}
	
	cout << "-" << endl;
}

void Game_Board::displayVertical(int firstSpace, int lastSpace, int numPlayers){

	Space current = spaces[firstSpace];
	Space current2 = spaces[lastSpace];

	//toplines
	if(firstSpace != 19){

		cout << "-----------";

		for(int i = 0; i < 8; i++){
			cout << "          ";
		}

		cout << "         ";
		cout << "-----------" << endl;

	}

	
	
	//first line
	if(current.getType() == "Property"){
		cout << "|--"; 
		for(int x = 0; x < current.getHouses(); x++){
			cout << "X";
		}
		for(int x = 0; x < 7-(current.getHouses()); x++){
			cout << "-";
		} 
	} else{
		cout << "|" << current.getName(0);
	}
	
	cout << "|         ";

	for(int i = 0; i < 8; i++) {
		cout << "          ";
	}

	if(current2.getType() == "Property"){
		cout << "|--"; 
		for(int x = 0; x < current2.getHouses(); x++){
			cout << "X";
		}
		for(int x = 0; x < 7-(current2.getHouses()); x++){
			cout << "-";
		} 
	} else{
		cout << "|" << current2.getName(0);
	}
	
	cout << "|" << endl;

	//second line

	if(current.getType() == "Property"){
		cout << "|" << current.getName(0);
	} else{
		cout << "|" << current.getName(1);
	}
	
	cout << "|         ";

	for(int i = 0; i < 8; i++) {
		cout << "          ";
	}

	if(current2.getType() == "Property"){
		cout << "|" << current2.getName(0);
	} else{
		cout << "|" << current2.getName(1);
	}

	cout << "|" << endl;
	
	//third line
	
	if(current.getType() == "Property"){
		cout << "|" << current.getName(1);
	} else{
		cout << "|" << "         ";
	}
	
	cout << "|         ";

	for(int i = 0; i < 8; i++) {
		cout << "          ";
	}

	if(current2.getType() == "Property"){
		cout << "|" << current2.getName(1);
	} else{
		cout << "|" << "         ";
	}

	cout << "|" << endl;

	//fourth line

	int counter = 0;		

	cout << "|   ";

	for(int j = 0; j < numPlayers; j++){
		if((firstSpace) == (players[j].getLocation())){
			cout << players[j].getGamePiece();
			counter++;
		}
	}	

	for(int x = 0; x < (6-counter); x++){
		        cout << " ";
	}

	cout << "|         ";	

	for(int z = 0; z < 8; z++){
	    cout << "          ";
	}

	counter = 0;		

	cout << "|   ";
	
	for(int j = 0; j < numPlayers; j++){
		if((lastSpace) == (players[j].getLocation())){
			cout << players[j].getGamePiece();
			counter++;
		}
	}	

	for(int x = 0; x < (6-counter); x++){
		        cout << " ";
	}	
	
	cout << "|" << endl;

	//fifth line
	
	if(current.getType() == "Property"){
		cout << "|" << current.getActionText(0);
	} else{
		cout << "|" << current.getActionText(0);
	}
	
	cout << "|         ";

	for(int i = 0; i < 8; i++) {
		cout << "          ";
	}

	if(current2.getType() == "Property"){
		cout << "|" << current2.getActionText(0);
	} else{
		cout << "|" << current2.getActionText(0);
	}
	
	cout << "|" << endl;

	//sixth line
	
	if(current.getType() == "Property"){
		cout << "|" << current.getActionText(1);
	} else{
		cout << "|" << current.getActionText(1);
	}
	
	cout << "|         ";

	for(int i = 0; i < 8; i++) {
		cout << "          ";
	}

	if(current2.getType() == "Property"){
		cout << "|" << current2.getActionText(1);
	} else{
		cout << "|" << current2.getActionText(1);
	}
	
	cout << "|" << endl;

}





