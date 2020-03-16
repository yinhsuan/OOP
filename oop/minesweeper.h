#ifndef MINESWEEPER_H
#define MINESWEEPER_H

#include "myother.h"

class Minesweeper : public MyOther
{
public:
    Minesweeper();
    string solve(string s);
};

#endif // MINESWEEPER_H
