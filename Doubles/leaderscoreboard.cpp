#include "leaderscoreboard.h"
#include "statistics.h"



LeaderScoreboard::LeaderScoreboard()
{
	scored;
	int max = scored.size();
	for (int i = 0; i < max; i++)
	{
			scored[i] = 0;
	}
}

int LeaderScoreboard::add(int score) {
	scored.push_back(score);
	return score;
}

double LeaderScoreboard::getHighest()
{
	for (unsigned int i = 0; i < scored.size(); i++)
	{
		if (scored[0] < scored[i])
			scored[0] = scored[i];	  
	}
	
	return scored[0];
}

LeaderScoreboard::~LeaderScoreboard()
{

}

void LeaderScoreboard::callPoints(int score) {
	this->score = score;
}

void LeaderScoreboard::print()
{
	cout << " High score: " << scored[0] << endl;
	
	for (unsigned int i = 0; i < scored.size(); i++)
		cout << scored[i] << endl;
}
void process() {
	LeaderScoreboard aBoard;
	aBoard.add(0);
	aBoard.getHighest();
	aBoard.print();
}



void LeaderScoreboard::test()
{
	LeaderScoreboard aBoard;
	aBoard.add(10);
	aBoard.add(10);
	aBoard.getHighest();
	aBoard.print();
}

