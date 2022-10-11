#include "statistics.h"
#ifndef USERCHANCES_H_INCLUDED
#define USERCHANCES_H_INCLUDED

class UserChances: public Statistics{

    public:
        UserChances();
        UserChances(int Chances);
        int getChances();
    protected:
        int Chances;
};

#endif // USERCHANCES_H_INCLUDED
