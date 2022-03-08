#pragma once
#include "graphics.h"
#include <algorithm>
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#ifndef LEADER_SCOREBOARD_H
#define LEADER_SCOREBOARD_H

using namespace std;

class LeaderScoreboard {
public:
	LeaderScoreboard();
	double getHighest();
	int add(int score);
	~LeaderScoreboard();
	void print();
	void callPoints(int score);
	static void test();
protected:
	vector <int> scored;
	int score;
	int i;
};
#endif //!LEADER_SCOREBOARD_H
