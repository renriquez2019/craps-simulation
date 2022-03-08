#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

#ifndef DICEALPHABETEXCEPTION_H_INCLUDED
#define DICEALPHABETEXCEPTION_H_INCLUDED

class DiceAlphabetException{
    public:
        void print(){
        cerr <<"Error "<< Errorcode << ": " << Message << endl;
        }
        DiceAlphabetException(){
        Errorcode = 42069;
        Message = "Alphabetic value inserted, not accepted.";
        }
        virtual ~DiceAlphabetException(){
        }
    private:
        int Errorcode;
        string Message;
};

#endif // DICEALPHABETEXCEPTION_H_INCLUDED
