#include "centralwidget.h"

CentralWidget::CentralWidget(int tempNum, Player* tempPlayers): QWidget() {
  numPlayers = tempNum;
  
  //setting up the chance and community chest images
  boardLabel = new QLabel( this ); //adding current widget to another widget
  boardLabel->setPixmap( QPixmap("./Images/Monopoly.jpg") );
  this->setGeometry(0, 0, 650, 650);

  //setting up the dice images
  dice1 = new QLabel(this);
  dice1->setPixmap(QPixmap("./Dice/dice1.png"));
  dice1->setGeometry(430, 370, 35, 35);
  dice1->setFixedWidth(35);
  dice1->setFixedHeight(35);
  dice1->setScaledContents(true);
  dice1->show();

  dice2 = new QLabel(this);
  dice2->setPixmap(QPixmap("./Dice/dice1.png"));
  dice2->setGeometry(470, 370, 35, 35);
  dice2->setFixedWidth(35);
  dice2->setFixedHeight(35);
  dice2->setScaledContents(true);
  dice2->show();

  
  //Create the covers for the card deck
  chanceCover = new QLabel(this);
  chanceCover->setPixmap(QPixmap("./Chance/chanceTemplate.jpg"));
  chanceCover->setGeometry(102, 102, 180, 100);
  chanceCover->setFixedWidth(180);
  chanceCover->setFixedHeight(100);
  chanceCover->setScaledContents(true);
  chanceCover->show();

  communityCover = new QLabel(this);
  communityCover->setPixmap(QPixmap("./Community Chest/communityTemplate.jpg"));
  communityCover->setGeometry(366, 442, 180, 100);
  communityCover->setFixedWidth(180);
  communityCover->setFixedHeight(100);
  communityCover->setScaledContents(true);
  communityCover->show();

  //setting up Player Icons
  playerIcons = new QLabel*[numPlayers];
  int pieceCounter = 0;

  for(int i = 0; i < numPlayers; i++){

  	
	string tempName = tempPlayers[i].getGamePieceName();
	QString qName = QString::fromStdString(tempName);

	playerIcons[i] = new QLabel(this);
	playerIcons[i]->setPixmap(QPixmap(qName));

	Coordinates tempLocation = tempPlayers[i].getPixelLocation();	

        if(numPlayers == 2) {
 	    playerIcons[i]->setGeometry(tempLocation.x + (i*22), tempLocation.y, 25, 25);
	} else if (numPlayers == 3) {
		if(i < 2){
	    		playerIcons[i]->setGeometry(tempLocation.x + (i*22), tempLocation.y, 25, 25);
		} else if (i == 2) {
			playerIcons[i]->setGeometry(tempLocation.x + (pieceCounter*22), tempLocation.y + (22), 25, 25);
		}

 	} else if (numPlayers == 4) {
		if (i < 2) {
			playerIcons[i]->setGeometry(tempLocation.x + (i*22), tempLocation.y, 25, 25);
		} else if (i >= 2 && i < 4) {
			playerIcons[i]->setGeometry(tempLocation.x + (pieceCounter*22), tempLocation.y + (22), 25, 25);
			pieceCounter++;
		}
	}

  	playerIcons[i]->setFixedWidth(25);
  	playerIcons[i]->setFixedHeight(25);
  	playerIcons[i]->setScaledContents(true);
  	playerIcons[i]->show();
  }
  

}

void CentralWidget::drawCard() {
  //draw card slot
}

void CentralWidget::movePieces(int playerNum, Coordinates tempCoordinates){
    
    Coordinates tempLocation = tempCoordinates;	

        if(playerNum == 0) {
 	    playerIcons[playerNum]->setGeometry(tempLocation.x, tempLocation.y, 25, 25);
	} else if (playerNum == 1){
	    playerIcons[playerNum]->setGeometry(tempLocation.x + (22), tempLocation.y, 25, 25);
	} else if (playerNum == 2) {
	    playerIcons[playerNum]->setGeometry(tempLocation.x, tempLocation.y + (22), 25, 25);
 	} else if (playerNum == 3) {
	    playerIcons[playerNum]->setGeometry(tempLocation.x + (22), tempLocation.y + (22), 25, 25);
	}
}

