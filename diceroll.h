#ifndef DICEROLL_H
#define DICEROLL_H
#include <iostream>
#include <cstdlib>
#include <ctime>

namespace d{

template <typename T> T add(T num1, T num2, T num3){
    return (num1 + num2 + num3);

};



class diceRoll
{
protected:

    bool canPlay;

private:
    int redDie;
    int blueDie;


    double total_number_of_rolls = {};
    double total_number_of_sixes = {};
    int again = {};

public:
    diceRoll(int a, int b);
    friend class Room;
    friend class combat;


    diceRoll operator + (diceRoll const &obj);
    int roll();
    ~diceRoll();

};


extern diceRoll res;
}
#endif // DICEROLL_H
