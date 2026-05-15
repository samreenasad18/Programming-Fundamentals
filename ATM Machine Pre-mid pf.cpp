#include<iostream>
using namespace std;
int main()
{
	cout << " WELCOME TO ATM " << endl;
	// INITIALIZATION
	int attempts = 3, pin, correct_pin = 1234, max_balance = 1000000, choice,
		last_transaction = 0;
	int deposit, balance = 10000, withdraw;
	//  PIN VERIFICATION
	while (attempts > 0) {
		cout << " ENTER PIN = " << endl;
		cin >> pin;

		if (pin == correct_pin)
		{
			cout << " ACCESS IS GRANTED " << endl;
			
			//CHOICES
			do {
				cout << " CHOOSE ONE OF THEM " << endl;
				cout << " 1.CHECK BALANCE" << endl;
				cout << "2.DEPOIST MONEY" << endl;
				cout << "3.WITHDRAW MONEY" << endl;
				cout << "4.MINI STATEMENT" << endl;
				cout << "5.EXIT" << endl;
				cout << "ENTER YOUR CHOICE: " << endl;
				cin >> choice;

				switch (choice)
				{
				case 1: //BALANCE
					cout << "YOUR CURRENT BALANCE IS : " << balance << endl;
					break;
				case 2: //DEPOSIT AMOUNT
				{
					cout << " DEPOSIT YOUR AMOUNT : " << endl;
					cin >> deposit;
					if (deposit > max_balance) {
						cout << " ERROR OCCURRED!! , ENTERED VALUE IS TO LARGE" << endl;
					}
					else if(deposit<0){
						cout << " ERROR OCCURRED!! , INVALID AMOUNT" << endl;	
					}
					else {
						balance = balance + deposit;
						last_transaction = deposit;
						cout << " AMOUNT DEPOSITED , CURRENT BALANCE IS: " << balance << endl;
					}
					break;
				}
				case 3:// WITHDRAW AMOUNT 
				{
					cout << " WITHDRAW YOUR AMOUNT: " << endl;
					cin >> withdraw;
					if (withdraw > 0 && withdraw <= balance) {
						balance = balance - withdraw;
						last_transaction = -withdraw;
						cout << " WITHDRAW DONE " << balance << endl;
					}
					else {
						cout << " INSUFFIENT FUNDS!! " << endl;
					}
					break;
				}
				case 4: //MINI STATEMENT
				{
					cout << " MINI STATEMENT " << endl;
					if (last_transaction > 0) {
						cout << " LAST TRANSACTION DEPOSITED " <<last_transaction<< endl;
						cout << " balance before postfix= " << balance++;
						cout << " balance after postfix= " << balance << endl;
						balance--;
					}
					else if (last_transaction < 0) {
						cout << " LAST TRANSACTION WITHDREW " << -last_transaction << endl;
						cout << " balance before prefix= " << balance << endl;
						cout << " balance after prefix= " << ++balance << endl;
						balance--;
					}
					else {
						cout << " THERE IS NO TRANSACTION YET " << endl;
					}
					break;
				}
				case 5: // EXIT
					cout << " GOODBYE!!\n THANK YOU FOR USING ATM " << endl;
					break;
				default:
					cout << " INVALID CHOICE , CHOOSE AGAIN!" << endl;
				}

			} while (choice != 5);
		}
		else
		{
			attempts--;
			cout << " ACCESS IS DENIED " <<attempts<<endl;
			cin >> pin;
		}
	}
	if (attempts == 0)
	{
		cout << " ACCOUNT IS LOCKED. PLEASE TRY AGAIN LATER" << endl;
	}





	return 0;
}