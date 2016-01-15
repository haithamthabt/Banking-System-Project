// Purpose: To implement a seat reservation for a passenger airplane.
// Author's Name: Haitham Thab
// Creation Date: 10/07/2015
// Modification Date: 10/20/2015


#include <iostream>
#include <string>
#include "CBankAccount.h"
#include <windows.h> // this is used for the sleep code in the quit function


using namespace std;

// global variales
int numberOfAccounts = 0;
int userChoice;
int const MAX_LENGTH = 100;
CBankAccount  accounts[MAX_LENGTH];



void displayMenu(); // this functions displays the menu of options
void createAnAccount();
void CheckUserBalance();
void withDrawUserMoney();
void depositUserMoney();
void closeUserAccount();
void showList();
void displayHelp();
void quit();
int searchByAccNum(string accntNum);
void addDefaultAccounts(CBankAccount arr[]); // this function is just to add some default accounts to the list



int main() {





	do {

		displayMenu();
		switch (userChoice)
		{
		case 1:
			createAnAccount();
			break;
		case 2:
			CheckUserBalance();
			break;
		case 3:
			withDrawUserMoney();
			break;
		case 4:
			depositUserMoney();
			break;
		case 5:
			closeUserAccount();
			break;
		case 6:
			showList();
			break;
		case 7:
			displayHelp();
			break;
		case 8:
			quit();
			break;
		default:
			break;
		}

	} while (userChoice != 8);
	

	system("PAUSE");
	return 0;
}


// Purpose of the function: To display the menu options
// Author's Name: Haitham Thabt
// Creation Date: 10/07/2015
// Modification Date: 10/07/2015
void displayMenu() {
	cout << "---------------------------- Welcome To our Bank --------------------------" << endl;
	cout << "1. Create an Account" << endl;
	cout << "2. Check Balancet" << endl;
	cout << "3. WithDraw Amount" << endl;
	cout << "4. Deposit Amount" << endl;
	cout << "5. Close Account" << endl;
	cout << "6. Show All Account Holders List" << endl;
	cout << "7. Help" << endl;
	cout << "8. Quit" << endl;
	cout << "Please Enter You Choice (1-8): ";
	cin >> userChoice;
	cout << "-----------------------------------------------------------" << endl;
}

// Purpose of the function: To create an account for the user
// Author's Name: Haitham Thabt
// Creation Date: 10/07/2015
// Modification Date: 10/07/2015
void createAnAccount() {


	// check if there is avaliable place in the array for the new account
	if (numberOfAccounts < MAX_LENGTH ) {
		string accountNum;
		string cstmrName;
		float initialAmount;

		cout << endl << "   ---------- NEW ACCOUNT ENTRY FORM -------------" << endl << endl << endl;
		cout << "Pleae Enter account Number: ";
		cin >> accountNum;

		// check if the account number is already there
		if (searchByAccNum(accountNum) == -1) {

			cout << "Please Enter your Name: ";
			cin >> cstmrName;
			cout << "PLease enter initial amount: $";
			cin >> initialAmount;

			// add the information into the array
			accounts[numberOfAccounts].createAccount(accountNum, cstmrName);

			// add balance to the account
			accounts[numberOfAccounts].setBalance(initialAmount);


			cout << endl << endl << endl << "          Your account created successfully...";


			// increase the num of accounts
			numberOfAccounts++;

		} else {

			cout << "Sorry! Can't craete account. Account number is already in our system" << endl;

		}

		

	} else {

		cout << "Sorry! Can't create anymore accounts. The list is full";
	}
	

}


// Purpose of the function: To check the user's balance
// Author's Name: Haitham Thabt
// Creation Date: 10/07/2015
// Modification Date: 10/07/2015
void CheckUserBalance() {

	string userAccnt;

	cout << "------- Balance Details -------------" << endl << endl;
	cout << "Please enter your account number: ";
	cin >> userAccnt;
	// get the location of the account in the array
	int index = searchByAccNum(userAccnt);

	// display the balance if its located
	if (index != -1) {

		cout << "Hello, " << accounts[index].getName() << endl;
		cout << "Account Balance is: $" << accounts[index].checkBalance() << endl;

	} else {

		cout << "Can't locate Account number in our system" << endl;
	}
	
}

