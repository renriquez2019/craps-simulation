#include <iostream>
#include "getbonus.h"
#include "GameMenuExceptions.h"

#ifndef BONUSMENU_H
#define BONUSMENU_H

//using namespace std;

class Bonus : public GetBonus{
public:
	Bonus();
	~Bonus();
	void displayMenu();
	void getNums();
		//throw (InvalidNumber);
	int process(int point);
	static void test();
private:
	int num1;
	int num2;
	int num3;
	int rolls;
};

#endif