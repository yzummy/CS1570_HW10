/*
   Programmers: Christopher O'Toole and Yunchao Zhang
   Date:
   File: polluter.cpp
   Purpose: Definitions of functions which control the behavior
        of a polluter within a town object's grid.
*/

#include "polluter.h"
#include <cstdlib>

Polluter::Polluter( const string name, const char symbol )
: m_X( POLLUTER_DEFAULT_COORD_VAL ), m_Y( POLLUTER_DEFAULT_COORD_VAL ),
  m_Symbol( symbol ),
  m_Name( name ), isCaught( false )
{
}

void Polluter::setPos( Town& town, const int x, const int y )
{
  // clear polluter's last pos in grid if applicable
  if ( town.isWithinGrid( m_X, m_Y ) )
    town.setGridAt( m_X, m_Y );

  // set polluter to new position
  m_X = x;
  m_Y = y;
  town.setGridAt( x, y, m_Symbol );

  return;
}

void Polluter::placeMe( Town& town )
{
  int x = 0, y = 0;

  do
  {
    // get random coordinates within town grid
    x = rand( ) % town.getMaxDimUsed( );
    y = rand( ) % town.getMaxDimUsed( );
    // while coordinates are invalid or collision is detected
  } while ( !town.isWithinGrid( x, y ) || !town.isGridEmptyAt( x, y ) );

  // update position in town
  setPos( town, x, y );
  return;
}

void Polluter::randMove( Town& town )
{
  int x = 0, y = 0;
  do
  {
    // add -1, 0, or 1 to current x coord
    x = m_X + ( rand( ) % 3 - 1 );
    // add -1, 0, or 1 to current y coord
    y = m_Y + ( rand( ) % 3 - 1 );
    // while coordinates are invalid or collision is detected
  } while ( !town.isWithinGrid( x, y ) || !town.isGridEmptyAt(x, y));

  // update position in town
  if(town.getGridAt(x, y) == DEFAULT_COP_SYMBOL 
      || town.getGridAt(x, y) == DEFAULT_ACTIVIST_SYMBOL)
    isCaught = true;
  setPos( town, x, y );

  return;
}
