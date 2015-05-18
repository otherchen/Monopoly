#include "guiplayers.h"

GUIPlayers::GUIPlayers(Player* p, int playerNum){
  
  player = p;
  stringstream ss;
  ownedProperties = new QPushButton*[40];
  ownedCount = 0;

  //player's number
  string tempNum;
  ss << (playerNum + 1);
  ss >> tempNum;
  tempNum = "Player " + tempNum; 
  ss.clear();
	
  QString qNum = QString::fromStdString(tempNum);
  numLabel = new QLabel( this );
  numLabel->setText( qNum );
  
  //player's money
  ss << player->getMoneyAmount();
  string tempMoney;
  ss >> tempMoney;
  tempMoney = ("$" + tempMoney);
  ss.clear();

  QString qMoney = QString::fromStdString(tempMoney);
  moneyLabel = new QLabel( this );
  moneyLabel->setText( qMoney );

  //player's game piece
  string tempPiece = player->getGamePieceName();
  QString qTempPiece = QString::fromStdString(tempPiece);
  gamePieceImg = new QLabel(this);
  gamePieceImg->setPixmap(qTempPiece);
  gamePieceImg->setFixedWidth(55);
  gamePieceImg->setFixedHeight(50);
  gamePieceImg->setScaledContents(true);

  //Adding all parts to layout
  layout = new QVBoxLayout;
  layout->addWidget(gamePieceImg);
  layout->addWidget(numLabel);
  layout->addWidget(moneyLabel);

  sideBar = new QWidget(this);
  sideBar->setLayout(layout);
  setWidget(sideBar);

  this->setMinimumSize(QSize(143, 650));
  this->setMaximumSize(QSize(143, 650));
}

GUIPlayers::GUIPlayers(){

}

void GUIPlayers::setMoneyText(){
  stringstream ss;
  ss << player->getMoneyAmount();
  string tempMoney;
  ss >> tempMoney;
  tempMoney = ("$" + tempMoney);
  ss.clear();

  QString qMoney = QString::fromStdString(tempMoney);
  moneyLabel->setText( qMoney );	
}

void GUIPlayers::addProperty(int propertyNum, string propertyName, Space** tempArray){

	QString tempName = QString::fromStdString(propertyName);
	QPushButton* newButton = new QPushButton(tempName);
	ownedProperties[ownedCount] = newButton;
	ownedProperties[ownedCount]->setEnabled(false);
        currentPropertyNum = propertyNum;
        allProperties[ownedCount] = propertyNum;

/*
	QSignalMapper* signalMapper = new QSignalMapper(this);

	for(int i = 0; i < ownedCount; i++){

	    connect(ownedProperties[ownedCount], SIGNAL(clicked(i)), this, SLOT(upgradeSpace(i)) );
	    
	    //connect (ownedProperties[i], SIGNAL(clicked()), signalMapper, SLOT(map()));
	    //signalMapper->setMapping(ownedProperties[i], i);
	    

                //connect(ownedProperties[i], SIGNAL(clicked()), this, SLOT(upgradeSpace()) );
	}
	//connect (signalMapper, SIGNAL(mapped(int)), this, SIGNAL(clicked(int)));
	//connect (signalMapper, SIGNAL(mapped(int)), this, SLOT(upgradeSpace(int)));
	
*/


	connect(ownedProperties[ownedCount], SIGNAL(clicked()), this, SLOT(upgradeSpace()) );




 
        
	layout->addWidget(ownedProperties[ownedCount]);
	sideBar->setLayout(layout);
	setWidget(sideBar);
	ownedCount++;

}

void GUIPlayers::enableUpgrade(){

	for( int i = 0; i < ownedCount; i++){
	    if(((player->getMoneyAmount() - allSpaces[allProperties[i]]->getPropertyCost()) <= 0) || !(allSpaces[allProperties[i]]->getType() == "Property")) {
		ownedProperties[i]->setEnabled(false);
	    } else {
		ownedProperties[i]->setEnabled(true);
	    }
	}

}

void GUIPlayers::disableUpgrade(){

	for( int i = 0; i < ownedCount; i++){
		ownedProperties[i]->setEnabled(false);
	}

}

void GUIPlayers::upgradeSpace(){
	bool isUpgraded;
	//int currentSpace = allProperties[num];
	isUpgraded = allSpaces[currentPropertyNum]->upgrade();
	
	if(isUpgraded == true){

		if((player->getMoneyAmount() - allSpaces[currentPropertyNum]->getPropertyCost()) <= 0) {
			   string text = "You do not have enough money to upgrade this property!";	    
            		   QString qText = QString::fromStdString(text);

            	 	   QMessageBox UpGradeLimit;
            		   UpGradeLimit.setText(qText);
            		   UpGradeLimit.exec(); 
		} else {
			   moneyAction.giveBank(player, bankPointer, allSpaces[currentPropertyNum]->getPropertyCost()); 
		}

		
	} else {
	    
	    string text = "Maximum (5) amount of upgrades reached for this property!";	    
            QString qText = QString::fromStdString(text);

            QMessageBox maxUpgrade;
            maxUpgrade.setText(qText);
            maxUpgrade.exec();
	}

	setMoneyText();
	disableUpgrade();

}

void GUIPlayers::setAllSpaces(Space** spaceArray){
	allSpaces = new Space*[40];
	allSpaces = spaceArray;
}

void GUIPlayers::setBank(Bank* tempBank){
	bankPointer = new Bank;
	bankPointer = tempBank;
}





