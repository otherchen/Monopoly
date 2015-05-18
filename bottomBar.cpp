#include "bottomBar.h"
#include "mainwindow.h"
#include "dice.h"
#include <iostream>

BottomBar::BottomBar() {

    currentPlayerNum = 0;
    bank = new Bank;
    freePark = new Player(0);
    communityCount = 0;
    chanceCount = 0;

    //creating shuffled index
    for( int i = 0; i < 10; i++){
        index[i] = i;
    }
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
    community = new Card*[10];

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
    community[index[0]]->setCardText("./community/community0.png");
    community[index[0]]->setAmount(0);

    //Community Card 1
    community[index[1]]->setCardText("./community/community1.png");
    community[index[1]]->setAmount(75);

    //Community Card 2
    community[index[2]]->setCardText("./community/community2.png");
    community[index[2]]->setAmount(150);

    //Community Card 3
    community[index[3]]->setCardText("./community/community3.png");
    community[index[3]]->setAmount(24);

    //Community Card 4
    community[index[4]]->setCardText("./community/community4.png");
    community[index[4]]->setAmount(100);

    //Community Card 5
    community[index[5]]->setCardText("./community/community5.png");
    community[index[5]]->setAmount(20);

    //Community Card 6
    community[index[6]]->setCardText("./community/community6.png");
    community[index[6]]->setAmount(39);

    //Community Card 7
    community[index[7]]->setCardText("./community/community7.png");
    community[index[7]]->setAmount(15);

    //Community Card 8
    community[index[8]]->setCardText("./community/community8.png");
    community[index[8]]->setAmount(200);
    
    //Community Card 9
    community[index[9]]->setCardText("./community/community9.png");
    community[index[9]]->setAmount(20);   


    //setting up the Chance cards
    chance = new Card*[10];

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
    chance[index[0]]->setCardText("./chance/chance0.png");
    chance[index[0]]->setAmount(0);

    //Chance Card 1
    chance[index[1]]->setCardText("./chance/chance1.png");
    chance[index[1]]->setAmount(28);

    //Chance Card 2
    chance[index[2]]->setCardText("./chance/chance2.png");
    chance[index[2]]->setAmount(50);

    //Chance Card 3
    chance[index[3]]->setCardText("./chance/chance3.png");
    chance[index[3]]->setAmount(11);

    //Chance Card 4
    chance[index[4]]->setCardText("./chance/chance4.png");
    chance[index[4]]->setAmount(100);

    //Chance Card 5
    chance[index[5]]->setCardText("./chance/chance5.png");
    chance[index[5]]->setAmount(15);

    //Chance Card 6
    chance[index[6]]->setCardText("./chance/chance6.png");
    chance[index[6]]->setAmount(15);

    //Chance Card 7
    chance[index[7]]->setCardText("./chance/chance7.png");
    chance[index[7]]->setAmount(15);

    //Chance Card 8
    chance[index[8]]->setCardText("./chance/chance8.png");
    chance[index[8]]->setAmount(5);
    
    //Chance Card 9
    chance[index[9]]->setCardText("./chance/chance9.png");
    chance[index[9]]->setAmount(100);

 

    //setting up all the buttons 
    rollButton = new QPushButton("Roll Dice");
    upgradeButton = new QPushButton("Upgrade");
    purchaseButton = new QPushButton("Purchase");
    player1Button = new QPushButton("See Player 1");
    player2Button = new QPushButton("See Player 2");
    player3Button = new QPushButton("See Player 3");
    player4Button = new QPushButton("See Player 4");
    endTurnButton = new QPushButton("End Turn");

    layout = new QGridLayout;
    layout->addWidget(endTurnButton, 0, 0, 0);
    layout->addWidget(upgradeButton, 0, 1, 0);
    layout->addWidget(purchaseButton, 0, 2, 0);
    layout->addWidget(rollButton, 0, 3, 0);  
    layout->addWidget(player1Button, 1, 0, 0);
    layout->addWidget(player2Button, 1, 1, 0);
    layout->addWidget(player3Button, 1, 2, 0);
    layout->addWidget(player4Button, 1, 3, 0);
    

    this->setMaximumSize(QSize(800, 100));

    bottomWidget = new QWidget(this);
    bottomWidget->setLayout(layout);
    setWidget(bottomWidget);

    //connecting buttons
    connect(player1Button, SIGNAL(clicked()), this, SLOT(seePlayer1()) );
    connect(player2Button, SIGNAL(clicked()), this, SLOT(seePlayer2()) );
    connect(player3Button, SIGNAL(clicked()), this, SLOT(seePlayer3()) );
    connect(player4Button, SIGNAL(clicked()), this, SLOT(seePlayer4()) );
    connect(rollButton, SIGNAL(clicked()), this, SLOT(rollDice()) );
    connect(endTurnButton, SIGNAL(clicked()), this, SLOT(endTurn()) );
    connect(purchaseButton, SIGNAL(clicked()), this, SLOT(purchase()) );
    connect(upgradeButton, SIGNAL(clicked()), this, SLOT(upgrade()) );

    //disabling the endTurnButton
    endTurnButton->setEnabled(false);
    purchaseButton->setEnabled(false);
    upgradeButton->setEnabled(false);
}

