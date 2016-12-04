/*
   Programmers: Christopher O'Toole and Yunchao Zhang
   Date:
   File: town.h
   Purpose: Definition for a Town class which represents a town and the objects
         within it via a grid system.
*/

#ifndef TOWN_H
#define TOWN_H

#include <iostream>
#include "root.h"
#include "point.h"
#include "config.h"
using namespace std;

// max width/height of town
const short TOWN_MAX_DIM = 25;
// char representing wall
const char TOWN_WALL_CHAR = 'W';
// char representing exit
const char TOWN_EXIT_CHAR = 'E';
// char representing cop
const char TOWN_COP_CHAR = 'C';
// empty space in town
const char TOWN_EMPTY_SPACE = ' ';
// grid character separator
const char TOWN_GRID_SEP = '|';
// max amount of roots
const int MAX_NUM_ROOTS = 20;

class Town
{
  public:
    // num dignity points lost by actor for talking to cop
    static int numPtsLostForCop;
     // num dignity points lost by actor for wall collision
    static int numPtsLostForWall;

    //Desc: Constructs empty Town of maxDimUsed x maxDimUsed size
    //Pre:  0 < maxDimUsed <= TOWN_MAX_DIM
    //Post: An empty town of maxDimUsed x maxDimUsed is constructed if
    //   maxDimUsed is within the range specified, otherwise, an error
    //   message is displayed and the program terminates.

    Town( const Config& config, short maxDimUsed = TOWN_MAX_DIM );

    //Desc: Overloaded insertion operator for Town class, prints out the
    //   the entirety of the town grid to the screen.
    //Pre:  None.
    //Post: The town grid is displayed on the screen.

    friend ostream& operator<<( ostream& os, const Town& town );

    //Desc: The isWithinGrid() function checks whether or not the given (x, y)
    //   coordinate is within the dimensions of the grid.
    //Pre:  None.
    //Post: Returns true if the (x, y) coordinate is within the grid,
    //   false otherwise.

    bool isWithinGrid( const Point<int>& pos ) const;

    //Desc: The setGridAt() function sets the grid value at (x, y) to the given
    //   symbol, or an empty space if a symbol is not specified.
    //Pre:  0 <= x, y < maxDimUsed
    //Post: The town grid is updated at the given (x, y) pos with the given
    //   symbol if (x, y) is a valid grid pos, otherwise an error message is
    //   displayed and the program terminates.

    void setGridAt( const Point<int>& pos, const char symbol );

    //Desc: The isGridEmptyAt() function returns whether or not the town grid
    //   has an empty space at pos (x, y).
    //Pre:  0 <= x, y < maxDimUsed
    //Post: Returns true if the town grid at pos (x, y) is an empty space,
    //    false otherwise when (x, y) is a valid grid pos. If (x, y) is not
    //    a valid grid pos, an error message is displayed and the program
    //    terminates.

    bool isGridEmptyAt( const Point<int>& pos ) const;

    //Desc: The getMaxDimUsed( ) region returns the max width/height of the
    //   town.
    //Pre:  None.
    //Post: The max width/height of the town is returned.

    short getMaxDimUsed( ) const { return m_MaxDimUsed; }

    //Desc: The getGridAt( ) function retrieves the value of the town grid
    //    at pos ( x, y ).
    //Pre:  0 <= x, y < maxDimUsed
    //Post: The value of the town grid at pos (x, y) is returned if (x, y)
    //   is a valid grid pos, otherwise an error message is displayed and the
    //   the program terminates.

    char getGridAt( const Point<int>& point ) const;

    //Desc:
    //Pre:
    //Post:

    Root& getNextRoot( );

    //Desc:
    //Pre:
    //Post:

    const Point<int>& getRandPointInGrid( );

  private:
    char  m_Grid[TOWN_MAX_DIM][TOWN_MAX_DIM]; // grid representing town
    short m_MaxDimUsed; // max dimensions of town that are actually in use
    Root m_Roots[MAX_NUM_ROOTS]; // array of roots in the town
    int m_NumRoots; // number of roots left
    int m_NumCops;

    //Desc: The clear( ) function fills the used region of the town grid with
    //   empty space.
    //Pre:  None.
    //Post: The used region of the town grid is filled with empty space.

    void clear( );

    //Desc: The build( ) function updates the town grid with the walls and
    //   exits of the town.
    //Pre:  None.
    //Post: The town grid is updated with the walls and exits of the town.

    void build( );


};

#endif
