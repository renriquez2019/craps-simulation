#include "statistics.h"

Statistics::Statistics() {
	die1 = 0;
	die2 = 0;
	score = 0;
	rolled = 0;
	point = 0;
	bonus = 0;
	singles = 0;
	doubles = 0;
	chances = 0;
}

Statistics::~Statistics() {

}

void Statistics::getDice(int die1, int die2) {
	this->die1 = die1;
	this->die2 = die2;
	point = die1 + die2;
	rolled++;
}

bool Statistics::checkFail() {
	bool fail;
	if (point == 2 || point == 3 || point == 12 || die1 == die2) {
		fail = true;
	}
	else {
		fail = false;
	}
	return fail;
}

bool Statistics::checkWin(int winningpoint) {
	bool win;
	if (point == winningpoint || point == bonus || point == 7 || point == 11) {
		win = true;
	}
	else {
		win = false;
	}
	return win;
}

bool Statistics::process(int die1, int die2, int bonus) {
	int winningpoint = point;
	bool check = false;
	bool checkfail = false, checkwin = false;
	this->bonus = bonus;

	getDice(die1, die2);
	if (die1 == die2) {
		doubles++;
	}
	else {
		singles++;
	}

	checkfail = checkFail();
	if (checkfail == true) {
		cout << " You have lost the roll!" << endl;
		check = true;
		return check;
	}
	else {
		checkwin = checkWin(winningpoint);
	}

	if (checkwin == true) {
		cout << " You have won the roll!" << endl;
		score = point + score;
		return check;
	}
	else if (checkwin == false && checkfail == false) {
		cout << " You did not hit the point." << endl;
		cout << " Go for " << point << endl;
		return check;
	}
}

int Statistics::getPoint() {
	return point;
}
int Statistics::getScore() {
	return score;
}

void Statistics::passChances(int chance) {
	chances = chance;
}

void Statistics::setBonus(int bonus) {
	this->bonus = bonus;
}

void Statistics::print() {
	cout << " Score: " << score << endl;
	cout << " Number of rolls: " << rolled << endl;
	cout << " Point: " << point << endl;
	cout << " Bonus Point: " << bonus << endl;
	cout << " Singles: " << singles << endl;
	cout << " Doubles: " << doubles << endl;
	cout << " Chances: " << chances << endl;
}

void Statistics::test() {
	/*Statistics aUser;

	aUser.process(5, 4);
	aUser.process(6, 3);
	aUser.process(4, 2);
	aUser.process(1, 5);
	aUser.process(2, 2);

	aUser.print();*/

}