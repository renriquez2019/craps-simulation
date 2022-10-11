#include "getbonus.h"

GetBonus::GetBonus() {
	roll = 0;
	bonus = 0;
	count = 1;
}

GetBonus::~GetBonus() {

}

void GetBonus::startRole() {
	cout << " Statring Role: " << count << endl;
	roll = rand() % 6 + 1;
	cout << " The roll is " << roll << endl;
	count++;
	switch (roll) {
	case 1:
		face1();
		break;
	case 2:
		face2();
		break;
	case 3:
		face3();
		break;
	case 4:
		face4();
		break;
	case 5:
		face5();
		break;
	case 6:
		face6();
		break;
	default:
		cout << " Bad Value" << endl;
	}
}

bool GetBonus::determinePoint(int num1, int num2, int num3) {
	bool check;
	
	if (roll == num1 || roll == num2 || roll == num3) {
		check = true;
	}
	else {
		check = false;
	}
	return check;
}

int GetBonus::determineBonus(int point) {
	switch (point) {
	case 4:
		bonus = 10;
		break;
	case 5:
		bonus = 9;
		break;
	case 6:
		bonus = 8;
		break;
	case 8:
		bonus = 4;
		break;
	case 9:
		bonus = 5;
		break;
	case 10:
		bonus = 4;
		break;
	default:
		cout << " Bad value" << endl;
	}
	int pbonus = bonus;
	return pbonus;
}


void GetBonus::test() {
	/*GetBonus user;
	bool checkeroni = true;
	srand(time(NULL));
	for (int i = 0; i < 2; i++) {
		user.startRole();
		checkeroni = user.determinePoint(5, 2, 4);
		if (checkeroni == false) {
			cout << "You failed" << endl;
			i = 4;
		}
	}*/

}