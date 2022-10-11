#include <iostream>
#include <time.h>
#include <cstdlib>
#include "Exit.h"
using namespace std;
#ifndef GETBONUS_H
#define GETBONUS_H


class GetBonus : public Exit {
public:
	GetBonus();
	~GetBonus();
	void startRole();
	bool determinePoint(int num1, int num2, int num3);
	int determineBonus(int point);
	static void test();
private:
	int roll;
	int count;
	int bonus;
};

#endif