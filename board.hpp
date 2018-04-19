/**********************************************************************************************
* Progam Name: board.hpp
* Author: George Lenz
* Date: 1/21/2018
* Description: Header file for board class.
*********************************************************************************************/

#ifndef BOARD_HPP
#define BOARD_HPP
#include "ant.hpp"


class Board
{
private:
    
    enum Space {black, white};    
    Space antSpace; 
    int width;
    int height;
    char **boardPtr;
    Ant* anAnt;

public:

    Board(int height, int width);

    int getWidth();
    int getHeight();
    Ant* getAnt();
    Space getAntSpace();
    char** getBoardPtr();

    void setWidth(int aWidth);
    void setHeight(int aHeight);
    void setAnt(Ant*);

    void drawBoard();
    void setSpace(int row, int column, char space);
    void placeAnt(int row, int column);
    
    void changePrevious(int row, int column);
    void updateColor(int row, int column);
    void changeDirection();
    void freeMemory(int height, int width);
};
#endif
