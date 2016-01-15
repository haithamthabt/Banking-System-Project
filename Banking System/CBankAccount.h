// CBankAccount Header File

#include <iostream>
#include <string>


using namespace std;

#ifndef CBankAccount_C
#define CBankAccount_C

// CLASS USED IN PROJECT
class CBankAccount {

	string accNum;
	string name;
	float balance;


public:
	CBankAccount(); // constructor function that set the initial balance to 
	void createAccount(string accountNumber, string cstmrName);
	void depositMoney(float amount); 
	void withdrawMoney(float amount);
	float checkBalance();
	void closeAccount();




	// setters 
	void setAccNum(string aN);
	void setName(string n);
	void setBalance(float b);


	// getters
	string getAccNum();
	string getName();
	float getBalance();


};

# endif

