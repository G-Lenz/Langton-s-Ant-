/**********************************************************************************************
* Progam Name: main.cpp
* Author: George Lenz
* Date: 1/21/2018
* Description: Runs a simulation of Langton's ant
*********************************************************************************************/

#include "board.hpp"
#include "ant.hpp"
#include <iostream>

int main()
{
    int menuChoice = 0;
    int numMoves =0;
    Ant Ant1;
    int row = 0;
    int column = 0;
    int antRow = 0;
    int antColumn = 0;
        
	

    
    do
    {
        //menu for simulation    
        std::cout << "Please select menu item: " << std::endl;
        std::cout << "1: Start Langton's Ant Simulation" << std::endl;
        std::cout << "2: Quit" << std::endl;

        //Input validation for menu selection
        while (!(std::cin >> menuChoice))
        {
            std::cout << "ERROR: Please enter a valid menu choice: \n";
            std::cin.clear();
            std::cin.ignore(500, '\n');
        }
        std::cin.ignore(500, '\n'); 
    
     

        if (menuChoice == 1)
        {
            //Get and validate height input form user.
            do
            {
                std::cout << "Please Enter the board's height(150 max): " << std::endl;
                while(!(std::cin >> row))
                {
                    std::cout << "Please enter a valid integer for height(0-150): \n";
                    std::cin.clear();
                    std::cin.ignore(500, '\n');
		}
                std::cin.ignore(500, '\n');
                if (row > 150)
                {
                    std::cout << "ERROR: NUMBER TOO LARGE \n";
            
                }
                else if (row < 1)
                {
                    std::cout << "ERROR: NUMBER TOO SMALL \n";
                }
                
            }while(!(row > 0 && row <= 150));

            //Get and validate width input from user
            do
            {
       	        std::cout << "Please Enter the board's width: ";
                while(!(std::cin >> column))
                {
                    std::cout << "ERROR: Please enter a valid integer for width (0-150): \n";
                    std::cin.clear();
                    std::cin.ignore(500, '\n');
                }
                std::cin.ignore(500, '\n');
                if (column < 1)
                {
                    std::cout << "ERROR: Number is too small \n";
                }
                else if (column > 150)
                {
                    std::cout << "ERROR: Number is too large \n";
                }
            
            }while(column < 1 || column > 150);


           //get and validate the ant's x-coordinate from user
   	   std::cout << "Please Enter the ant's x coordinate: ";
           do
           {
                while(!(std::cin >> antColumn))
                {
                    std::cout << "ERROR: Please enter a valid integer for ant x-coordinate: \n";
                    std::cin.clear();
                    std::cin.ignore(500, '\n');
                }
                std::cin.ignore(500, '\n');
       
                if(antColumn < 0)
                {
                    std::cout << "ERROR: Number too small. \n";
                }
                else if(antColumn >= 150)
                {
                    std::cout << "ERROR: Number too large. \n";
                }    
        
            }while(antColumn < 0 || antColumn >= column); 

            //Get and validate the ant's y-coordinate from user
	    std::cout << "Please Enter the ant's y-coordinate ";
            do
            {
                while (!(std::cin >> antRow))
                {
                    std::cout << "ERROR: Please enter a valid integer for ant y-coordinate: \n";
                    std::cin.clear();
                    std::cin.ignore(500, '\n');
                }
                std::cin.ignore(500, '\n');
                if (antRow < 0)
                {
                    std::cout << "ERROR: Number is too small \n";
                }
                else if (antRow >= row)
                {
                    std::cout << "ERROR: Number is too large \n";
                }
            }while(antRow < 0 || antRow >= row);

       
            //Get and validate the number of moves for the simulation to perform.
            std::cout << "Please enter the number of moves ";
            while (!(std::cin >> numMoves))
            {
                std::cout << "ERROR: Please enter a valid integer for number of moves: \n";
                std::cin.clear();
                std::cin.ignore(500, '\n');
            }       
            std::cin.ignore(500, '\n');
        
            //creates instance of a board
            Board board1(row, column);

            //sets the ant on the board
    	    board1.setAnt(&Ant1);  

            //fills the board with all white spaces 
   	    for(int i=0; i<row; i++)
    	    {    
                for(int j=0; j<column; j++)
                {
                    board1.setSpace(i, j, ' ');
       	        }	
            }

            //updates board up to the amount of moves provided
    	    for(int i=0; i<numMoves; i++)
    	    {
                //updates the previous ant location 
    	        board1.changePrevious(antRow, antColumn);
                //moves the ant position one space
       	        (board1.getAnt())->moveAnt(&antRow, &antColumn, row, column);
                //updates the color of the ant's current position
    	        board1.updateColor(antRow, antColumn);
    	        //changes the direction of the ant based on the current space color
                board1.changeDirection();
    
    	    }
            //places the ant on the board
    	    board1.placeAnt(antRow, antColumn); 
            //outputs the instance of the finished simulation
    	    board1.drawBoard();
            //frees memory a
            board1.freeMemory(row, column);
            }
            //continued menu choice validation
        else if (menuChoice != 1 && menuChoice !=2)
        {
            std::cout << "ERROR: PLEASE ENTER A VALID NUMBER: \n";
        }
    }while(menuChoice != 2);

    
   
    return 0;
}
   