void BottomBar::setPlayers(int numberPlayers, GUIPlayers* tempPlayers[]){

	numberOfPlayers = numberPlayers;
	numAlive = numberPlayers;
	int NUM_PLAYERS = numberPlayers;
	allPlayers = new GUIPlayers*[NUM_PLAYERS];
	allPlayers = tempPlayers;

}
    
void BottomBar::setCentralWidget(CentralWidget* tempBoard){
	
	monopolyBoard = tempBoard;
	monopolyBoard->initializingCards(index);

}

void BottomBar::setMainWindow(MainWindow* tempWindow){
	myWindow = new MainWindow();
	myWindow = tempWindow;

	for(int i = 0; i < numberOfPlayers; i++){
		allPlayers[i]->setBank(bank);
	}
}

void BottomBar::disableButtons(int num){
	if(num == 1){
	    player4Button->setEnabled(false);
	} else if (num ==2){
	    player3Button->setEnabled(false);
	    player4Button->setEnabled(false);
	}
}

void BottomBar::seePlayer1(){
     myWindow->removeDockWidget( allPlayers[currentPlayerNum] );
     myWindow->addDockWidget( Qt::RightDockWidgetArea, allPlayers[0] );
     allPlayers[0]->show();
     currentPlayerNum = 0;
}

void BottomBar::seePlayer2(){
     myWindow->removeDockWidget( allPlayers[currentPlayerNum] );
     myWindow->addDockWidget( Qt::RightDockWidgetArea, allPlayers[1] );
     allPlayers[1]->show();
     currentPlayerNum = 1;
}

void BottomBar::seePlayer3(){
  if(numberOfPlayers > 2){
     myWindow->removeDockWidget( allPlayers[currentPlayerNum] );
     myWindow->addDockWidget( Qt::RightDockWidgetArea, allPlayers[2] );
     allPlayers[2]->show();
     currentPlayerNum = 2;
  }
}

void BottomBar::seePlayer4(){
  if(numberOfPlayers > 3){
     myWindow->removeDockWidget( allPlayers[currentPlayerNum] );
     myWindow->addDockWidget( Qt::RightDockWidgetArea, allPlayers[3] );
     allPlayers[3]->show();
     currentPlayerNum = 3;
  }
}

