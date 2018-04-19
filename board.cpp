/**********************************************************************************************
* Progam Name: board.cpp
* Author: George Lenz
* Date: 1/21/2018
* Description: Implementation file for board class
*********************************************************************************************/

#include "board.hpp"
#include <iostream>
#include "ant.hpp"
#include <iomanip>

//Constructor for baord
Board::Board(int aHeight, int aWidth)
{

    width = aWidth;
    height = aHeight;
    anAnt = NULL;
    antSpace = white;
    boardPtr = new char*[height];
   

    for(int i=0; i<height; i++)
    {
        boardPtr[i] = new char[width];
    }
}
    
int Board::getWidth()
{
    return width;
}

int Board::getHeight()
{
    return height;
}

Ant* Board::getAnt()
{
    return anAnt;
}

Board::Space Board::getAntSpace()
{
    return antSpace;
}

char** Board::getBoardPtr()
{
    return boardPtr;
}

void Board::setWidth(int aWidth)
{
    width = aWidth;
}

void Board::setHeight(int aHeight)
{
    height = aHeight;
}

void Board::setAnt(Ant* aAnt)
{
    anAnt =  aAnt;
}

//outputs an instance of a board    
void Board::drawBoard()
{
    for(int i=0; i<height; i++)
    {
        std::cout << std::setw(1) << '|';

        for(int j=0; j<width; j++)
        {
            std::cout << boardPtr[i][j];
            
        }
        std::cout << std::setw(1) << '|';
        std::cout << std::endl;
    }
}
 
//sets a space on the board to a given character            
void Board::setSpace(int row, int column, char space)
{ 
    boardPtr[row][column] = space;
} 

//places the ant at a given position on the board
void Board::placeAnt(int row, int column)
{
    boardPtr[row][column] = anAnt->getAntChar();
}

//changes the ants previous position on the board
void Board::changePrevious(int row, int column)
{
    if (antSpace == black)
    {
        boardPtr[row][column] = ' ';
    }
    else
    {
        boardPtr[row][column] = '#';
    }
}

//updates the color of the ants current space
void Board::updateColor(int row, int column)
{
    if(boardPtr[row][column] == '#')
    {
        antSpace = black;
    }
    else if (boardPtr[row][column] == ' ') 
    {
        antSpace = white;
    }
}

//changes the direction the ant is facing based on board space color
void Board::changeDirection()
{
    if(antSpace == white)
    {
        anAnt->turnRight();
    }
    else if (antSpace == black)
    {
        anAnt->turnLeft();
    }
}

//frees the memory allocated to the array.
void Board::freeMemory(int height, int width)
{
    for (int i=0; i<height; i++)
    {
	delete [] boardPtr[i];
        boardPtr[i] = nullptr;
    }
    
    delete [] boardPtr;
    boardPtr = nullptr;
}
    




