#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>
#include "GameMenu.h"
#include "diceusers.h"
#include "UserChances.h"
#include "statistics.h"

using namespace std;

GameMenu::GameMenu(){
    //string User;
    point = 0;
    bonus = 0;
}

GameMenu::GameMenu(int chance){
	Chances = chance;
    }

int GameMenu::Menu()
{
	int userchoice;
    do{
			cout << "" << endl;
            cout << " Enter [1] to Roll the Dice." << endl;
            cout << " Enter [2] to Check your Statistics." << endl;
            cout << " Enter [3] to Try out the Bonus Challenge. (Roll at least one before going for bonus)" << endl;
            cout << " Enter [4] to Add Chances to your Account." << endl;
            cout << " Enter [5] to Check out the Current LeaderBoards." << endl;
            cout << " Enter [0] to Exit." << endl;
			cout << "" << endl;
            cin >> userchoice;
    }while (userchoice<0 || userchoice>5);
	return userchoice;
}

void GameMenu::MenuProcess(int Option){
	LeaderScoreboard aBoard;
	Statistics scores;
	int score = scores.getScore();
	//score = score + point;
	int a;
    switch(Option){
    case 1:
        cout << " Chances are now " <<Chances<<endl;
        if (Chances > 0){
        cout << endl;
        cout << " You've chosen to the Roll the Dice! Have Fun." << endl;
        Roll();
        cout<< " Chances left: "<<Chances<<endl;}
        if (Chances == 0){
            cout<< " You have no more chances remaining!" << endl;
        }

        break;
    case 2:
        cout << " You've decided to check your Statistics." << endl;
        cout << endl;
		CheckStatistics();
        break;
    case 3:
		if (point != 0) {
			cout << " Good luck with the bonus challenge!." << endl;
			ChooseBonus();
		}
		else {
			cout << " Roll before you go for bonus" << endl;
		}
        break;
    case 4:
        cout << " You've decided to add chances to your account." << endl;
		AddChances();
        break;
    case 5:
		cout << " Take a look at the Leaderboards!" << endl;
		score = getScore();
		aBoard.add(score);
		aBoard.getHighest();
		aBoard.print();
        break;
    case 0:
        cout << endl;
        cout << " Thanks For Playing Dice!" << endl;
		score = getScore();
		a = exitProcess(0, 0,score);

        break;
    default:
        cout << " The choice you've selected is not valid" << endl;
        cout << " Please choose a value between " << endl;

     }
}

void GameMenu::Roll(){
    int dice1 = DieOne();
    int dice2 = DieTwo();
    cout << dice1 <<endl;
    cout << dice2 <<endl;
	bool checkfail = Statistics::process(dice1, dice2, bonus);
	int pPoint = getPoint();
	point = pPoint;
	if (checkfail == true) {
		Chances = Chances - 1;
	}
	else {
		//point = getPoint();
	}
  
}

/*int GameMenu::SwitchDice(){
    return 0;
}*/

double GameMenu::IncrementScore(){
    return 0;
}

void GameMenu::CheckStatistics(){
	Statistics::passChances(Chances);
	Statistics::print();
}

void GameMenu::ChooseBonus(){
	int a = Bonus::process(point);
	if (a == 0) {
		Chances = Chances - 1;
	}
	bonus = a;
	setBonus(a);
}

void GameMenu::AddChances(){
	DiceUsers auser;
	int plusChance = auser.buyChanses(balance);
	if (plusChance == 0) {
		int a = exitProcess(0, 0, score);
	}
	Chances = plusChance + Chances;
	balance = balance - (plusChance * 4);
	cout << " You now have $" << balance << endl;
	cout << " You now have " << Chances << " chances" << endl;
}

void GameMenu::CheckLeaders(){
}

int GameMenu::DieOne(){
    int d1;
    d1 = rand()% 6+1;
	switch (d1) {
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
    return d1;
}

int GameMenu::DieTwo(){
    int d2;
    d2 = rand()% 6+1;
	switch (d2) {
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

    return d2;
}

void GameMenu::test(){
        //cout << "Hello world!" << endl;

    srand (time(NULL));
    GameMenu aMenu;
  //  cout << "How many chances would you like?" <<endl;
  //  cin >> aMenu.Chances;

    int userchoice;
    do{
        cout << "\n";
        userchoice = aMenu.Menu();
        aMenu.MenuProcess(userchoice);
    }while ((userchoice != 0));

}

void GameMenu::mainprocess() {
	srand(time(NULL));
	App user;
	LeaderScoreboard aBoard;
	user.appprocess();
	DiceUsers auser;
	double b = auser.deposit();
	int chance = auser.process();

    GameMenu usermenu(chance);
	usermenu.balance = b;

	while (usermenu.Chances > 0) {
		int option = usermenu.Menu();
		usermenu.MenuProcess(option);
	}

	char choice;
	cout << " Do you want to buy more chances?" << endl;
	cout << "[Y] or [N]";
	cin >> choice;
	if (choice == 'y' || choice == 'Y') {
		usermenu.AddChances();
		while (usermenu.Chances > 0) {
			int option = usermenu.Menu();
			usermenu.MenuProcess(option);
		}
	}
	Exit euser;
	euser.exitProcess(0,0, usermenu.score);

}