void BottomBar::rollDice(){
  
    //getting 2 random dice rolls
    Dice dice[2];
    diceRoll1 = dice[0].rollDice();
    diceRoll2 = dice[1].rollDice();
    oldSpace = 0;
    newSpace = 0;
    int futureSpace = 0;

    //changing dice images on board
    monopolyBoard->changeDiceImg(diceRoll1, diceRoll2);

    //moving pieces
    oldSpace = myWindow->getPlayerLocation(currentPlayerNum);
    newSpace = oldSpace;
    newSpace += (diceRoll1 + diceRoll2);
    newSpace = newSpace % 40;
    myWindow->setPlayerLocation(currentPlayerNum, newSpace);
    monopolyBoard->movePieces(currentPlayerNum, myWindow->getPlayerPixels(currentPlayerNum));

    if(oldSpace > newSpace) {
	moneyAction.takeBank(myWindow->getPlayer(currentPlayerNum), bank, 200);
	allPlayers[currentPlayerNum]->setMoneyText();
    }

    /*****************************     If new location is a Property     *****************************/

	int currentOwnership = myWindow->getSpaceOwnership(newSpace);

        //if the space is some sort of property...
	if((myWindow->spaceType(newSpace) == "Property" || myWindow->spaceType(newSpace) == "RailRoad") || myWindow->spaceType(newSpace) == "Utility"){

		 //if the property is not owned...
		if(myWindow->getSpaceOwnership(newSpace) < 0) {
			if(myWindow->getPlayerMoney(currentPlayerNum) - myWindow->getSpacePropertyCost(newSpace) <= 0) {
			    purchaseButton->setEnabled(false);
			} else {
			    purchaseButton->setEnabled(true);
			}

		 //else if property is owned...
		} else if (myWindow->getSpaceOwnership(newSpace) >= 0) {

			if(myWindow->getPlayerName(currentPlayerNum) != myWindow->getPlayerName(myWindow->getSpaceOwnership(newSpace))){
		
				moneyAction.executeAction(myWindow->getPlayer(currentPlayerNum), myWindow->getPlayer(currentOwnership), myWindow->getSpaceRent(newSpace));
				allPlayers[currentPlayerNum]->setMoneyText();	
			}
		}
	

	//checking if players are out of money
	if(myWindow->getPlayerMoney(currentPlayerNum) <= 0 && myWindow->isPlayerAlive(currentPlayerNum) == true){
					
		myWindow->playerLost(currentPlayerNum);
		
		for(int j = 0; j < 40; j++){
			if(myWindow->getSpaceOwnership(j) == currentPlayerNum){
			    myWindow->setSpaceOwnership(j, -1);
			}
		}

		if(currentPlayerNum == 0) {
			player1Button->setEnabled(false);
		} else if (currentPlayerNum == 1) {
			player2Button->setEnabled(false);
		} else if (currentPlayerNum == 2) {
			player3Button->setEnabled(false);
		} else if (currentPlayerNum == 3) {
			player4Button->setEnabled(false);
		}
		
		monopolyBoard->hidePiece(currentPlayerNum);
		allPlayers[currentPlayerNum]->setMoneyText();
		numAlive--;

	}
	
    /*******************************     If new Location is a "Tax"     **********************************/

	//if the space is a Tax...
	} else if(myWindow->spaceType(newSpace) == "Tax"){
		moneyAction.executeAction(myWindow->getPlayer(currentPlayerNum), freePark, myWindow->getSpaceTax(newSpace));
		allPlayers[currentPlayerNum]->setMoneyText();

        //checking if players are out of money
	if(myWindow->getPlayerMoney(currentPlayerNum) <= 0 && myWindow->isPlayerAlive(currentPlayerNum) == true){
					
		myWindow->playerLost(currentPlayerNum);
		
		for(int j = 0; j < 40; j++){
			if(myWindow->getSpaceOwnership(j) == currentPlayerNum){
			    myWindow->setSpaceOwnership(j, -1);
			}
		}

		if(currentPlayerNum == 0) {
			player1Button->setEnabled(false);
		} else if (currentPlayerNum == 1) {
			player2Button->setEnabled(false);
		} else if (currentPlayerNum == 2) {
			player3Button->setEnabled(false);
		} else if (currentPlayerNum == 3) {
			player4Button->setEnabled(false);
		}
		
		monopolyBoard->hidePiece(currentPlayerNum);
		allPlayers[currentPlayerNum]->setMoneyText();
		numAlive--;
	}
	


    /*******************************     If new Location is "Free Parking"     **********************************/

        //if the space is Free Parking...
	} else if(myWindow->spaceType(newSpace) == "FreeParking"){
		moneyAction.executeAction(freePark, myWindow->getPlayer(currentPlayerNum), freePark->getMoneyAmount());
		freePark->setMoneyAmount(0);
		allPlayers[currentPlayerNum]->setMoneyText();


    /*******************************     If new Location is "Go To Jail"     **********************************/

       	//if the space is Go To Jail...
	} else if(myWindow->spaceType(newSpace) == "GoJail"){
		myWindow->setPlayerLocation(currentPlayerNum, 10);
		moneyAction.executeAction(myWindow->getPlayer(currentPlayerNum), freePark, 200);
		monopolyBoard->movePieces(currentPlayerNum, myWindow->getPlayerPixels(currentPlayerNum));
	

    /*******************************     If new Location is "Community Chest"     **********************************/

 	//if the space is Community Chest...
	} else if (myWindow->spaceType(newSpace) == "Community Chest"){

		monopolyBoard->showCommunity(communityCount);

		community[communityCount]->cardAction(bank, myWindow->getPlayer(currentPlayerNum));
		myWindow->setPlayerLocation(currentPlayerNum, myWindow->getPlayerLocation(currentPlayerNum));
		monopolyBoard->movePieces(currentPlayerNum, myWindow->getPlayerPixels(currentPlayerNum));
		

	  futureSpace = myWindow->getPlayerLocation(currentPlayerNum);
	  if(futureSpace < newSpace){
		moneyAction.takeBank(myWindow->getPlayer(currentPlayerNum), bank,  200);
	  }
	
	  allPlayers[currentPlayerNum]->setMoneyText();


    /*******************************     If new Location is "Chance"     **********************************/

	//if the space is Chance...
	} else if (myWindow->spaceType(newSpace) == "Chance"){

		monopolyBoard->showChance(chanceCount);

		chance[chanceCount]->cardAction(bank, myWindow->getPlayer(currentPlayerNum));
		myWindow->setPlayerLocation(currentPlayerNum, myWindow->getPlayerLocation(currentPlayerNum));
		monopolyBoard->movePieces(currentPlayerNum, myWindow->getPlayerPixels(currentPlayerNum));
		

	  futureSpace = myWindow->getPlayerLocation(currentPlayerNum);
	  if(futureSpace < newSpace){
		moneyAction.takeBank(myWindow->getPlayer(currentPlayerNum), bank,  200);
	  }
	
	  allPlayers[currentPlayerNum]->setMoneyText();
	  
        }

    //disabling and enabling buttons
    endTurnButton->setEnabled(true);
    rollButton->setEnabled(false);
}