void CentralWidget::changeDiceImg(int rollNum1, int rollNum2){
    
    if(rollNum1 == 1) {
	dice1->setPixmap(QPixmap("./Dice/dice1.png"));
    } else if (rollNum1 == 2) {
	dice1->setPixmap(QPixmap("./Dice/dice2.png"));
    } else if (rollNum1 == 3) {
	dice1->setPixmap(QPixmap("./Dice/dice3.png"));
    } else if (rollNum1 == 4) {
	dice1->setPixmap(QPixmap("./Dice/dice4.png"));
    } else if (rollNum1 == 5) {
	dice1->setPixmap(QPixmap("./Dice/dice5.png"));
    } else if (rollNum1 == 6) {
	dice1->setPixmap(QPixmap("./Dice/dice6.png"));
    } 

    if(rollNum2 == 1) {
	dice2->setPixmap(QPixmap("./Dice/dice1.png"));
    } else if (rollNum2 == 2) {
	dice2->setPixmap(QPixmap("./Dice/dice2.png"));
    } else if (rollNum2 == 3) {
	dice2->setPixmap(QPixmap("./Dice/dice3.png"));
    } else if (rollNum2 == 4) {
	dice2->setPixmap(QPixmap("./Dice/dice4.png"));
    } else if (rollNum2 == 5) {
	dice2->setPixmap(QPixmap("./Dice/dice5.png"));
    } else if (rollNum2 == 6) {
	dice2->setPixmap(QPixmap("./Dice/dice6.png"));
    }
	
	
}

void CentralWidget::hidePiece(int playerNum){
	playerIcons[playerNum]->hide();
}

void CentralWidget::showCommunity(int cardNum){
	communityCover->hide();
	communityCards[cardNum]->show();
}

void CentralWidget::resetCommunity(int cardNum){
	communityCards[cardNum]->hide();
	communityCover->show();
}

void CentralWidget::showChance(int cardNum){
	chanceCover->hide();
	chanceCards[cardNum]->show();
}

void CentralWidget::resetChance(int cardNum){
	chanceCards[cardNum]->hide();
	chanceCover->show();
	
}

