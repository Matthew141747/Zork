#ifndef WORDLE_H
#define WORDLE_H
#include "Parser.h"
class wordle
{
private:
    string txtFile;
public:
    wordle(string t);
    void  reader();
    int game(Command command);
    void wordArray(string j, vector<string> s);
};

#endif // WORDLE_H
