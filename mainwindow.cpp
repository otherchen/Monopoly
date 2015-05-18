#include "mainwindow.h"

/**************     Primary constructor     ***************/
MainWindow::MainWindow(int numPlayers) {
  setFixedSize(800, 755);

  totalPlayers = numPlayers;
  playerTurn = 0;
  spaces = new Space*[40];

  //Creating the players!
  players = new Player[totalPlayers];
  if(totalPlayers == 2) {
	players[0].setPlayerName("Andrew");
	players[1].setPlayerName("Jacky");
  } else if (totalPlayers == 3){
	players[0].setPlayerName("Andrew");
	players[1].setPlayerName("Jacky");
	players[2].setPlayerName("Justin");
  } else if (totalPlayers == 4){
	players[0].setPlayerName("Andrew");
	players[1].setPlayerName("Jacky");
	players[2].setPlayerName("Justin");
	players[3].setPlayerName("Jason");
  }

  //setting up space locations on the board
  boardSpace[0].x = 594;
  boardSpace[0].y = 590;
  
  boardSpace[1].x = 513;
  boardSpace[1].y = 590;

  boardSpace[2].x = 462;
  boardSpace[2].y = 590;
  
  boardSpace[3].x = 408;
  boardSpace[3].y = 590;

  boardSpace[4].x = 356;
  boardSpace[4].y = 590;
  
  boardSpace[5].x = 304;
  boardSpace[5].y = 590;

  boardSpace[6].x = 252;
  boardSpace[6].y = 590;
  
  boardSpace[7].x = 199;
  boardSpace[7].y = 590;

  boardSpace[8].x = 145;
  boardSpace[8].y = 590;
  
  boardSpace[9].x = 94;
  boardSpace[9].y = 590;

  boardSpace[10].x = 13;
  boardSpace[10].y = 590;
  
  boardSpace[11].x = 13;
  boardSpace[11].y = 511;

  boardSpace[12].x = 13;
  boardSpace[12].y = 460;
  
  boardSpace[13].x = 13;
  boardSpace[13].y = 408;

  boardSpace[14].x = 13;
  boardSpace[14].y = 356;
  
  boardSpace[15].x = 13;
  boardSpace[15].y = 303;

  boardSpace[16].x = 13;
  boardSpace[16].y = 251;
  
  boardSpace[17].x = 13;
  boardSpace[17].y = 198;

  boardSpace[18].x = 13;
  boardSpace[18].y = 146;
  
  boardSpace[19].x = 13;
  boardSpace[19].y = 93;

  boardSpace[20].x = 13;
  boardSpace[20].y = 15;
  
  boardSpace[21].x = 95;
  boardSpace[21].y = 15;

  boardSpace[22].x = 146;
  boardSpace[22].y = 15;
  
  boardSpace[23].x = 198;
  boardSpace[23].y = 15;

  boardSpace[24].x = 250;
  boardSpace[24].y = 15;
  
  boardSpace[25].x = 303;
  boardSpace[25].y = 15;

  boardSpace[26].x = 356;
  boardSpace[26].y = 15;
  
  boardSpace[27].x = 408;
  boardSpace[27].y = 15;

  boardSpace[28].x = 460;
  boardSpace[28].y = 15;
  
  boardSpace[29].x = 514;
  boardSpace[29].y = 15;

  boardSpace[30].x = 594;
  boardSpace[30].y = 15;
  
  boardSpace[31].x = 594;
  boardSpace[31].y = 93;

  boardSpace[32].x = 594;
  boardSpace[32].y = 145;
  
  boardSpace[33].x = 594;
  boardSpace[33].y = 197;

  boardSpace[34].x = 594;
  boardSpace[34].y = 249;
  
  boardSpace[35].x = 594;
  boardSpace[35].y = 302;

  boardSpace[36].x = 594;
  boardSpace[36].y = 354;
  
  boardSpace[37].x = 594;
  boardSpace[37].y = 407;

  boardSpace[38].x = 594;
  boardSpace[38].y = 459;
  
  boardSpace[39].x = 594;
  boardSpace[39].y = 511;

  //Use functions in Space class to initialize each space

	for( int i = 0; i < 40; i++){
		spaces[i] = new Space;
	}
	
	//Space 0
	spaces[0]->setName("   GO!   ", "         ");
	spaces[0]->setType("START");
	spaces[0]->setPropertyCost(0);
	spaces[0]->setFreeParking(0);
	spaces[0]->setOccupied(true);
	spaces[0]->setOwnership(-1);
	spaces[0]->setMortgaged(false);
	spaces[0]->setRent(0);
	spaces[0]->setTax(0);
	spaces[0]->setActionText("Pass Go! ", "Get $200 ");

	//Space 1
	spaces[1]->setName("  Dorm   ", "  Room   ");
	spaces[1]->setType("Property");
	spaces[1]->setPropertyCost(60);
	spaces[1]->setFreeParking(0);
	spaces[1]->setOccupied(false);
	spaces[1]->setOwnership(-1);
	spaces[1]->setMortgaged(false);
	spaces[1]->setRent(2);
	spaces[1]->setTax(0);
	spaces[1]->setActionText("         ", "   $60   ");

	//Space 2
	spaces[2]->setName("Community", "  Chest  ");
	spaces[2]->setType("Community Chest");
	spaces[2]->setPropertyCost(0);
	spaces[2]->setFreeParking(0);
	spaces[2]->setOccupied(false);
	spaces[2]->setOwnership(-1);
	spaces[2]->setMortgaged(false);
	spaces[2]->setRent(0);
	spaces[2]->setTax(0);
	spaces[2]->setActionText(" Draw a  " ,"  Card   ");

	//Space 3
	spaces[3]->setName(" Leavey  ", " Library ");
	spaces[3]->setType("Property");
	spaces[3]->setPropertyCost(70);
	spaces[3]->setFreeParking(0);
	spaces[3]->setOccupied(false);
	spaces[3]->setOwnership(-1);
	spaces[3]->setMortgaged(false);
	spaces[3]->setRent(4);
	spaces[3]->setTax(0);
	spaces[3]->setActionText("         ", "   $60   ");
	

	//Space 4
	spaces[4]->setName(" College ", " Tuition ");
	spaces[4]->setType("Tax");
	spaces[4]->setPropertyCost(70);
	spaces[4]->setFreeParking(0);
	spaces[4]->setOccupied(false);
	spaces[4]->setOwnership(-1);
	spaces[4]->setMortgaged(false);
	spaces[4]->setRent(4);
	spaces[4]->setTax(200);
	spaces[4]->setActionText("         ", "Pay $200 ");

	//Space 5
	spaces[5]->setName(" Campus  ", " Cruiser ");
	spaces[5]->setType("RailRoad");
	spaces[5]->setPropertyCost(200);
	spaces[5]->setFreeParking(0);
	spaces[5]->setOccupied(false);
	spaces[5]->setOwnership(-1);
	spaces[5]->setMortgaged(false);
	spaces[5]->setRent(25);
	spaces[5]->setTax(0);
	spaces[5]->setActionText("         ", "  $200   ");

	//Space 6
	spaces[6]->setName(" Trojan  ", "  Hall   ");
	spaces[6]->setType("Property");
	spaces[6]->setPropertyCost(100);
	spaces[6]->setFreeParking(0);
	spaces[6]->setOccupied(false);
	spaces[6]->setOwnership(-1);
	spaces[6]->setMortgaged(false);
	spaces[6]->setRent(6);
	spaces[6]->setTax(0);
	spaces[6]->setActionText("         ", "  $100   ");
	
	//Space 7
	spaces[7]->setName(" Chance  ", "         ");
	spaces[7]->setType("Chance");
	spaces[7]->setPropertyCost(0);
	spaces[7]->setFreeParking(0);
	spaces[7]->setOccupied(false);
	spaces[7]->setOwnership(-1);
	spaces[7]->setMortgaged(false);
	spaces[7]->setRent(0);
	spaces[7]->setTax(0);
	spaces[7]->setActionText(" Draw a  ", "  card   ");

	//Space 8
	spaces[8]->setName("  Marks  ", "  Tower  ");
	spaces[8]->setType("Property");
	spaces[8]->setPropertyCost(100);
	spaces[8]->setFreeParking(0);
	spaces[8]->setOccupied(false);
	spaces[8]->setOwnership(-1);
	spaces[8]->setMortgaged(false);
	spaces[8]->setRent(6);
	spaces[8]->setTax(0);
	spaces[8]->setActionText("         ", "  $100   ");

	//Space 9
	spaces[9]->setName(" Pardee  ", " Tower   ");
	spaces[9]->setType("Property");
	spaces[9]->setPropertyCost(120);
	spaces[9]->setFreeParking(0);
	spaces[9]->setOccupied(false);
	spaces[9]->setOwnership(-1);
	spaces[9]->setMortgaged(false);
	spaces[9]->setRent(8);
	spaces[9]->setTax(0);
	spaces[9]->setActionText("         ", "  $120   ");


	//Space 10
	spaces[10]->setName(" SJACS!  ", "         ");
	spaces[10]->setType("Jail");
	spaces[10]->setPropertyCost(0);
	spaces[10]->setFreeParking(0);
	spaces[10]->setOccupied(false);
	spaces[10]->setOwnership(-1);
	spaces[10]->setMortgaged(false);
	spaces[10]->setRent(0);
	spaces[10]->setTax(0);
	spaces[10]->setActionText("  Just   ", "Visiting ");

	//Space 11
	spaces[11]->setName(" Silent  ", " Chapel  ");
	spaces[11]->setType("Property");
	spaces[11]->setPropertyCost(140);
	spaces[11]->setFreeParking(0);
	spaces[11]->setOccupied(false);
	spaces[11]->setOwnership(-1);
	spaces[11]->setMortgaged(false);
	spaces[11]->setRent(10);
	spaces[11]->setTax(0);
	spaces[11]->setActionText("         ", "  $140   ");

	//Space 12
	spaces[12]->setName("Bathroom ", "Janitors ");
	spaces[12]->setType("Utility");
	spaces[12]->setPropertyCost(150);
	spaces[12]->setFreeParking(0);
	spaces[12]->setOccupied(false);
	spaces[12]->setOwnership(-1);
	spaces[12]->setMortgaged(false);
	spaces[12]->setRent(10);
	spaces[12]->setTax(0);
	spaces[12]->setActionText("         ", "  $150   ");


	//Space 13
	spaces[13]->setName("McCarthy ", "  Quad   ");
	spaces[13]->setType("Property");
	spaces[13]->setPropertyCost(140);
	spaces[13]->setFreeParking(0);
	spaces[13]->setOccupied(false);
	spaces[13]->setOwnership(-1);
	spaces[13]->setMortgaged(false);
	spaces[13]->setRent(10);
	spaces[13]->setTax(0);
	spaces[13]->setActionText("         ", "  $140   ");

	//Space 14
	spaces[14]->setName(" Alumni  ", " House   ");
	spaces[14]->setType("Property");
	spaces[14]->setPropertyCost(160);
	spaces[14]->setFreeParking(0);
	spaces[14]->setOccupied(false);
	spaces[14]->setOwnership(-1);
	spaces[14]->setMortgaged(false);
	spaces[14]->setRent(12);
	spaces[14]->setTax(0);
	spaces[14]->setActionText("         ", "  $160   ");

	//Space 15
	spaces[15]->setName("LA Metro ", "         ");
	spaces[15]->setType("RailRoad");
	spaces[15]->setPropertyCost(200);
	spaces[15]->setFreeParking(0);
	spaces[15]->setOccupied(false);
	spaces[15]->setOwnership(-1);
	spaces[15]->setMortgaged(false);
	spaces[15]->setRent(25);
	spaces[15]->setTax(0);
	spaces[15]->setActionText("         ", "  $200   ");

	//Space 16
	spaces[16]->setName("  Fluor  ", "  Tower  ");
	spaces[16]->setType("Property");
	spaces[16]->setPropertyCost(180);
	spaces[16]->setFreeParking(0);
	spaces[16]->setOccupied(false);
	spaces[16]->setOwnership(-1);
	spaces[16]->setMortgaged(false);
	spaces[16]->setRent(14);
	spaces[16]->setTax(0);
	spaces[16]->setActionText("         ", "  $180   ");

	//Space 17
	spaces[17]->setName("Community", "  Chest  ");
	spaces[17]->setType("Community Chest");
	spaces[17]->setPropertyCost(0);
	spaces[17]->setFreeParking(0);
	spaces[17]->setOccupied(false);
	spaces[17]->setOwnership(-1);
	spaces[17]->setMortgaged(false);
	spaces[17]->setRent(0);
	spaces[17]->setTax(0);
	spaces[17]->setActionText(" Draw a  ", "  Card   ");

	//Space 18
	spaces[18]->setName("  Webb   ", "  Tower  ");
	spaces[18]->setType("Property");
	spaces[18]->setPropertyCost(180);
	spaces[18]->setFreeParking(0);
	spaces[18]->setOccupied(false);
	spaces[18]->setOwnership(-1);
	spaces[18]->setMortgaged(false);
	spaces[18]->setRent(14);
	spaces[18]->setTax(0);
	spaces[18]->setActionText("         ", "  $180   ");

	//Space 19
	spaces[19]->setName("  Lyon   ", " Center  ");
	spaces[19]->setType("Property");
	spaces[19]->setPropertyCost(200);
	spaces[19]->setFreeParking(0);
	spaces[19]->setOccupied(false);
	spaces[19]->setOwnership(-1);
	spaces[19]->setMortgaged(false);
	spaces[19]->setRent(16);
	spaces[19]->setTax(0);
	spaces[19]->setActionText("         ", "  $200   ");

	//Space 20
	spaces[20]->setName("Financial", "   Aid   ");
	spaces[20]->setType("FreeParking");
	spaces[20]->setPropertyCost(0);
	spaces[20]->setFreeParking(0);
	spaces[20]->setOccupied(false);
	spaces[20]->setOwnership(-1);
	spaces[20]->setMortgaged(false);
	spaces[20]->setRent(0);
	spaces[20]->setTax(0);
	spaces[20]->setActionText("         ", "         ");

	//Space 21
	spaces[21]->setName(" George  ", "Tirebiter");
	spaces[21]->setType("Property");
	spaces[21]->setPropertyCost(220);
	spaces[21]->setFreeParking(0);
	spaces[21]->setOccupied(false);
	spaces[21]->setOwnership(-1);
	spaces[21]->setMortgaged(false);
	spaces[21]->setRent(18);
	spaces[21]->setTax(0);
	spaces[21]->setActionText("         ", "  $220   ");

	//Space 22
	spaces[22]->setName(" Chance  ", "         ");
	spaces[22]->setType("Chance");
	spaces[22]->setPropertyCost(0);
	spaces[22]->setFreeParking(0);
	spaces[22]->setOccupied(false);
	spaces[22]->setOwnership(-1);
	spaces[22]->setMortgaged(false);
	spaces[22]->setRent(0);
	spaces[22]->setTax(0);
	spaces[22]->setActionText(" Draw a  ", "  Card   ");

	//Space 23
	spaces[23]->setName("Traveller", " Statue  ");
	spaces[23]->setType("Property");
	spaces[23]->setPropertyCost(220);
	spaces[23]->setFreeParking(0);
	spaces[23]->setOccupied(false);
	spaces[23]->setOwnership(-1);
	spaces[23]->setMortgaged(false);
	spaces[23]->setRent(18);
	spaces[23]->setTax(0);
	spaces[23]->setActionText("         ", "  $220   ");

	//Space 24
	spaces[24]->setName("Knight's ", " Bench   ");
	spaces[24]->setType("Property");
	spaces[24]->setPropertyCost(240);
	spaces[24]->setFreeParking(0);
	spaces[24]->setOccupied(false);
	spaces[24]->setOwnership(-1);
	spaces[24]->setMortgaged(false);
	spaces[24]->setRent(20);
	spaces[24]->setTax(0);
	spaces[24]->setActionText("         ", "  $240   ");

	//Space 25
	spaces[25]->setName("Lyft App ", "         ");
	spaces[25]->setType("RailRoad");
	spaces[25]->setPropertyCost(200);
	spaces[25]->setFreeParking(0);
	spaces[25]->setOccupied(false);
	spaces[25]->setOwnership(-1);
	spaces[25]->setMortgaged(false);
	spaces[25]->setRent(25);
	spaces[25]->setTax(0);
	spaces[25]->setActionText("         ", "  $200   ");

	//Space 26
	spaces[26]->setName("Cromwell ", "  Field  ");
	spaces[26]->setType("Property");
	spaces[26]->setPropertyCost(260);
	spaces[26]->setFreeParking(0);
	spaces[26]->setOccupied(false);
	spaces[26]->setOwnership(-1);
	spaces[26]->setMortgaged(false);
	spaces[26]->setRent(22);
	spaces[26]->setTax(0);
	spaces[26]->setActionText("         ", "  $260   ");

	//Space 27
	spaces[27]->setName(" V.K.C.  ", "Carillon ");
	spaces[27]->setType("Property");
	spaces[27]->setPropertyCost(260);
	spaces[27]->setFreeParking(0);
	spaces[27]->setOccupied(false);
	spaces[27]->setOwnership(-1);
	spaces[27]->setMortgaged(false);
	spaces[27]->setRent(22);
	spaces[27]->setTax(0);
	spaces[27]->setActionText("         ", "  $260   ");

	//Space 28
	spaces[28]->setName(" Laundry ", " Company ");
	spaces[28]->setType("Utility");
	spaces[28]->setPropertyCost(150);
	spaces[28]->setFreeParking(0);
	spaces[28]->setOccupied(false);
	spaces[28]->setOwnership(-1);
	spaces[28]->setMortgaged(false);
	spaces[28]->setRent(10);
	spaces[28]->setTax(0);
	spaces[28]->setActionText("         ", "  $150   ");

	//Space 29
	spaces[29]->setName(" Gallen  ", " Center  ");
	spaces[29]->setType("Property");
	spaces[29]->setPropertyCost(280);
	spaces[29]->setFreeParking(0);
	spaces[29]->setOccupied(false);
	spaces[29]->setOwnership(-1);
	spaces[29]->setMortgaged(false);
	spaces[29]->setRent(22);
	spaces[29]->setTax(0);
	spaces[29]->setActionText("         ", "  $280   ");

	//Space 30
	spaces[30]->setName("Caught by", " D.P.S.  ");
	spaces[30]->setType("GoJail");
	spaces[30]->setPropertyCost(0);
	spaces[30]->setFreeParking(0);
	spaces[30]->setOccupied(false);
	spaces[30]->setOwnership(-1);
	spaces[30]->setMortgaged(false);
	spaces[30]->setRent(0);
	spaces[30]->setTax(0);
	spaces[30]->setActionText("         ", "         ");

	//Space 31
	spaces[31]->setName("Heritage ", "  Hall   ");
	spaces[31]->setType("Property");
	spaces[31]->setPropertyCost(300);
	spaces[31]->setFreeParking(0);
	spaces[31]->setOccupied(false);
	spaces[31]->setOwnership(-1);
	spaces[31]->setMortgaged(false);
	spaces[31]->setRent(26);
	spaces[31]->setTax(0);
	spaces[31]->setActionText("         ", "  $300   ");

	//Space 32
	spaces[32]->setName("  McKay  ", " Center  ");
	spaces[32]->setType("Property");
	spaces[32]->setPropertyCost(300);
	spaces[32]->setFreeParking(0);
	spaces[32]->setOccupied(false);
	spaces[32]->setOwnership(-1);
	spaces[32]->setMortgaged(false);
	spaces[32]->setRent(26);
	spaces[32]->setTax(0);
	spaces[32]->setActionText("         ", "  $300   ");

	//Space 33
	spaces[33]->setName("Community", "  Chest  ");
	spaces[33]->setType("Community Chest");
	spaces[33]->setPropertyCost(0);
	spaces[33]->setFreeParking(0);
	spaces[33]->setOccupied(false);
	spaces[33]->setOwnership(-1);
	spaces[33]->setMortgaged(false);
	spaces[33]->setRent(0);
	spaces[33]->setTax(0);
	spaces[33]->setActionText(" Draw a  ", "  Card   ");

	//Space 34
	spaces[34]->setName(" Bovard  ", " Stage   ");
	spaces[34]->setType("Property");
	spaces[34]->setPropertyCost(320);
	spaces[34]->setFreeParking(0);
	spaces[34]->setOccupied(false);
	spaces[34]->setOwnership(-1);
	spaces[34]->setMortgaged(false);
	spaces[34]->setRent(28);
	spaces[34]->setTax(0);
	spaces[34]->setActionText("         ", "  $320   ");

	//Space 35
	spaces[35]->setName("   USC   ", " Shuttle ");
	spaces[35]->setType("RailRoad");
	spaces[35]->setPropertyCost(200);
	spaces[35]->setFreeParking(0);
	spaces[35]->setOccupied(false);
	spaces[35]->setOwnership(-1);
	spaces[35]->setMortgaged(false);
	spaces[35]->setRent(25);
	spaces[35]->setTax(0);
	spaces[35]->setActionText("         ", "  $200   ");

	//Space 36
	spaces[36]->setName(" Chance  ", "         ");
	spaces[36]->setType("Chance");
	spaces[36]->setPropertyCost(0);
	spaces[36]->setFreeParking(0);
	spaces[36]->setOccupied(false);
	spaces[36]->setOwnership(-1);
	spaces[36]->setMortgaged(false);
	spaces[36]->setRent(0);
	spaces[36]->setTax(0);
	spaces[36]->setActionText(" Draw a  ", "  Card   ");

	//Space 37
	spaces[37]->setName(" Trojan  ", " Shrine  ");
	spaces[37]->setType("Property");
	spaces[37]->setPropertyCost(350);
	spaces[37]->setFreeParking(0);
	spaces[37]->setOccupied(false);
	spaces[37]->setOwnership(-1);
	spaces[37]->setMortgaged(false);
	spaces[37]->setRent(35);
	spaces[37]->setTax(0);
	spaces[37]->setActionText("         ", "  $350   ");

	//Space 38
	spaces[38]->setName("Textbook ", "  Fees   "); 
	spaces[38]->setType("Tax");
	spaces[38]->setPropertyCost(0);
	spaces[38]->setFreeParking(0);
	spaces[38]->setOccupied(false);
	spaces[38]->setOwnership(-1);
	spaces[38]->setMortgaged(false);
	spaces[38]->setRent(0);
	spaces[38]->setTax(75);
	spaces[38]->setActionText("         ", " Pay $75 ");

	//Space 39
	spaces[39]->setName("Football ", "Coliseum ");
	spaces[39]->setType("Property");
	spaces[39]->setPropertyCost(400);
	spaces[39]->setFreeParking(0);
	spaces[39]->setOccupied(false);
	spaces[39]->setOwnership(-1);
	spaces[39]->setMortgaged(false);
	spaces[39]->setRent(50);
	spaces[39]->setTax(0);
	spaces[39]->setActionText("         ", "  $400   ");       
	
	for(int i = 0; i < 40; i++){
	    spaces[i]->setHouses(0);
	}


}

