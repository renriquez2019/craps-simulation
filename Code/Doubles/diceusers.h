#pragma once
#include "app.h"
#include <string>

#ifndef DICE_USERS_H
#define DICE_USERS_H
#define PMAX 10000
#define CMAX 10000
class DiceUsers :
	public App
{
public:
	DiceUsers();
	void userCheck();
	double deposit();
	int buyChanses(double bb);
	void checkBalance();
	int getChances();
	int process();
	~DiceUsers();
protected:
	double balance;
	double account;
private:
	int chances;
};
#endif //!DICE_USERS_H
