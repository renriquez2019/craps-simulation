#include "diceusers.h"

DiceUsers::DiceUsers()
{
}

void DiceUsers::userCheck()
{

}

double DiceUsers::deposit()
{
	int dollars = 0;
	cout << endl;
	cout << " Please enter the amount that you want to deposit => ";
	cin >> dollars;		
	while(dollars<0){
		cout << " Invalid amount to enter. Please try again." << endl;
		cout << " Please enter the amount that you want to deposit => ";
		cin >> dollars;
	}
	balance = +dollars;
	cout << " You have deposited $" << balance << "."<< endl;
	return balance;
}

int DiceUsers::buyChanses(double bb)
{
    int a = 0, b = 0;
		cout << " Please enter the amount of chances you like to puchase (chances = $4) => ";
		cin >> a;
		while (a < 0) {
			cout << " You've entered an invalid amount of Chances, Please try again." << endl;
			cout << " Please enter the amount of chances you like to puchase => ";
			cin >> a;
		}
		if (bb >= a * 4) {
		b = a * 4;
		bb = bb - b;
		cout << " You have purchased " << a << " chances." << endl;
		chances = a;
		return chances;
		}
		if (bb < a * 4) {
		cout << " You do not have sufficient funds to purchase Chances, please deposit more." << endl;
		return 0;
		}
}

void DiceUsers::checkBalance()
{
	cout << " Your balance is " << balance << endl;

}

int DiceUsers::getChances() {
	return chances;
}

int DiceUsers::process()
{
	DiceUsers user;
	int a = user.buyChanses(balance);
	//user.checkBalance();
	return a;
}


DiceUsers::~DiceUsers()
{
}

