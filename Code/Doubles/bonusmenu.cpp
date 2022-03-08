#include "bonusmenu.h"

Bonus::Bonus() {
	num1 = 0;
	num2 = 0;
	num3 = 0;
	rolls = 0;
}

Bonus::~Bonus() {

}

void Bonus::displayMenu() {
	cout << " *******************" << endl;
	cout << " Pick 3 numbers (1-6) to bet on bonus point" << endl;
	getNums();
	cout << " *******************" << endl;
}

void Bonus::getNums() //throw (InvalidNumber)
{ 
	cout << " Number 1: ";
	cin >> num1;
	if (num1 <= 0 || num1 > 6) {
		//throw InvalidNumber();
	}
	cout << endl;
	cout << " Number 2: ";
	cin >> num2;
	if (num2 <= 0 || num2 > 6) {
		//throw InvalidNumber();
	}
	cout << endl;
	cout << " Number 3: ";
	cin >> num3;
	if (num3 <= 0 || num3 > 6) {
		//throw InvalidNumber();
	}
	cout << endl;
}

int Bonus::process(int point) {
	Bonus user;
	int bonus = 0;
	user.displayMenu();
	user.startRole();
	rolls++;
	bool check = user.determinePoint(user.num1, user.num2, user.num3);
	if (check == true) {
		bonus = user.determineBonus(point);
		cout << " You win the bonus roll!" << endl;
		cout << " You can now score " << point << " and " << bonus << " to win!" << endl;
		return bonus;
	}
	else {
		cout << " You have failed the roll" << endl;
		return bonus;
	}
}

void Bonus::test() {
	//try {
		Bonus user;
		srand(time(NULL));
		int check = user.process(5);
	//}
	//catch(InvalidNumber& e){
	//	e.print();
	//}
}