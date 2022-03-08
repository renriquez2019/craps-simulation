#include <iostream>
#include <string>
#include <cstdlib>
#ifndef GAMEMENU_H_INCLUDED
#define GAMEMENU_H_INCLUDED
#include "GameMenuExceptions.h"
#include "UserChances.h"
#include "app.h"

using namespace std;

class GameMenu:public UserChances {
    public:
        GameMenu();
        GameMenu(int chance);
        int Menu();
        void MenuProcess(int Option);
        void Roll ();
        //int SwitchDice();
        double IncrementScore();
        void CheckStatistics();
        void ChooseBonus();
        void AddChances();
        void CheckLeaders();
        int DieOne();
        int DieTwo();
        static void test();
		static void mainprocess();
    private:
        string User;
		int point;
        int bonus;
		double balance;
};

#endif // GAMEMENU_H_INCLUDED




