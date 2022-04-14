#ifndef CHARACTER_H_
#define CHARACTER_H_
#include "ZorkUL.h"


using namespace std;
#include <vector>
using std::vector;


class Character {
private:
	string description;
	 vector < string > itemsInCharacter;
public:
    void addItems(string Item);

public:
	Character(string description);
	string shortDescription();
	string longDescription();
    void string();
    virtual void print();
};
class CharacterA : Character{
public:
       void print();
};


namespace X{

class Characterx{
private:
    string description;
     vector < Item > itemsInCharacter;
public:
    void addItems(Item &item);
    void addItem(Item *item);

public:
    Characterx();
    Characterx(string description);
    string shortDescription();
    string longDescription();
    int health;
    int strength;



};
}

#endif /*CHARACTER_H_*/