//Secondary constructor
MainWindow::MainWindow(){ }

/***********     Setting up the entire window     ************/
void MainWindow::windowSetUp(){

  //Displaying GUIPlayers
  for(int i = 0; i < 4; i++){ 
	guiPlayers[i] = NULL;
  }

  for(int i = 0; i < totalPlayers; i++){
	guiPlayers[i] = new GUIPlayers(&players[i], i);
	guiPlayers[i]->setFeatures(QDockWidget::NoDockWidgetFeatures);
	guiPlayers[i]->setAllSpaces(spaces);
  }

  addDockWidget( Qt::RightDockWidgetArea, guiPlayers[0]);

  //Displaying the board in the central widget
  centralWidget = new CentralWidget(totalPlayers, players);
  setCentralWidget( centralWidget );

  //Displaying the Bottom Button bar
  bottomBar = new BottomBar();
  bottomBar->setPlayers(totalPlayers, guiPlayers);
  bottomBar->setCentralWidget(centralWidget);
  bottomBar->setMainWindow(this);

  if(totalPlayers == 2){
	bottomBar->disableButtons(2);
  } else if (totalPlayers == 3){
	bottomBar->disableButtons(1);
  }

  bottomBar->setFeatures(QDockWidget::NoDockWidgetFeatures);
  addDockWidget( Qt::BottomDockWidgetArea, bottomBar );

  //Create numPlayers of QLabels in central widget,
  //save images, and display the players on the board

}


