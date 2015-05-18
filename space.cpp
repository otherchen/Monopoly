#include "space.h"
#include <iostream>

//functions to set values
void Space::setName(string inputName, string inputName2){
	name[0] = inputName;
	name[1] = inputName2;
	houses = 0;
}

void Space::setActionText(string inputText, string inputText2){
	actionText[0] = inputText;
	actionText[1] = inputText2;
	houses = 0;
}

void Space::setType(string inputType){
	spaceType = inputType;
}

void Space::setPropertyCost(int inputCost){
	propertyCost = inputCost;
}

void Space::setFreeParking(int inputMoney){
	freeParking = inputMoney;
}

void Space::setOccupied(int inputOccupied){
	occupied = inputOccupied;
}

void Space::setOwnership(int inputOwnership){
	owned = inputOwnership;
}

void Space::setMortgaged(bool inputMortgage){
	mortgaged = inputMortgage;
}

void Space::setRent(int inputRent){
	rent = inputRent;
}

void Space::setTax(int inputTax){
	tax = inputTax;
}
	
//functions to get values
string Space::getName(int nameIndex){
	return name[nameIndex];
}

string Space::getActionText(int textIndex){
	return actionText[textIndex];
}

int Space::getPropertyCost(){
	return propertyCost;
}

int Space::getFreeParking(){
	return freeParking;
}

bool Space::getMortgaged(){
	return mortgaged;
}

int Space::getRent(){
	return rent;
}

int Space::getTax(){
	return tax;
}

string Space::getType(){
	return spaceType;
}

int Space::getOwnership(){
	return owned;
}

int Space::getHouses(){
	return houses;
}

void Space::setHouses(int inputHouses){
	houses = inputHouses;
}

bool Space::upgrade(){
	if(houses < 5){
	    rent = rent * 2;
	    houses++;
	    return true;
	} else {
	    return false;
	}
}
