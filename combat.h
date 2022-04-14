#ifndef COMBAT_H
#define COMBAT_H
#include "diceroll.h"
// user defined exception, initialiser list,
#include <exception>
using namespace std;

class MyException : public exception{
public:
    const char *what()const throw()
    {
        return "error you did not type in an integer";
    }
};

class combat
{

private:
    int mhealth;
    static int phealth;

    const int attackValue;
    int defenceValue;

public:
    combat();

    combat(int attackValue, int defenceValue);


    int showMonsterhp();

    int showPlayerhp();
    void win();


};

#endif // COMBAT_H
