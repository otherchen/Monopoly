#ifndef GUIPLAYERS_H
#define GUIPLAYERS_H

#include "player.h"
#include <QtGui>
#include <QDockWidget>
#include <string>
#include <sstream>
#include <QVBoxLayout>
#include "space.h"
#include "money_action.h"
#include "bank.h"
#include <QSignalMapper>


class GUIPlayers : public QDockWidget {
  Q_OBJECT

  protected:
    Player* player;
    QLabel *numLabel;
    QLabel *moneyLabel;
    QVBoxLayout* layout;
    QWidget* sideBar;
    QLabel* gamePieceImg;
    QPushButton** ownedProperties;
    int currentPropertyNum;
    int allProperties[40];
    int ownedCount;
    Space** allSpaces;
    MoneyAction moneyAction;
    Bank* bankPointer;

  private slots:
    void upgradeSpace();

  public:
    GUIPlayers(Player* p, int playerNum);
    GUIPlayers();
    void setMoneyText();
    void addProperty(int propertyNum, string propertyName, Space** spaceArray);
    void enableUpgrade();
    void disableUpgrade();
    void setAllSpaces(Space** spaceArray);
    void setBank(Bank* tempBank);

};

#endif
