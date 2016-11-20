/*
   Programmers: Christopher O'Toole and Yunchao Zhang
   Date:
   File: activist.h
   Purpose: Definition for a Activist class which represents a activist in
         a town.
*/

#ifndef ACTIVIST_H
#define ACTIVIST_H

#include <iostream>
#include "town.h"
using namespace std;

// min possible toxicity
const float MIN_TOXICITY = 0;
// max possible toxicity
const float MAX_TOXICITY = 3;
// max possible dignity
const int MAX_DIGNITY = 100;
// min possible dignity
const int MIN_DIGNITY = 0;

// possible states
const short STATE_NORMAL = 0; // activist is normal
const short STATE_COOL = 1;   // activist is cool
const short STATE_GONE = 2;   // activist is gone

// default x/y coordinate value
const int DEFAULT_POS = -1;
// default state
const short DEFAULT_STATE = STATE_NORMAL;
// default symbol
const char DEFAULT_ACTIVIST_SYMBOL = 'A';
// default dignity
const int DEFAULT_DIGNITY = MAX_DIGNITY;
// default toxicity
const float DEFAULT_TOXICITY = .05;

class Activist
{
  public:
    //Desc: Constructs an Activist with the given name and symbol. If the
    //   symbol is not specified, the default symbol for an activist is used.
    //Pre: None.
    //Post: The calling object is constructed with the given name and symbol
    //   set and the rest of its members are given initial values.

    Activist( const string name, const char symbol = DEFAULT_ACTIVIST_SYMBOL );

    //Desc: Prints out the values of the relevant members of the calling Activist
    //   object in a user-friendly manner.
    //Pre:  None.
    //Post: Members of the object are displayed on the screen.

    friend ostream& operator<<( ostream& os, const Activist& activist );

    //Desc: The placeMeInMiddle( ) function places an activist in the middle
    //   of the town param's grid
    //Pre:  None.
    //Post: The town param's grid has an activist placed within it.

    void placeMeInMiddle( Town& town );

    //Desc: The randMove( ) function randomly moves an activist one space
    //   in any direction.
    //Pre:  None.
    //Post: The town param's grid is updated with the activist at a new pos.

    void randMove( Town& town );

  private:
    //Desc: The setPos( ) function sets an activist to the pos (x, y) in
    //   the town grid and clears their last pos.
    //Pre: (x, y) is a valid pos in the town's grid.
    //Post: The activist object is set to a different location in the town
    //   param's grid. The x and y members of the calling object are updated to
    //   reflect the change in position.

    void setPos( Town& town, const int x, const int y );

    int m_X; // x coordinate
    int m_Y; // y coordinate
    short m_State; // state (normal, gone, or cool)
    char m_Symbol; // char representation on grid
    int m_Dignity; // amount of dignity
    float m_Toxicity; // toxicity level
    string m_Name; // name
};

#endif
