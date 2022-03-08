#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "GameMenu.h"
#include "leaderscoreboard.h"

using namespace std;

#ifndef APP_H
#define APP_H

class App : public LeaderScoreboard{
public:
	App();
	void createAccount();
	void loginAccount();
	~App();

	void print();
	static void test();
	void appprocess();

protected:
	string username1;
	string password1;
	string user;
	string pass;
private:
	vector<string> username;
	vector<string> password;
};
#endif //!APP_H
