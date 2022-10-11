#include "app.h"
#include "diceusers.h"


App::App()
{
	username;
	password;
}

void App::createAccount()
{
	ofstream userNameData;
	userNameData.open("userNameData.txt");

	cout << "        ********* " << endl;
	cout << "        * HELLO * " << endl;
	cout << "        ********* " << endl;
	cout << " Please enter your new username => ";
	cin >> user;
	username.push_back(user);
	userNameData << user << endl;

	cout << " Please enter your new password => ";
	cin >> pass;
	password.push_back(pass);
	userNameData << pass << endl;

	userNameData.close();
}

void App::loginAccount()
{
	string line, us1, ps2;
	ifstream userNameData("userNameData.txt");

	if (userNameData.is_open())
	{
		getline(userNameData, us1);
		getline(userNameData, ps2);
		userNameData.close();
	}else cout << "Unable to open file";

	cout << "                 " << endl;
	cout << "        ********* " << endl;
	cout << "        * HELLO * " << endl;
	cout << "        ********* " << endl;
	cout << " Please enter your username => ";
	cin >> username1;
	cout << " Please enter your password => ";
	cin >> password1;

	if (username1 != us1 || password1 != ps2) {
		cout << " You have either entered wrong username or password!" << endl;
		cout << " Please try again!" << endl;
		loginAccount();
	}
	else {
		cout << " Success! Enjoy Your Game" << endl;
	}
	
	DiceUsers player;
	 player.userCheck();
}


App::~App()
{
}

void App::print()
{
	//cout << " To create your username you have entered " << user << endl;
	//cout << " To login you have entered " << username1 << endl;
	//cout << " To create your password you have entered " << pass << endl;
	//cout << " To login you have entered " << password1 << endl;
}

void App::test()
{/*
	App aApp;
	aApp.createAccount();
	cout << "-------------------------------------------------";
	aApp.loginAccount();
	aApp.print();
	*/
}

void App::appprocess() {
	App aApp;
	char a;
	cout << "" << endl;
	cout << "                    ******************************* " << endl;
	cout << "                    * WELCOME TO THE DOUBLES GAME * " << endl;
	cout << "                    ******************************* " << endl;
	cout << "" << endl;
	cout << " To create new account please enter [C] or to login please enter [L] => ";
	cin >> a;
	if (a == 'c' || a == 'C') {
		aApp.createAccount();
	}
		cout << " ------------------------------------------------------------------";
		if (a == 'l' || a == 'L') {
			aApp.loginAccount();
		}
		aApp.print();
	}
