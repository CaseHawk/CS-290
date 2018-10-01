/*****************************************************************************************
 *  Author: Group 6- Casey Hawkins, Austin Henry, Brad Powell, Jonathan Ruby, Jacky Thind
 *  Date: 07/29/18
 *  Description: Group Project- Declaration of the Critter class
 *****************************************************************************************/

#ifndef CRITTER_HPP
#define CRITTER_HPP
#include <stdlib.h>
#include <iostream>

class Critter
{
protected:
    int row;
    int column;
    int breed;
    int breedSteps;
    int type;
    bool moved;
    static int boardRows;
    static int boardCols;
    
public:
    Critter(int, int);
    virtual ~Critter();
    
    virtual bool move(Critter** &bpard);
    virtual bool breeding(Critter** &board);
    virtual int getType();
    virtual void setMoved();
    static void setBoard(int, int);
    
};

#endif
