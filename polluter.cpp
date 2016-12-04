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
: m_Pos( POLLUTER_DEFAULT_COORD_VAL, POLLUTER_DEFAULT_COORD_VAL ),
  m_Symbol( symbol ),
  m_Name( name ),
  m_Caught( false ),
  m_OverRoot( false )
{
}

void Polluter::setPos( Town& town, const Point<int>& pos )
{
  const char charAtPos = town.getGridAt( pos );

  if ( charAtPos != TOWN_WALL_CHAR && charAtPos != TOWN_EXIT_CHAR )
  {
    if ( town.isWithinGrid( m_Pos ) )
    {
      town.setGridAt( m_Pos, m_OverRoot ? ROOT_CHAR : TOWN_EMPTY_SPACE );
      m_OverRoot = false;
    }

    if ( charAtPos == TOWN_COP_CHAR )
      m_Caught = true;
    else if ( charAtPos == ROOT_CHAR )
      m_OverRoot = true;

    m_Pos.setPos( pos.getX( ), pos.getY( ) );
    town.setGridAt( pos, m_Symbol );
  }

  return;
}

void Polluter::placeMe( Town& town )
{
  setPos( town, town.getRandPointInGrid( ) );
  return;
}

bool Polluter::randMove( Town& town )
{
  bool move = !m_Caught;
  Point<int> newPos;

  if ( move )
  {
    newPos = m_Pos.randMove( );
    setPos( town, newPos );
  }

  return move;
}
