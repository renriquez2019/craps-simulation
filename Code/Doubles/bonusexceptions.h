#include <iostream>
#include <string>

#ifndef BONUSEXCEPTIONS_H
#define BONUSEXCEPTIONS_H
using namespace std;


class InvalidNumber {
public:
	InvalidNumber() {
		message = "Invalid Number";
		errorcode = 10001;
	}
	~InvalidNumber() {

	}
	void print() {
		cout << "Error Code: " << errorcode << endl;
		cout << message << endl;
	}

private:
	string message;
	int errorcode;
};

#endif