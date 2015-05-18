#ifndef SPACE_H
#define SPACE_H

#include "action.h"


class Space {

	private:
	    string name[2];
	    string actionText[2];
	    string spaceType; //property, card, tax, railroads, jail, etc	    
	    int propertyCost;
  	    int freeParking;
	    bool occupied;
	    int owned;
	    bool mortgaged;	    
	    int houses;
	    int rent;
	    int tax;

	public:
	    //functions to set values
	    void setName(string inputName, string inputName2);
	    void setType(string inputType);
	    void setPropertyCost(int inputCost);
	    void setFreeParking(int inputMoney);
	    void setOccupied(int inputOccupied);
	    void setOwnership(int inputOwnership);
	    void setMortgaged(bool inputMortgage);
	    void setRent(int inputRent);
	    void setTax(int inputTax); 
	    void setActionText(string textInput, string textInput2);
	    void setHouses(int inputHouses);
	    bool upgrade();
	
	    //functions to get values
	    string getName(int nameIndex);
	    int getPropertyCost();
	    int getFreeParking();
	    bool getMortgaged();
	    int getRent();
	    int getTax();
	    int getOwnership();
	    string getActionText(int textIndex);
	    string getType();
	    int getHouses();	    
	
};
#endif

