/*****************************************************************************************
 *  Author: Group 6- Casey Hawkins, Austin Henry, Brad Powell, Jonathan Ruby, Jacky Thind
 *  Date: 07/29/18
 *  Description: Group Project- Critter implementation file
 *****************************************************************************************/

#include "Critter.hpp"

Critter::Critter(int row, int column)
{
    this->row = row;
    this->column = column;
    this->breedSteps = 0;
    this->moved = false;
}

bool Critter::move(Critter** &board)
{
    int dir = rand() % 4;
    bool validMove = false;
    
    if(board[dir] == 0)         //If board[dir] == 0, the board space is open, not an edge or critter
    {
        validMove = true;
        switch(dir)
        {
            case(0):
                row -= 1;
                break;
            case(1):
                column += 1;
                break;
            case(2):
                row += 1;
                break;
            case(3):
                column -= 1;
                break;
        }
    }
    
    breedSteps ++;
    if (breedSteps == breed)
    {
        breed(array);
    }
    moved = validMove;
    return validMove;
}

bool Critter::breeding(Critter** &board)
{
    bool newCritter;
    int checkSequence[4] = {-1, -1, -1, -1};
    int newCrittRow;
    int newCrittCol;
    bool uniqueOrder = false;
    bool breedNew = false;
    
    for(int i = 0; i < 4; i++)          //Check to see if critter can breed in an empty space
    {
        while(!uniqueOrder)
        {
            uniqueOrder = true;
            checkSequence[i] = rand() % 4;
            for(int j = 0; j < i; j++)
            {
                if(checkSequence[i] == checkSequence[j])
                {
                    uniqueOrder = false;
                }
            }
        }
    }
    
    for(int cell = 0; cell < 4; cell++)
    {
        if(!breedNew)
        {
            switch(checkSequence[cell])
            {
                case(0):
                    if(board[0] == 0)
                    {
                        newCrittRow = row - 1;
                        newCrittCol = column;
                        breedNew = true;
                    }
                    break;
                case(1):
                    if(board[1] == 0)
                    {
                        newCrittRow = row;
                        newCrittCol = column + 1;
                        breedNew = true;
                    }
                    break;
                case(2):
                    if(board[2] == 0)
                    {
                        newCrittRow = row + 1;
                        newCrittCol = column;
                        breedNew = true;
                    }
                    break;
                case(3):
                    if(board[3] == 0)
                    {
                        newCrittRow = row;
                        newCrittCol = column - 1;
                        breedNew = true;
                    }
                    break;
            }
        }
    }
    
    if(breedNew)        //If there is an open space, the critter can breed, create new critter
    {
        newCritter = Critter(newCrittRow,newCrittCol));
        breedSteps = 0;
    }
    else
    {
        newCritter = nullptr;
    }
    return newCritter;
}

int Critter::getType()
{
    return type;
}

void Critter::setMoved()
{
    this->moved = moved;
}

void setBoard(int rows, int columns)
{
    int boardsRows = rows;
    int boardCols = columns;
}