// Purpose of the function: To withdraw Money
// Author's Name: Haitham Thabt
// Creation Date: 10/07/2015
// Modification Date: 10/07/2015
void withDrawUserMoney() {

	string userAccnt;

	cout << "------- Withdraw Money -------------" << endl << endl;
	cout << "Please enter your account number: ";
	cin >> userAccnt;

	int index = searchByAccNum(userAccnt);

	// get the location of the account in the array
	if ( index != -1 ) {

		float amount;
		cout << "PLease Enter ammount: $";
		cin >> amount;
			
		accounts[index].withdrawMoney(amount);

	} else {

		cout << "Can't locate Account number in our system" << endl;
	}

}

// Purpose of the function: To Deposit Money
// Author's Name: Haitham Thabt
// Creation Date: 10/07/2015
// Modification Date: 10/07/2015
void depositUserMoney() {

	// deposit moeny
}

// Purpose of the function: To close an account
// Author's Name: Haitham Thabt
// Creation Date: 10/07/2015
// Modification Date: 10/07/2015
void closeUserAccount() {

	// close account
}


// Purpose of the function: To show the details of all the customers in a list
// Author's Name: Haitham Thabt
// Creation Date: 10/10/2015
// Modification Date: 10/10/2015
void showList() {

	cout << "                 All Accounts List" << endl << endl;
	cout << "======================================================" << endl;
	cout << "Accoun no.       Name               Balance" << endl;
	cout << "======================================================" << endl;
	for (int i = 0; i < numberOfAccounts; i++) {

		cout << accounts[i].getAccNum() << "       " << accounts[i].getName() << "               " << accounts[i].checkBalance() << endl;

	}
}


// Purpose of the function: To display a detailed message on how to use the system
// Author's Name: Haitham Thabt
// Creation Date: 10/15/2015
// Modification Date: 10/15/2015
void displayHelp() {

	cout << " Press a number between one and seven" << endl;
	cout << "Press 1 to display the seat chart" << endl
		<< "Press 2 to to reserve a seat. You need to enter seat number as (e.g., 3A, 7D, etc.) " << endl
		<< "Press 3 to to to cancel a seat. You need to enter seat number as (e.g., 3A, 7D, etc.)" << endl
		<< "Press 4 to to save the chart into a file. Enter file name with its extention as (e.g., file.txt, chart.txt, etc.)s " << endl
		<< "Press 5 to to display the following statistics: Number of available seats, percentage of seats that are reserved, list of window seats that are available, list of aisle seats that are available." << endl
		<< "Press 6 to to display help and a detailed message on how to use the program" << endl
		<< "Press 7 to quit and terminate the program" << endl;
}

// Purpose of the function: To display a thank you message and then terminates the program after 5 seconds
// Author's Name: Haitham Thabt
// Creation Date: 10/10/2015
// Modification Date: 10/10/2015
void quit() {

	cout << "Thank you for using our Bank";
	Sleep(5000); // to terminates after 5 seconds of choosing the quit option

}




// Purpose of the function: To search for a specific account num and returns the index
// Author's Name: Haitham Thabt
// Creation Date: 10/07/2015
// Modification Date: 10/07/2015
int searchByAccNum(string accntNum) {

	//searching Linear Search algoirthm
	for (int i = 0; i < numberOfAccounts; i++) {

		if (accounts[i].getAccNum() == accntNum) {

			return i;
		}

	}

	// if the accnt num is not in the list
	return -1;

}




// Purpose of the function: To add initial accounts to the list
// Author's Name: Haitham Thabt
// Creation Date: 10/07/2015
// Modification Date: 10/07/2015
void addDefaultAccounts(CBankAccount myArray[]) {
	/*

	// first customer
	myArray[0].createAccount("1235", "Haitham", numberOfAccounts);
	myArray[0].depositMoney(200.5);


	// second customer
	myArray[1].createAccount("1237", "Laila", numberOfAccounts);
	myArray[1].depositMoney(100);


	*/


}

