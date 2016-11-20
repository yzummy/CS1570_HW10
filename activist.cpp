/*
   Programmer: Christopher O'Toole
   Date: 11/13/2016
   File: activist.cpp
   Purpose: Definitions of functions which control the behavior
        of an activist within a town object's grid.
*/

#include "activist.h"

Activist::Activist( const string name, const char symbol )
: m_X( DEFAULT_POS ), m_Y( DEFAULT_POS ),
  m_State( STATE_NORMAL ),
  m_Symbol( symbol ),
  m_Dignity( DEFAULT_DIGNITY ),
  m_Toxicity( DEFAULT_TOXICITY ),
  m_Name( name )
{
}

void Activist::setPos( Town& town, const int x, const int y )
{
  // clear activist's last pos in grid if applicable
  if ( town.isWithinGrid( m_X, m_Y ) )
    town.setGridAt( m_X, m_Y );

  // set activist to pos
  m_X = x;
  m_Y = y;
  town.setGridAt( x, y, m_Symbol );

  return;
}

void Activist::placeMeInMiddle( Town& town )
{
  // get x and y midpoint
  const int mid = town.getMaxDimUsed( ) / 2;

  // update position in town
  setPos( town, mid, mid );

  return;
}

void Activist::randMove( Town& town )
{
  int x = 0, y = 0;

  do
  {
    // add -1, 0, or 1 to current x coord
    x = m_X + ( rand( ) % 3 - 1 );
    // add -1, 0, or 1 to current y coord
    y = m_Y + ( rand( ) % 3 - 1 );
    // while coordinates are invalid or collision is detected
  } while( !town.isWithinGrid( x, y ) || !town.isGridEmptyAt( x, y ) );

  // update position in town
  setPos( town, x, y );
  return;
}

ostream& operator<<( ostream& os, const Activist& activist )
{
  string state;

  // convert integer state representation to string
  switch( activist.m_State )
  {
    case STATE_NORMAL:
      state = "normal";
    break;

    case STATE_COOL:
      state = "cool";
    break;

    case STATE_GONE:
      state = "gone";
    break;
  }

  // print object to stream
  os << "Position: ( " << activist.m_X << ", " << activist.m_Y << " )"
       << endl << "State: " << state << endl
       << "Symbol: '" << activist.m_Symbol << "'" << endl
       << "Dignity: " << activist.m_Dignity << endl
       << "Toxicity: " << activist.m_Toxicity << endl
       << "Name: " << activist.m_Name;

  return os;
}
