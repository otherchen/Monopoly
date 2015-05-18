#ifndef CENTRALWIDGET_H
#define CENTRALWIDGET_H

#include <QtGui>
#include "player.h"

class CentralWidget: public QWidget {
  Q_OBJECT

  private:
    QLabel* chanceCover;
    QLabel* communityCover;
    QLabel* boardLabel;
    QLabel* dice1;
    QLabel* dice2;
    QLabel** playerIcons;
    int numPlayers;
    QLabel** communityCards;
    QLabel** chanceCards;
    //Coordinates boardSpace[40];
    //QPixmap* cardFaceDown;
    //QPixmap* cardFaceUp;
    //bool isFaceDown;

  private slots:
    void drawCard();
  
 public:
    CentralWidget(int tempNum, Player* tempPlayers);
    void changeDiceImg(int rollNum1, int rollNum2);
    void movePieces(int playerNum, Coordinates tempCoordinates);
    void hidePiece(int playerNum);
    void showCommunity(int cardNum);
    void resetCommunity(int cardNum);
    void showChance(int cardNum);
    void resetChance(int cardNum);
    void initializingCards(int tempArray[]);

};

#endif