/************     Rest of Regular Functions     ************/

//assigning game pieces to players
void MainWindow::setGamePiece(int playerNum, string pieceName){
	players[playerNum].setGamePieceName(pieceName);
}


//incrimenting turn
void MainWindow::nextTurn(){

	if(playerTurn == (totalPlayers - 1)) {
		playerTurn = 0;
		
	} else {
	        playerTurn++;
	}

} 
 
//getting player's turn   
int MainWindow::getPlayerTurn(){
	return playerTurn;
}

string MainWindow::getGamePiece(int playerNum){
	return players[playerNum].getGamePieceName();
}

void MainWindow::setPlayerLocation(int playerNum, int spaceNum){
	players[playerNum].setLocation(spaceNum);
        players[playerNum].setPixelLocation(boardSpace[spaceNum]);
}

int MainWindow::getPlayerLocation(int playerNum){
	return players[playerNum].getLocation();
}


Coordinates MainWindow::getPlayerPixels(int playerNum){
	return players[playerNum].getPixelLocation();
}

int MainWindow::getSpaceOwnership(int spaceIndex){
	return spaces[spaceIndex]->getOwnership();
}

string MainWindow::spaceType(int inputIndex){
	return spaces[inputIndex]->getType();
}

Player* MainWindow::getPlayer(int num){
	return &players[num];
}

string MainWindow::getPlayerName(int playerNum){
	return players[playerNum].getPlayerName();
}

int MainWindow::getSpaceRent(int spaceIndex){
	return spaces[spaceIndex]->getRent();
}

int MainWindow::getPlayerMoney(int playerNum){
	return players[playerNum].getMoneyAmount();
}

int MainWindow::getSpacePropertyCost(int spaceIndex){
	return spaces[spaceIndex]->getPropertyCost();
}


void MainWindow::setSpaceOwnership(int spaceIndex, int playerNum){
	spaces[spaceIndex]->setOwnership(playerNum);
}

void MainWindow::playerLost(int playerNum){
	players[playerNum].reset();
}

bool MainWindow::isPlayerAlive(int playerNum){
	return players[playerNum].isAlive();
}

int MainWindow::getSpaceTax(int spaceIndex){
	return spaces[spaceIndex]->getTax();
}

string MainWindow::getSpaceName(int spaceIndex, int index){
	return spaces[spaceIndex]->getName(index);
}

Space** MainWindow::getAllSpaces(){
	return spaces;
}














