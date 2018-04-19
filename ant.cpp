/**********************************************************************************************
* Progam Name: ant.cpp
* Author: George Lenz
* Date: 1/21/2018
* Description: Implementatino file for ant class
*********************************************************************************************/

#include "ant.hpp"
#include "board.hpp"

//constructor for ant class.
Ant::Ant()
{
    antDirection = up;
    antChar = '*';
}

Ant::Direction Ant::getAntDirection()
{
    return antDirection;
}

char Ant::getAntChar()
{
    return antChar;
}

//turns the ant 90 degrees right
void Ant::turnRight()
{
    if(antDirection == up)
    {
        antDirection = right;
    }
    else if (antDirection == down)
    {
        antDirection = left;
    }
    else if (antDirection == left)
    {
        antDirection = up;
    }
    else 
    {
        antDirection = down;
    }
}

//turns the ant 90 degrees left
void Ant::turnLeft()
{
    if(antDirection == up)
    {
        antDirection = left;
    }
    else if (antDirection == down)
    {
        antDirection = right;
    }
    else if (antDirection == left)
    {
        antDirection = down;
    }
    else 
    {
        antDirection = up;
    }
}

//moves the ant forward one space.
void Ant::moveAnt(int *row, int *column, int boardRow, int boardColumn)
{
    
    if (antDirection == Ant::up)
    {
        if(*row - 1 >= 0)	
        {
	    *row = *row - 1;
        }
	else
	{
	    *row = (boardRow - 1);
        }
    }
            
    else if (antDirection == Ant::down)
    {
	if(*row + 1 < boardRow)	
        {
	    *row = *row + 1;
        }
	else
	{
	    *row = 0;
        }
        
    	}
    else if (antDirection == Ant::left)
    {
        if(*column - 1 >= 0)	
        {
	    *column = *column - 1;
        }
	else
	{
	    *column = (boardColumn - 1);
        }
        
    }
            
    else if (antDirection == Ant::right)
    {
        if(*column + 1 < boardColumn)	
        {
	    *column = *column + 1;
        }
	else
	{
	    *column = 0;
        }
        
    }
}
