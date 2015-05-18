#ifndef BOTTOMBAR_H
#define BOTTOMBAR_H

#include <QtGui>
#include <QDockWidget>
#include <QPushButton>
#include <QGridLayout>
#include "guiplayers.h"
#include "centralwidget.h"
#include "money_action.h"
#include "bank.h"
#include "card.h"
#include "card_move.h"
#include "card_money.h"

class MainWindow;

class BottomBar : public QDockWidget {
  Q_OBJECT

  protected:
   
    QPushButton* rollButton;
    QPushButton* upgradeButton;
    QPushButton* purchaseButton;
    QPushButton* endTurnButton;
    QPushButton* player1Button;
    QPushButton* player2Button;
    QPushButton* player3Button;
    QPushButton* player4Button;
    QGridLayout* layout;
    QWidget* bottomWidget;
    int diceRoll1;
    int diceRoll2;
    Bank* bank;
    Player* freePark;
    MoneyAction moneyAction;
    Card** community;
    Card** chance;
    int newSpace;
    int oldSpace;
    int numAlive;
    int communityCount;
    int chanceCount;
    int index[10];

    //storing reference pointers
    GUIPlayers** allPlayers;
    CentralWidget* monopolyBoard;
    MainWindow* myWindow;
    int numberOfPlayers;
    int currentPlayerNum;

  private slots:
    //need to incorporate to make the buttons work

    void rollDice(); 
    void upgrade();
    void purchase();
    void endTurn();
    void seePlayer1();
    void seePlayer2();
    void seePlayer3();
    void seePlayer4();
   
  public:
    BottomBar();
    void setPlayers(int numberPlayers, GUIPlayers* tempPlayers[]);
    void setCentralWidget(CentralWidget* tempBoard);
    void setMainWindow(MainWindow* tempWindow);
    void disableButtons(int num);
    

};

#endif
