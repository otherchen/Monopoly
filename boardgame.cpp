/*
Andrew Chen
Professor Crowley
April 30, 2014
PA6: Board Game
*/

#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <QApplication>
#include "player.h"
#include "space.h"
#include "Game_Board.h"
#include "dice.h"
#include "action.h"
#include "move_action.h"
#include "money_action.h"
#include "goToAction.h"
#include "card.h"
#include "card_money.h"
#include "card_move.h"
#include "bank.h"
#include "mainwindow.h"

using namespace std;

int main(int argv, char* argc[]) {

    //creating QApp
    QApplication app(argv, argc);

    //seeding the time
    srand(time(0));

    //variables
    int numOfPlayers = 0;
    char gamePieces[10] = {'~', '!', '@', '#', '$', '%', '^', '&', '*', '?'};
    int numOfPieces = 10; 

/*************    setting up NUMBER OF PLAYERS pop up box    *****************/
    QMessageBox numPlayersBox;
    QPushButton *button2 = numPlayersBox.addButton(QPushButton::tr("Two"), QMessageBox::ActionRole);
    QPushButton *button3 = numPlayersBox.addButton(QPushButton::tr("Three"), QMessageBox::ActionRole);
    QPushButton *button4 = numPlayersBox.addButton(QPushButton::tr("Four"), QMessageBox::ActionRole);
    numPlayersBox.setText("How many people would like to play?");
    numPlayersBox.exec();

    if (numPlayersBox.clickedButton() == button2) {
      numOfPlayers = 2;

    }
    if (numPlayersBox.clickedButton() == button3) {
    numOfPlayers= 3;

    }
    if (numPlayersBox.clickedButton() == button4) {
    numOfPlayers = 4;

    }

/*****************************************************************************/

    //setting up the game
    MainWindow mainWindow(numOfPlayers);
    Game_Board gameBoard;
    gameBoard.createPlayers(numOfPlayers);
    Bank bank;
    Player freePark(0);
    MoneyAction moneyAction;
    GoToAction goToAction;
    Dice dice[2];
    string gamePieceIcons[10] = {"hat.png", "baseball.png", "dog.png", "soccer.png", "surfer.png", "dragon.png", "barrow.png", "pretzel.png", "car.png", "ship.png"};

/**************      Setting up Game Piece Choices     ******************/

    QPushButton *icon[10];

    //giving game pieces to players
    for(int i = 0; i < numOfPlayers; i++){

	stringstream ss;
	string tempPlayerNum;
	int indexPiece = 0;
	
	//allowing user to choose game piece
	for(int j = 0; j < numOfPieces; j++){
	    icon[j] = NULL;
        }
	
	ss << (i+1);
	ss >> tempPlayerNum;
	QString tempNum = QString::fromStdString(tempPlayerNum);

  	QMessageBox gamePieceBox;
	gamePieceBox.setText("Player " + tempNum + ", please choose from the following game pieces.");
	
	for(int j = 0; j < numOfPieces; j++){
	    icon[j] = new QPushButton;
	    icon[j]->setIcon(QIcon(QString(("Pieces/" + gamePieceIcons[j]).c_str())));
	    icon[j]->setIconSize(QSize(50,50));
	    gamePieceBox.addButton(icon[j], QMessageBox::ActionRole);
	}   

	gamePieceBox.exec();
	
	for( int j = 0; j < numOfPieces; j++){

	    if(gamePieceBox.clickedButton() == icon[j]){
		//set guiPlayer's gamepiece to the chosen gamePieceIcon
		indexPiece = j;
		mainWindow.setGamePiece(i, "Pieces/" + gamePieceIcons[indexPiece]);
		break;
	    }

	}
	
	numOfPieces--;
	
	//rearranging the game pieces to account for chosen piece
	for(int x = indexPiece; x < numOfPieces; x++){
		string tempPiece = "";
		tempPiece = gamePieceIcons[x];
	        gamePieceIcons[x] = gamePieceIcons[x+1];
		gamePieceIcons[x+1] = tempPiece;
	}	

    }

/*****************************************************************************/

    //setting up Full Game Board in Qt
    mainWindow.windowSetUp();
    mainWindow.show();
    return app.exec();






  
    //creating shuffled index
    int index[10] = {0,1,2,3,4,5,6,7,8,9};
    int random1 = -1;
    int random2 = -1;
    int tempNum = -1;
    
    for(int i = 0; i < 50; i++){
	random1 = rand()%10;
	random2 = rand()%10;

	tempNum = index[random1];
	index[random1] = index[random2];
	index[random2] = tempNum;	
    }

    //setting up the Community Chest cards
    Card** community = new Card*[10];

    community[index[0]] = new CardMove();
    community[index[1]] = new CardMoney();
    community[index[2]] = new CardMoney();
    community[index[3]] = new CardMove();
    community[index[4]] = new CardMoney();
    community[index[5]] = new CardMoney();
    community[index[6]] = new CardMove();
    community[index[7]] = new CardMoney();
    community[index[8]] = new CardMoney();
    community[index[9]] = new CardMoney();

    //Community Card 0
    community[index[0]]->setCardText("Advance to GO!");
    community[index[0]]->setAmount(0);

    //Community Card 1
    community[index[1]]->setCardText("Cheap Books on Amazon!");
    community[index[1]]->setAmount(75);

    //Community Card 2
    community[index[2]]->setCardText("It's your Birthday");
    community[index[2]]->setAmount(150);

    //Community Card 3
    community[index[3]]->setCardText("Advance to The Knight's Bench!");
    community[index[3]]->setAmount(24);

    //Community Card 4
    community[index[4]]->setCardText("You get a Research Position!");
    community[index[4]]->setAmount(100);

    //Community Card 5
    community[index[5]]->setCardText("Won 2nd Place at Songfest!");
    community[index[5]]->setAmount(20);

    //Community Card 6
    community[index[6]]->setCardText("March to the Coliseum!");
    community[index[6]]->setAmount(39);

    //Community Card 7
    community[index[7]]->setCardText("Parents send you a care package!");
    community[index[7]]->setAmount(15);

    //Community Card 8
    community[index[8]]->setCardText("You get a Paid Internship!");
    community[index[8]]->setAmount(200);
    
    //Community Card 9
    community[index[9]]->setCardText("Given the Pell Grant!");
    community[index[9]]->setAmount(20);

       
    //setting up the Chance cards
    Card** chance = new Card*[10];

    chance[index[0]] = new CardMove();
    chance[index[1]] = new CardMove();
    chance[index[2]] = new CardMoney();
    chance[index[3]] = new CardMove();
    chance[index[4]] = new CardMoney();
    chance[index[5]] = new CardMoney();
    chance[index[6]] = new CardMove();
    chance[index[7]] = new CardMoney();
    chance[index[8]] = new CardMove();
    chance[index[9]] = new CardMoney();

    //Chance Card 0
    chance[index[0]]->setCardText("Advance to GO!");
    chance[index[0]]->setAmount(0);

    //Chance Card 1
    chance[index[1]]->setCardText("Advance to Laundry");
    chance[index[1]]->setAmount(28);

    //Chance Card 2
    chance[index[2]]->setCardText("You steal from charity!");
    chance[index[2]]->setAmount(50);

    //Chance Card 3
    chance[index[3]]->setCardText("Advance to Silent Chapel");
    chance[index[3]]->setAmount(11);

    //Chance Card 4
    chance[index[4]]->setCardText("Your parents give you money!");
    chance[index[4]]->setAmount(100);

    //Chance Card 5
    chance[index[5]]->setCardText("There is an error with your banking!");
    chance[index[5]]->setAmount(15);

    //Chance Card 6
    chance[index[6]]->setCardText("Take a trip to the LA Metro");
    chance[index[6]]->setAmount(15);

    //Chance Card 7
    chance[index[7]]->setCardText("You found some printer ink!");
    chance[index[7]]->setAmount(15);

    //Chance Card 8
    chance[index[8]]->setCardText("Advance to Campus Cruiser!");
    chance[index[8]]->setAmount(5);
    
    //Chance Card 9
    chance[index[9]]->setCardText("Got a good grade in programming class!");
    chance[index[9]]->setAmount(100);
    
    //print Game Board 
    gameBoard.displayHorizontal(20, 30, numOfPlayers);
    gameBoard.displayVertical(19, 31, numOfPlayers);
    gameBoard.displayVertical(18, 32, numOfPlayers);
    gameBoard.displayVertical(17, 33, numOfPlayers);
    gameBoard.displayVertical(16, 34, numOfPlayers);
    gameBoard.displayVertical(15, 35, numOfPlayers);
    gameBoard.displayVertical(14, 36, numOfPlayers);
    gameBoard.displayVertical(13, 37, numOfPlayers);
    gameBoard.displayVertical(12, 38, numOfPlayers);
    gameBoard.displayVertical(11, 39, numOfPlayers);
    gameBoard.displayHorizontal(10, 0, numOfPlayers);

    //Begin Game
    stringstream ss;
    string enterBuffer;
    getline(cin, enterBuffer);
    int diceRoll1;
    int diceRoll2;
    int communityCount = 0;
    int chanceCount = 0;
    int numAlive = numOfPlayers;

    cout << endl;

    //as long as there are players, continue the game
    while(numAlive > 1){

    //cycling through each player's turn
    for (int i = 0; i < numOfPlayers; i++){

      if(gameBoard.isPlayerAlive(i) == true){

    	cout << "It's " << gameBoard.getPlayerName(i);
    	cout << "'s turn!" << endl;
	
	int answer = 0;
	
	while(answer != 1){
	    do{
		//print out menu
		cout << "Please choose one of the following options..." << endl;
		cout << " 1. Roll" << endl;
		cout << " 2. Upgrade" << endl;
		cout << " 3. Quit" << endl;
		cout << "Enter a number between 1 and 3: ";
		
		    cin >> answer;
	
		    if(cin.fail()){
			cin.clear();
			cin.ignore(10000, '\n');
		        cout << "Improper input! Try again!" << endl << endl;
			continue;
		    } else if(answer < 1 || answer > 3){
			cout << "\nNumber is out of range... Try again!" << endl << endl;
			continue;
		    }	

		getline(cin, enterBuffer);
		cout << endl;
	    } while (answer < 1 || answer > 3);

	    switch(answer){
	        case 1:
		    continue;
		    break;
	        case 2:
		    {
		    int own[40];
		    int count = 0;
		    int upgradeNum = 0;
		    stringstream ss2;

		    for(int x = 0; x < 40; x++){
			if(gameBoard.getSpaceOwnership(x) == i && gameBoard.spaceType(x) == "Property"){
			    own[count] = x;
			    count++;
		 	}
		    }

		    string tempName1;
		    string tempName2;
		    int j = 0;
		    
		    cout << "You own the following properties:" << endl;
		    cout << " 1. Cancel" << endl;
		    
		    for(j = 0; j < count; j++){
			int currentOwn = own[j];
			tempName1 = "";
		        tempName2 = "";
	
			ss2 << gameBoard.getSpaceName(currentOwn, 0);
		        ss2 << gameBoard.getSpaceName(currentOwn, 1);
		        ss2 >> tempName1;
		        ss2 >> tempName2;
			ss2.clear();			
			
			cout << " " << j+2 << ". " << tempName1 << " " << tempName2 << ": $" << gameBoard.getSpacePropertyCost(currentOwn) << endl;
		    }
		    
		    cout << endl << "What would you like to upgrade? (Max 4 upgrades): ";
		    
		    while(upgradeNum < 1 || upgradeNum > j+1){
		    
		    cin >> upgradeNum;
		    if(cin.fail()){
			cin.clear();
	    		cin.ignore(10000, '\n');
			cout << "Invalid entry. Try again: ";
			continue;
		    } else if (upgradeNum < 1 || upgradeNum > j+1){
			cout << "Entry out of range...Try again: ";
			continue;
		    }
		    }

		    if(upgradeNum == 1){
			cout << endl;
			continue;
		    }

		    upgradeNum = upgradeNum - 2;
		    
		    string tempName3;
		    string tempName4;
		    
		    ss.clear();
		    ss2 << gameBoard.getSpaceName(own[upgradeNum], 0);
		    ss2 << gameBoard.getSpaceName(own[upgradeNum], 1);
		    ss2 >> tempName3;
	            ss2 >> tempName4;
		    ss2.clear();

		    if(gameBoard.getPlayerMoney(i) - gameBoard.getSpacePropertyCost(own[upgradeNum]) <= 0) {
			cout << "You do not have enough money to upgrade this property!" << endl << endl;
			continue;
		    }		    
		
		    gameBoard.upgradeSpace(own[upgradeNum]);
		    moneyAction.giveBank(gameBoard.getPlayer(i), &bank, gameBoard.getSpacePropertyCost(own[upgradeNum]));

		    cout << "You have just upgraded " << tempName3 << " " << tempName4 << endl << endl;
 		    break;
		    }
	        case 3:
		    return 0;
		    break;
	    }
	}

	//rolling the die and moving the player
	cin.clear();
	diceRoll1 = dice[0].rollDice();
	diceRoll2 = dice[1].rollDice();
	cout << "You rolled...Move " << diceRoll1 + diceRoll2 << " steps." << endl << endl;
	int pastLocation = gameBoard.getPlayerLocation(i);
	gameBoard.move(i, diceRoll1 + diceRoll2);
	int currentLocation = gameBoard.getPlayerLocation(i);
	int currentOwnership = gameBoard.getSpaceOwnership(currentLocation);
	int futureLocation = 0;
	

	//if you pass GO collect $200
	if(pastLocation > currentLocation){
		moneyAction.takeBank(gameBoard.getPlayer(i), &bank,  200);
		cout << "*** You Passed GO! Collect $200! ***" << endl << endl;
	}

/********************** Actions for Specific Space Types **************************/

	//if the space is some sort of property...
	if((gameBoard.spaceType(currentLocation) == "Property" || gameBoard.spaceType(currentLocation) == "RailRoad") || gameBoard.spaceType(currentLocation) == "Utility"){

		 //if the property is not owned...
		if(gameBoard.getSpaceOwnership(currentLocation) < 0) {

			char purchaseAnswer;
			string tempName1;
			string tempName2;
			ss << gameBoard.getSpaceName(currentLocation, 0);
			ss << gameBoard.getSpaceName(currentLocation, 1);
			ss >> tempName1;
			ss >> tempName2;
			ss.clear();
			
			cout << "Would you like to purchase \"" << tempName1 << " " << tempName2 << "\" for " << gameBoard.getSpacePropertyCost(currentLocation) << "? (y or n): ";
			
			do{
			cin >> purchaseAnswer;
			if(cin.fail()){
			    cin.clear();
	    		    cin.ignore(10000, '\n');
			    cout << "Improper Entry. Please enter 'y' or 'n': ";
			    continue;
			} else if(purchaseAnswer != 'y' && purchaseAnswer != 'n'){
			    cout << "Error, please enter 'y' or 'n'! Try again: ";
			    continue;
			}
			} while(purchaseAnswer!= 'y' && purchaseAnswer != 'n');

			getline(cin, enterBuffer);
			cin.clear();
			cout << endl;
		
			//you purchase the property
			if(purchaseAnswer == 'y'){
	
			//if player cannot afford the property
			if(gameBoard.getPlayerMoney(i) - gameBoard.getSpacePropertyCost(currentLocation) <= 0) {
				cout << "You do not have enough money to purchase this property!" << endl << endl;

				//printing out player's money
				for(int j = 0; j < numOfPlayers; j++){
				    if(gameBoard.isPlayerAlive(j) == true){
					cout << gameBoard.getPlayerName(j) << ": $"<< gameBoard.getPlayerMoney(j) << endl;
				    }				
				}

				cout << "~~~~~~~~~~~~~~~~~~" << endl << endl;
				continue;
		   	}

				//paying the money
				moneyAction.giveBank(gameBoard.getPlayer(i), &bank, gameBoard.getSpacePropertyCost(currentLocation));
				gameBoard.setSpaceOwnership(currentLocation, i); 

			//you do not purchase the property
			} else {
				cout << "You do not buy this property..." << endl << endl;
			}

	 	//if the property is owned...
		} else if(gameBoard.getSpaceOwnership(currentLocation) >= 0) {
		
			if(gameBoard.getPlayerName(i) != gameBoard.getPlayerName(gameBoard.getSpaceOwnership(currentLocation))){
				cout << "You must pay $" << gameBoard.getSpaceRent(currentLocation) << " to " << gameBoard.getPlayerName(currentOwnership) << "." << endl << endl;
				moneyAction.executeAction(gameBoard.getPlayer(i), gameBoard.getPlayer(currentOwnership), gameBoard.getSpaceRent(currentLocation));	
			}

				//checking if players are out of money
				if(gameBoard.getPlayerMoney(i) <= 0 && gameBoard.isPlayerAlive(i) == true){
					cout << "*************************************" << endl;
					cout << gameBoard.getPlayerName(i) << " is out of money! He drops out of the game!" << endl;
					gameBoard.playerLost(i);
		
					for(int j = 0; j < 40; j++){
						if(gameBoard.getSpaceOwnership(j) == i){
						gameBoard.setSpaceOwnership(j, -1);
						}
					}
	
					cout << "All of " << gameBoard.getPlayerName(i) << "'s properties are now returned to the bank." << endl;
					cout << "*************************************" << endl << endl;
	
					numAlive--;
					continue;
				}			
			}
	
	//if the space is a Tax...
	} else if(gameBoard.spaceType(currentLocation) == "Tax"){
		cout << "You must pay $" << gameBoard.getSpaceTax(currentLocation) << " in taxes!" << endl << endl;
		moneyAction.executeAction(gameBoard.getPlayer(i), &freePark, gameBoard.getSpaceTax(currentLocation));

	//checking if players are out of money
	if(gameBoard.getPlayerMoney(i) <= 0 && gameBoard.isPlayerAlive(i) == true){
		cout << "*************************************" << endl;
		cout << gameBoard.getPlayerName(i) << " is out of money! He drops out of the game!" << endl;
		gameBoard.playerLost(i);
		
		for(int j = 0; j < 40; j++){
			if(gameBoard.getSpaceOwnership(j) == i){
				gameBoard.setSpaceOwnership(j, -1);
			}
		}
	
		cout << "All of " << gameBoard.getPlayerName(i) << "'s properties are now returned to the bank." << endl;
		cout << "*************************************" << endl << endl;

		numAlive--;
		continue;
	}
    

	//if the space is Free Parking...
	} else if(gameBoard.spaceType(currentLocation) == "FreeParking"){
		cout << "You landed on Financial Aid! Collect $" << freePark.getMoneyAmount() << "." << endl << endl;
		moneyAction.executeAction(&freePark, gameBoard.getPlayer(i), freePark.getMoneyAmount());

	//if the space is Go To Jail...
	} else if(gameBoard.spaceType(currentLocation) == "GoJail"){
		cout << "Go Directly to Jail and pay $100! >:D" << endl << endl;
		goToAction.executeAction(gameBoard.getPlayer(i), gameBoard.getPlayer(i), 10);

		moneyAction.executeAction(gameBoard.getPlayer(i), &freePark, 100);
	
	//if the space is Community Chest...
	} else if (gameBoard.spaceType(currentLocation) == "Community Chest"){
		cout << "You landed on Community Chest!" << endl << endl;
		community[communityCount]->cardAction(&bank, gameBoard.getPlayer(i));

	  cout << community[communityCount]->getCardText(0) << endl;
	  cout << community[communityCount]->getCardText(1) << endl << endl;

	  futureLocation = gameBoard.getPlayerLocation(i);
	  if(futureLocation < currentLocation){
		moneyAction.takeBank(gameBoard.getPlayer(i), &bank,  200);
		cout << "*** You Passed GO! Collect $200! ***" << endl << endl;
	  }
	
	  communityCount++;
	  if(communityCount > 9){
		communityCount = 0;
	  }
	
	//if the space is Chance...	
	} else if (gameBoard.spaceType(currentLocation) == "Chance"){
		cout << "You landed on Chance!" << endl << endl;
		chance[chanceCount]->cardAction(&bank, gameBoard.getPlayer(i));

	  cout << chance[chanceCount]->getCardText(0) << endl;
	  cout << chance[chanceCount]->getCardText(1) << endl << endl;
	
	  futureLocation = gameBoard.getPlayerLocation(i);
	  if(futureLocation < currentLocation){
		moneyAction.takeBank(gameBoard.getPlayer(i), &bank, 200);
		cout << "*** You Passed GO! Collect $200! ***" << endl << endl;
	  }

	  chanceCount++;
	  if(chanceCount > 9){
		chanceCount = 0;
	  }
	}

	//printing out player's money
	for(int i = 0; i < numOfPlayers; i++){
	    if(gameBoard.isPlayerAlive(i) == true){
		cout << gameBoard.getPlayerName(i) << ": $"<< gameBoard.getPlayerMoney(i) << endl;
	    }
	}

	cout << "~~~~~~~~~~~~~~~~~~" << endl << endl;
      }
    }

    //checking if players are out of money
    for(int i = 0; i < numOfPlayers; i++){
	if(gameBoard.getPlayerMoney(i) <= 0 && gameBoard.isPlayerAlive(i) == true){
		cout << "*************************************" << endl;
		cout << gameBoard.getPlayerName(i) << " is out of money! He drops out of the game!" << endl;
		gameBoard.playerLost(i);
		
		for(int j = 0; j < 40; j++){
			if(gameBoard.getSpaceOwnership(j) == i){
	 			gameBoard.setSpaceOwnership(j, -1);
			}
		}
	
		cout << "All of " << gameBoard.getPlayerName(i) << "'s properties are now returned to the bank." << endl;
		cout << "*************************************" << endl << endl;	

		numAlive--;
		continue;
	}
    }

    if(numAlive <= 1){
	for(int x = 0; x < numOfPlayers; x++){
		if(gameBoard.isPlayerAlive(x) == true){
			cout << "****************************" << endl;
			cout << gameBoard.getPlayerName(x) << " is the winner! Congratulations!" << endl;
			cout << "****************************" << endl;
		}
		return 0;
	}		 
    }

    cout << "Press 'enter' to print the board." << endl;
    getline(cin, enterBuffer); 
    
    if(cin.fail()){
	cin.clear();
	cin.ignore(10000, '\n');
	cout << "Error with data entry. Terminating program!" << endl;
	return 1;
    }  

    //print Game Board 
    gameBoard.displayHorizontal(20, 30, numOfPlayers);
    gameBoard.displayVertical(19, 31, numOfPlayers);
    gameBoard.displayVertical(18, 32, numOfPlayers);
    gameBoard.displayVertical(17, 33, numOfPlayers);
    gameBoard.displayVertical(16, 34, numOfPlayers);
    gameBoard.displayVertical(15, 35, numOfPlayers);
    gameBoard.displayVertical(14, 36, numOfPlayers);
    gameBoard.displayVertical(13, 37, numOfPlayers);
    gameBoard.displayVertical(12, 38, numOfPlayers);
    gameBoard.displayVertical(11, 39, numOfPlayers);
    gameBoard.displayHorizontal(10, 0, numOfPlayers);
    
    }

}
