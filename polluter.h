/*
   Programmers: Christopher O'Toole and Yunchao Zhang
   Date:
   File: polluter.h
   Purpose: Definition for a Polluter class which represents a polluter in
         a town.
*/

#ifndef POLLUTER_H
#define POLLUTER_H

#include "town.h"
#include "activist.h"
using namespace std;

// default x/y coordinate value
const int POLLUTER_DEFAULT_COORD_VAL = -1;
// default symbol
const char POLLUTER_DEFAULT_SYMBOL = 'P';

class Polluter
{
  public:
    //Desc: Constructs a Polluter with the given name and symbol. If the symbol
    //   is not specified, the default symbol for a polluter is used.
    //Pre: None.
    //Post: The calling object is constructed with the given name and symbol set
    //   and the rest of its members are given initial values.

    Polluter( const string name, const char symbol = POLLUTER_DEFAULT_SYMBOL );

    //Desc: The placeMe( ) function places the polluter at a random spot in
    //   the town grid.
    //Pre: None.
    //Post: The town param's grid has a polluter set at a random location.
    //   The polluter's x and y members of the calling object are updated
    //   to reflect the change in position.

    void placeMe( Town& town );

    //Desc: The randMove( ) moves the polluter one space in any direction.
    //Pre:  None.
    //Post: The polluter object is set to a different location in the town
    //   param's grid. The x and y members of the calling object are updated to
    //   reflect the change in position.

    void randMove( Town& town );

    //Desc:
    //Pre: 
    //Post: 
    int getPosX() const {return m_X;}
    
    //Desc:
    //Pre:
    //Post:
    int getPosY() const {return m_Y;} 

    //Desc:
    //Pre:
    //Post:
    bool getCaughtStatus() const {return isCaught;}
  private:
    int m_X; // x coordinate
    int m_Y; // y coordinate
    char m_Symbol; // character representation on grid
    string m_Name; // name
    bool isCaught;
    
    //Desc: The setPos( ) function sets a polluter to the pos (x, y) in
    //   the town grid and clears their last pos.
    //Pre: (x, y) is a valid pos in the town's grid.
    //Post: The polluter object is set to a different location in the town
    //   param's grid. The x and y members of the calling object are updated to
    //   reflect the change in position.

    void setPos( Town& town, const int x, const int y );
};

#endif
