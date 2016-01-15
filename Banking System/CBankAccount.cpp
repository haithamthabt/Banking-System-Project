// CBankAccount Implemintation File

#include <iostream>
#include <string>
#include "CBankAccount.h"

using namespace std;


// constructor function that set the initial balance to zero
CBankAccount::CBankAccount() {

	setBalance(0.0);

}

// setters ------------------------------
// set account number
void CBankAccount::setAccNum(string aN) {

	accNum = aN;

}

// set name
void CBankAccount::setName(string n) {

	name = n;

}

// set balance
void CBankAccount::setBalance(float b) {

	balance = b;

}

// getters ----------------------------

// get account number
string CBankAccount::getAccNum(){

	return accNum;
}

// get name 
string CBankAccount::getName() {

	return name;
}


// get balance
float CBankAccount::getBalance() {

	return balance;
}

//----------------------------------------------

// create an account function
void CBankAccount::createAccount(string accountNumber, string cstmrName) {

	// set account number
	setAccNum(accountNumber);

	//set account name
	setName(cstmrName);


}

// deposite money
void CBankAccount::depositMoney(float addAmount) {

	// add the amount to the current ballence
	addAmount = addAmount + getBalance();

	// change the balance with the new amount
	setBalance(addAmount);
	cout << "Your Account Balance after deposit is: $" << getBalance() << endl << endl;

}

// withdraw money
void CBankAccount::withdrawMoney(float subtractAmount) {


	// check if the balance is greater than or equal to the requested withdraw amount
	if (getBalance() >= subtractAmount) {

		subtractAmount = getBalance() - subtractAmount;
		setBalance(subtractAmount);

		cout << "Your Account Balance after withdraw is: $" << getBalance() << endl << endl;
	} else {

		cout << "Sorry! Cant process the withdraw because balance is less than requested withdraw amount " << endl << endl;
	}


} 


// check balance
float CBankAccount::checkBalance() {

	return getBalance();
}

// close account 
void CBankAccount::closeAccount() {


	// close bank account
}