void CentralWidget::initializingCards(int tempArray[]){

  communityCards = new QLabel*[10];
  chanceCards = new QLabel*[10];
 

  //chance card 0
  chanceCards[tempArray[0]] = new QLabel(this);
  chanceCards[tempArray[0]]->setPixmap(QPixmap("./Chance/chance0.png"));
  chanceCards[tempArray[0]]->setGeometry(102, 102, 180, 100);
  chanceCards[tempArray[0]]->setFixedWidth(180);
  chanceCards[tempArray[0]]->setFixedHeight(100);
  chanceCards[tempArray[0]]->setScaledContents(true);
  chanceCards[tempArray[0]]->hide();
  
  //chance card 1
  chanceCards[tempArray[1]] = new QLabel(this);
  chanceCards[tempArray[1]]->setPixmap(QPixmap("./Chance/chance1.png"));
  chanceCards[tempArray[1]]->setGeometry(102, 102, 180, 100);
  chanceCards[tempArray[1]]->setFixedWidth(180);
  chanceCards[tempArray[1]]->setFixedHeight(100);
  chanceCards[tempArray[1]]->setScaledContents(true);
  chanceCards[tempArray[1]]->hide();

  //chance card 2
  chanceCards[tempArray[2]] = new QLabel(this);
  chanceCards[tempArray[2]]->setPixmap(QPixmap("./Chance/chance2.png"));
  chanceCards[tempArray[2]]->setGeometry(102, 102, 180, 100);
  chanceCards[tempArray[2]]->setFixedWidth(180);
  chanceCards[tempArray[2]]->setFixedHeight(100);
  chanceCards[tempArray[2]]->setScaledContents(true);
  chanceCards[tempArray[2]]->hide();
 
  //chance card 3
  chanceCards[tempArray[3]] = new QLabel(this);
  chanceCards[tempArray[3]]->setPixmap(QPixmap("./Chance/chance3.png"));
  chanceCards[tempArray[3]]->setGeometry(102, 102, 180, 100);
  chanceCards[tempArray[3]]->setFixedWidth(180);
  chanceCards[tempArray[3]]->setFixedHeight(100);
  chanceCards[tempArray[3]]->setScaledContents(true);
  chanceCards[tempArray[3]]->hide();

  //chance card 4
  chanceCards[tempArray[4]] = new QLabel(this);
  chanceCards[tempArray[4]]->setPixmap(QPixmap("./Chance/chance4.png"));
  chanceCards[tempArray[4]]->setGeometry(102, 102, 180, 100);
  chanceCards[tempArray[4]]->setFixedWidth(180);
  chanceCards[tempArray[4]]->setFixedHeight(100);
  chanceCards[tempArray[4]]->setScaledContents(true);
  chanceCards[tempArray[4]]->hide();

  //chance card 5
  chanceCards[tempArray[5]] = new QLabel(this);
  chanceCards[tempArray[5]]->setPixmap(QPixmap("./Chance/chance5.png"));
  chanceCards[tempArray[5]]->setGeometry(102, 102, 180, 100);
  chanceCards[tempArray[5]]->setFixedWidth(180);
  chanceCards[tempArray[5]]->setFixedHeight(100);
  chanceCards[tempArray[5]]->setScaledContents(true);
  chanceCards[tempArray[5]]->hide();

  //chance card 6
  chanceCards[tempArray[6]] = new QLabel(this);
  chanceCards[tempArray[6]]->setPixmap(QPixmap("./Chance/chance6.png"));
  chanceCards[tempArray[6]]->setGeometry(102, 102, 180, 100);
  chanceCards[tempArray[6]]->setFixedWidth(180);
  chanceCards[tempArray[6]]->setFixedHeight(100);
  chanceCards[tempArray[6]]->setScaledContents(true);
  chanceCards[tempArray[6]]->hide();

  //chance card 7
  chanceCards[tempArray[7]] = new QLabel(this);
  chanceCards[tempArray[7]]->setPixmap(QPixmap("./Chance/chance7.png"));
  chanceCards[tempArray[7]]->setGeometry(102, 102, 180, 100);
  chanceCards[tempArray[7]]->setFixedWidth(180);
  chanceCards[tempArray[7]]->setFixedHeight(100);
  chanceCards[tempArray[7]]->setScaledContents(true);
  chanceCards[tempArray[7]]->hide();

  //chance card 8
  chanceCards[tempArray[8]] = new QLabel(this);
  chanceCards[tempArray[8]]->setPixmap(QPixmap("./Chance/chance8.png"));
  chanceCards[tempArray[8]]->setGeometry(102, 102, 180, 100);
  chanceCards[tempArray[8]]->setFixedWidth(180);
  chanceCards[tempArray[8]]->setFixedHeight(100);
  chanceCards[tempArray[8]]->setScaledContents(true);
  chanceCards[tempArray[8]]->hide();

  //chance card 9
  chanceCards[tempArray[9]] = new QLabel(this);
  chanceCards[tempArray[9]]->setPixmap(QPixmap("./Chance/chance9.png"));
  chanceCards[tempArray[9]]->setGeometry(102, 102, 180, 100);
  chanceCards[tempArray[9]]->setFixedWidth(180);
  chanceCards[tempArray[9]]->setFixedHeight(100);
  chanceCards[tempArray[9]]->setScaledContents(true);
  chanceCards[tempArray[9]]->hide();

  //community card 0
  communityCards[tempArray[0]] = new QLabel(this);
  communityCards[tempArray[0]]->setPixmap(QPixmap("./Community Chest/community0.png"));
  communityCards[tempArray[0]]->setGeometry(366, 442, 180, 100);
  communityCards[tempArray[0]]->setFixedWidth(180);
  communityCards[tempArray[0]]->setFixedHeight(100);
  communityCards[tempArray[0]]->setScaledContents(true);
  communityCards[tempArray[0]]->hide();

  //community card 1
  communityCards[tempArray[1]] = new QLabel(this);
  communityCards[tempArray[1]]->setPixmap(QPixmap("./Community Chest/community1.png"));
  communityCards[tempArray[1]]->setGeometry(366, 442, 180, 100);
  communityCards[tempArray[1]]->setFixedWidth(180);
  communityCards[tempArray[1]]->setFixedHeight(100);
  communityCards[tempArray[1]]->setScaledContents(true);
  communityCards[tempArray[1]]->hide();

  //community card 2
  communityCards[tempArray[2]] = new QLabel(this);
  communityCards[tempArray[2]]->setPixmap(QPixmap("./Community Chest/community2.png"));
  communityCards[tempArray[2]]->setGeometry(366, 442, 180, 100);
  communityCards[tempArray[2]]->setFixedWidth(180);
  communityCards[tempArray[2]]->setFixedHeight(100);
  communityCards[tempArray[2]]->setScaledContents(true);
  communityCards[tempArray[2]]->hide();

  //community card 3
  communityCards[tempArray[3]] = new QLabel(this);
  communityCards[tempArray[3]]->setPixmap(QPixmap("./Community Chest/community3.png"));
  communityCards[tempArray[3]]->setGeometry(366, 442, 180, 100);
  communityCards[tempArray[3]]->setFixedWidth(180);
  communityCards[tempArray[3]]->setFixedHeight(100);
  communityCards[tempArray[3]]->setScaledContents(true);
  communityCards[tempArray[3]]->hide();
  
  //community card 4
  communityCards[tempArray[4]] = new QLabel(this);
  communityCards[tempArray[4]]->setPixmap(QPixmap("./Community Chest/community4.png"));
  communityCards[tempArray[4]]->setGeometry(366, 442, 180, 100);
  communityCards[tempArray[4]]->setFixedWidth(180);
  communityCards[tempArray[4]]->setFixedHeight(100);
  communityCards[tempArray[4]]->setScaledContents(true);
  communityCards[tempArray[4]]->hide();

  //community card 5
  communityCards[tempArray[5]] = new QLabel(this);
  communityCards[tempArray[5]]->setPixmap(QPixmap("./Community Chest/community5.png"));
  communityCards[tempArray[5]]->setGeometry(366, 442, 180, 100);
  communityCards[tempArray[5]]->setFixedWidth(180);
  communityCards[tempArray[5]]->setFixedHeight(100);
  communityCards[tempArray[5]]->setScaledContents(true);
  communityCards[tempArray[5]]->hide();

  //community card 6
  communityCards[tempArray[6]] = new QLabel(this);
  communityCards[tempArray[6]]->setPixmap(QPixmap("./Community Chest/community6.png"));
  communityCards[tempArray[6]]->setGeometry(366, 442, 180, 100);
  communityCards[tempArray[6]]->setFixedWidth(180);
  communityCards[tempArray[6]]->setFixedHeight(100);
  communityCards[tempArray[6]]->setScaledContents(true);
  communityCards[tempArray[6]]->hide();

  //community card 7
  communityCards[tempArray[7]] = new QLabel(this);
  communityCards[tempArray[7]]->setPixmap(QPixmap("./Community Chest/community7.png"));
  communityCards[tempArray[7]]->setGeometry(366, 442, 180, 100);
  communityCards[tempArray[7]]->setFixedWidth(180);
  communityCards[tempArray[7]]->setFixedHeight(100);
  communityCards[tempArray[7]]->setScaledContents(true);
  communityCards[tempArray[7]]->hide();

  //community card 8
  communityCards[tempArray[8]] = new QLabel(this);
  communityCards[tempArray[8]]->setPixmap(QPixmap("./Community Chest/community8.png"));
  communityCards[tempArray[8]]->setGeometry(366, 442, 180, 100);
  communityCards[tempArray[8]]->setFixedWidth(180);
  communityCards[tempArray[8]]->setFixedHeight(100);
  communityCards[tempArray[8]]->setScaledContents(true);
  communityCards[tempArray[8]]->hide();

  //community card 9
  communityCards[tempArray[9]] = new QLabel(this);
  communityCards[tempArray[9]]->setPixmap(QPixmap("./Community Chest/community9.png"));
  communityCards[tempArray[9]]->setGeometry(366, 442, 180, 100);
  communityCards[tempArray[9]]->setFixedWidth(180);
  communityCards[tempArray[9]]->setFixedHeight(100);
  communityCards[tempArray[9]]->setScaledContents(true);
  communityCards[tempArray[9]]->hide();
}



