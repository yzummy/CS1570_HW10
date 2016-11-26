/*
   Programmers: Christopher O'Toole and Yunchao Zhang
   Date:
   File: activist.cpp
   Purpose: Definitions of functions which control the behavior
        of an activist within a town object's grid.
*/

#include "activist.h"
#include "root.h"
#include "polluter.h"
#include "town.h"
#include <cstdlib>

using namespace std;

Activist::Activist( const string name, const char symbol )
: m_X( DEFAULT_POS ), m_Y( DEFAULT_POS ),
  m_State( STATE_NORMAL ),
  m_Symbol( symbol ),
  m_Dignity( DEFAULT_DIGNITY ),
  m_Toxicity( DEFAULT_TOXICITY ),
  m_Name( name ),
  overCop( false )
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
  
  if(overCop)
  {
    town.setGridAt(m_X, m_Y, DEFAULT_COP_SYMBOL);  
    overCop = false;
  }
  do
  {
    // add -1, 0, or 1 to current x coord
    x = m_X + ( rand() % 3 - 1 );
    // add -1, 0, or 1 to current y coord
    y = m_Y + ( rand() % 3 - 1 );
    // while coordinates are invalid or collision is detected
  } 
  while( (x == m_X && y == m_Y) || !town.isWithinGrid( x, y ) );

          cout << "original: " << m_X << " " << m_Y << endl;
          cout << "new: " << x << " " << y << endl;

  
  if(town.isGridEmptyAt(x, y))
    setPos(town, x, y);
  else
    collide(town, x, y);
  return;
}


void Activist::smartMove(Town& town, const int pol_x, const int pol_y)
{
  int x = m_X, y = m_Y;
  
  if(overCop)
  {
    town.setGridAt(m_X, m_Y, DEFAULT_COP_SYMBOL);
    overCop = false;
  }
  if(pol_x < m_X && pol_y > m_Y)
  {
    x = m_X - 1;
    y = m_Y + 1;
  }
  else if(pol_x < m_X && pol_y < m_Y)
  {
    x = m_X - 1;
    y = m_Y - 1;
  }
  else if(pol_x > m_X && pol_y > m_Y)
  {
    x = m_X + 1;
    y = m_Y + 1; 
  }
  else if(pol_x > m_X && pol_y < m_Y)
  {
    x = m_X + 1;
    y = m_Y - 1;
  }
  else if(pol_x < m_X && pol_y == m_Y)
  {
    x = m_X - 1;
  }
  else if(pol_x > m_X && pol_y == m_Y)
  {
    x = m_X + 1;
  }
  else if(pol_x == m_X && pol_y < m_Y)
  {
    y = m_Y - 1;
  }
  else if(pol_x == m_X && pol_y > m_Y)
  {
    y = m_Y + 1;
  }
  
          cout << "original: " << m_X << " " << m_Y << endl;
          cout << "new: " << x << " " << y << endl;
  
  if(town.isGridEmptyAt(x, y))
    setPos(town, x, y);
  else
    collide(town, x, y);
  
  return; 
}

void Activist::move(Town & town, const int pol_x, const int pol_y)
{
  if(m_State)
    randMove(town);
  else
    smartMove(town, pol_x, pol_y);    
  return;  
}

void Activist::collide(Town & town, const int x, const int y)
{
 switch(town.getGridAt(x, y))
 {
   case TOWN_WALL_CHAR:
     m_Dignity -= town.getDigLossWall();
                                          cout << "dignity lost" << endl;     
     break;
   case TOWN_EXIT_CHAR:
     setState(STATE_GONE);
     break;
   case POLLUTER_DEFAULT_SYMBOL:
     // TO-DO win the day
     setState(STATE_GONE);
     break;
   case DEFAULT_COP_SYMBOL:
     setPos(town, x, y);
     overCop = true;
     m_Dignity -= town.getDigLossCop();
     if(m_Dignity <= GONE_DIGNITY)
       setState(STATE_GONE);
     break;
   case ROOT_SYMBOL:
     setPos(town, x, y);
     *this += town.getArrRoot(town.getNumRoots()-1);
                                                     cout << "nth Root: "  << town.getNumRoots()-1 << endl;
     town.setNumRoots(town.getNumRoots()-2);
     if(m_Toxicity >= COOL_TOXICITY)
     {  
       setState(STATE_COOL);
                                       cout << " Current Toxicity: " << m_Toxicity 
                                       << "\n Ccoool one: " << COOL_TOXICITY
                                        <<"\nset to coooooooool   !!!!!!!!" << endl;
     }
     else if(m_Toxicity >= GONE_TOXICITY)
       setState(STATE_GONE);
     else
       setState(STATE_NORMAL);
     break; 
   default:
     break;   
      
 }
 return;
}

void Activist::setState(const short state)
{
  m_State = state;
  return;
}

Activist & Activist::operator+=(const root & rt)
{
  m_Toxicity += rt.getEffVal();  
  return *this;
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