void BottomBar::upgrade(){
	
	allPlayers[currentPlayerNum]->enableUpgrade();

}

void BottomBar::purchase(){

	//if player cannot afford the property
	if(myWindow->getPlayerMoney(currentPlayerNum) - myWindow->getSpacePropertyCost(newSpace) <= 0) {
		//let Player know he can't purchase in GUI (pop up box) or disable button

	} else {

		//paying the money
		moneyAction.giveBank(myWindow->getPlayer(currentPlayerNum), bank, myWindow->getSpacePropertyCost(newSpace));
		//moneyAction.giveBank(myWindow->getPlayer(currentPlayerNum), bank, 1000);
		myWindow->setSpaceOwnership(newSpace, currentPlayerNum); 
		allPlayers[currentPlayerNum]->setMoneyText();

	    //if(myWindow->spaceType(newSpace) == "Property") {
		stringstream ss;
                string tempString1;
		string tempString2;

		ss << myWindow->getSpaceName(newSpace, 0);
		ss << myWindow->getSpaceName(newSpace, 1);
		ss >> tempString1;
		ss >> tempString2;
		ss.clear();  		

		allPlayers[currentPlayerNum]->addProperty(newSpace, tempString1 + " " + tempString2, myWindow->getAllSpaces());
	    //}

	} 

        //checking if players are out of money
	if(myWindow->getPlayerMoney(currentPlayerNum) <= 0 && myWindow->isPlayerAlive(currentPlayerNum) == true){
	
		myWindow->playerLost(currentPlayerNum);

		for(int j = 0; j < 40; j++){
			if(myWindow->getSpaceOwnership(j) == currentPlayerNum){
			    myWindow->setSpaceOwnership(j, -1);
			}
		}

		if(currentPlayerNum == 0) {
			player1Button->setEnabled(false);
		} else if (currentPlayerNum == 1) {
			player2Button->setEnabled(false);
		} else if (currentPlayerNum == 2) {
			player3Button->setEnabled(false);
		} else if (currentPlayerNum == 3) {
			player4Button->setEnabled(false);
		}

		monopolyBoard->hidePiece(currentPlayerNum);
		allPlayers[currentPlayerNum]->setMoneyText();
		numAlive--;
	}

	purchaseButton->setEnabled(false);
        upgradeButton->setEnabled(true);
}

void BottomBar::endTurn(){
  
    //incrimenting turn
    myWindow->nextTurn();
    int next = myWindow->getPlayerTurn();

    while (!(myWindow->isPlayerAlive(next))){
        myWindow->nextTurn();
        next = myWindow->getPlayerTurn();
    }
   
    monopolyBoard->resetCommunity(communityCount);
    monopolyBoard->resetChance(chanceCount);

    communityCount++;
    if(communityCount > 9){
	communityCount = 0;
    }
    chanceCount++;
    if(chanceCount > 9){
        chanceCount = 0;
    }

    if(numAlive <= 1){
	stringstream ss;
	string nextString;
	string fullText;
	string informativeText;

        rollButton->setEnabled(false);
        upgradeButton->setEnabled(false);
        purchaseButton->setEnabled(false);
        player1Button->setEnabled(false);
        player2Button->setEnabled(false);
        player3Button->setEnabled(false);
        player4Button->setEnabled(false);
        endTurnButton->setEnabled(false);
        allPlayers[next]->disableUpgrade();
	
	ss << (next + 1);
	ss >> nextString;
	fullText = "Congratulations Player " + nextString + ", you have won the game!";
	informativeText = "You are now the ruler of the universe.";
        QString qText = QString::fromStdString(fullText);
	QString qInfo = QString::fromStdString(informativeText);

        QMessageBox winnerDisplay;
        winnerDisplay.setText(qText);
	winnerDisplay.setInformativeText(qInfo);
        winnerDisplay.exec();
    }

    myWindow->removeDockWidget( allPlayers[currentPlayerNum] );
    myWindow->addDockWidget( Qt::RightDockWidgetArea, allPlayers[next] );
    allPlayers[currentPlayerNum]->disableUpgrade();
    allPlayers[next]->show();
    currentPlayerNum = next;

    //disabling and enabling buttons
    endTurnButton->setEnabled(false);
    rollButton->setEnabled(true);
    purchaseButton->setEnabled(false);

    for(int i = 0; i < 40; i++){
	if(myWindow->getSpaceOwnership(i) == currentPlayerNum && myWindow->spaceType(i) == "Property"){
		upgradeButton->setEnabled(true);
		break;
	} else {
		upgradeButton->setEnabled(false);
	}
    }
}








