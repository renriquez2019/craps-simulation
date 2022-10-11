#define CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "bonusmenu.h"
#ifndef STATISTICS_H
#define STATISTICS_H


using namespace std;

class Statistics: public Bonus {
public:
	Statistics();
	~Statistics();
	void getDice(int die1, int die2);
	bool checkFail();
	bool checkWin(int winpoint);
	bool process(int die1, int die2, int bonus);
	void passChances(int chance);
	void setBonus(int bonus);
	int getPoint();
	void print();
	int getScore();
	static void test();
private:
	int die1;
	int die2;
	int rolled;
	int point;
	int bonus;
	int singles;
	int doubles;
	int chances;
protected:
	int score;
};

#endif // STATISTICS_H