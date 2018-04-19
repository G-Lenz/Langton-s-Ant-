/**********************************************************************************************
* Progam Name: ant.hpp
* Author: George Lenz
* Date: 1/21/2018
* Description: Header file for ant class.
*********************************************************************************************/

#ifndef ANT_HPP
#define ANT_HPP

class Ant
{
private:
enum Direction {up, down, left, right};
Direction antDirection;
char antChar;


public:

Ant();


Direction getAntDirection();
char getAntChar();

void turnRight();
void turnLeft();
void moveAnt(int *row, int *column, int boardRow, int boardColumn);
};
#endif 
   


