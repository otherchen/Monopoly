#ifndef BANK_H
#define BANK_H

#include <string>

using namespace std;

class Bank {

	private:
	    int moneyAmount;

	public:
	    //constructors
	    Bank();	

	    //functions to get values
	    int getAmount();

	    //other functions
	    void give_money(int amount);
	    void take_money(int amount);	    

};
#endif
