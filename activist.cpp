/*
   Programmers: Christopher O'Toole and Yunchao Zhang
   Date:
   File: activist.cpp
   Purpose: Definitions of functions which control the behavior
        of an activist within a town object's grid.
*/

#include "activist.h"

Activist::Activist( const string name, const char symbol )
: m_Pos( DEFAULT_POS, DEFAULT_POS ),
  m_State( STATE_NORMAL ),
  m_Symbol( symbol ),
  m_Dignity( DEFAULT_DIGNITY ),
  m_Toxicity( DEFAULT_TOXICITY ),
  m_Name( name ),
  m_Result( 0 ),
  m_OverCop( false )
{
}

void Activist::setPos( Town& town, const Point<int>& pos )
{
  char collidedWith = handleCollision( town, pos );

  if ( collidedWith != TOWN_WALL_CHAR )
  {
    if ( town.isWithinGrid( m_Pos ) )
    {
      town.setGridAt( m_Pos, m_OverCop ? TOWN_COP_CHAR : TOWN_EMPTY_SPACE );
      m_OverCop = false;
    }

    if ( town.getGridAt( pos ) == TOWN_COP_CHAR )
      m_OverCop = true;

    m_Pos.setPos( pos.getX( ), pos.getY( ) );
    town.setGridAt( pos, m_Symbol );
  }

  return;
}

void Activist::placeMeInMiddle( Town& town )
{
  const Point<int> mid( town.getMaxDimUsed( ) / 2, town.getMaxDimUsed( ) / 2 );
  setPos( town, mid );

  return;
}

void Activist::randMove( Town& town )
{
  Point<int> newPos = m_Pos.randMove( );
  setPos( town, newPos );

  return;
}

void Activist::smartMove( Town& town, const Point<int>& polluterPos )
{
  Point<int> newPos = m_Pos.moveTowards( polluterPos );
  setPos( town, newPos );

  return;
}

void Activist::move( Town& town, const Point<int>& polluterPos )
{
  if ( !isInactive( ) )
  {
    if ( m_State == STATE_NORMAL )
      smartMove( town, polluterPos );
    else
      randMove( town );
  }

  return;
}

char Activist::handleCollision( Town& town, const Point<int>& pos )
{
  const char charAtPos = town.getGridAt( pos );

  if ( !town.isGridEmptyAt( pos ) )
  {
    if ( charAtPos == TOWN_COP_CHAR )
      m_Dignity -= town.numPtsLostForCop;
    else if ( charAtPos == TOWN_WALL_CHAR )
      m_Dignity -= town.numPtsLostForWall;
    else if ( charAtPos == TOWN_EXIT_CHAR )
      m_Result = RESULT_EXITED;
    else if ( charAtPos == POLLUTER_DEFAULT_SYMBOL )
      m_Result = RESULT_CAUGHT_POLLUTER;
    else if ( charAtPos == ROOT_CHAR )
    {
      ( *this ) += town.getNextRoot( );

      if ( m_State == STATE_GONE )
        m_Result = RESULT_GONE;
    }

    if ( m_Dignity <= 0 )
      m_Result = RESULT_DEATH_BY_LOSS_OF_DIGNITY;
  }

  return ( charAtPos == TOWN_EMPTY_SPACE ? 0 : charAtPos );
}

Activist& Activist::operator+=( const Root& root )
{
  m_Toxicity += root.getEffVal( );

  if ( m_Toxicity < COOL_TOXICITY )
    m_State = STATE_NORMAL;
  else if ( m_Toxicity >= COOL_TOXICITY && m_Toxicity < GONE_TOXICITY )
    m_State = STATE_COOL;
  else if ( m_Toxicity >= GONE_TOXICITY )
    m_State = STATE_GONE;

  return *this;
}

ostream& operator<<( ostream& os, const Activist& activist )
{
  string state;

  // convert integer state representation to string
  switch( activist.m_State )
  {
    case STATE_NORMAL: state = "normal"; break;
    case STATE_COOL:   state = "cool";   break;
    case STATE_GONE:   state = "gone";   break;
  }

  // print object to stream
  os << "Position: " << activist.m_Pos << endl
     << "State: " << state << endl
     << "Symbol: '" << activist.m_Symbol << "'" << endl
     << "Dignity: " << activist.m_Dignity << endl
     << "Toxicity: " << activist.m_Toxicity << endl
     << "Name: " << activist.m_Name;

  return os;
}
