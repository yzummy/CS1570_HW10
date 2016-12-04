/*
   Programmers: Christopher O'Toole and Yunchao Zhang
   Date:
   File: town.cpp
   Purpose: Definitions of functions pertaining to the Town class that manage
         access to the town's grid.
*/

#include "town.h"
#include <cstdlib>
using namespace std;

int Town::numPtsLostForCop = 0;
int Town::numPtsLostForWall = 0;

Town::Town( const Config& config, const short maxDimUsed )
: m_MaxDimUsed( maxDimUsed ),
  m_NumRoots( config.numRoots ),
  m_NumCops( config.numCops )
{
  // make sure maxDimUsed is valid before initializing object members
  if ( maxDimUsed <= 0 || maxDimUsed > TOWN_MAX_DIM )
  { // if not, display error and exit.
    cout << "The maxDimGrid param must be > 0 and <= " << TOWN_MAX_DIM << "!"
         << endl;
    exit( -1 );
  }

  if ( m_NumRoots < 0 || m_NumRoots > MAX_NUM_ROOTS )
  {
    cout << "The number of roots must be >= 0 and <= " << MAX_NUM_ROOTS
         << "!" << endl;
  }

  if ( m_NumCops < 0 )
    cout << "The number of cops must be positive or 0!" << endl;

  clear( ); // clear usable grid space
  build( ); // build walls and exits of town
}

void Town::clear( )
{
  // initialize town grid
  for ( int i = 0; i < m_MaxDimUsed; ++i )
    for ( int j = 0; j < m_MaxDimUsed; ++j )
      m_Grid[i][j] = TOWN_EMPTY_SPACE;
  return;
}

void Town::build( )
{
  // midpoint of x/y coordinate
  const int mid = m_MaxDimUsed / 2;

  // create walls
  for ( int i = 0; i < m_MaxDimUsed; ++i )
  {
    m_Grid[0][i] = m_Grid[i][0] = TOWN_WALL_CHAR;
    m_Grid[m_MaxDimUsed - 1][i] = m_Grid[i][m_MaxDimUsed - 1] = TOWN_WALL_CHAR;
  }

  // place roots
  for( int i = 0; i < m_NumRoots; ++i )
    setGridAt( getRandPointInGrid( ), ROOT_CHAR );

  // place cops
  for ( int i = 0; i < m_NumCops; ++i )
    setGridAt( getRandPointInGrid( ), TOWN_COP_CHAR );

  // set exits
  m_Grid[0][mid] = TOWN_EXIT_CHAR; // top
  m_Grid[mid][0] = TOWN_EXIT_CHAR; // left
  m_Grid[m_MaxDimUsed - 1][mid] = TOWN_EXIT_CHAR; // bottom
  m_Grid[mid][m_MaxDimUsed - 1] = TOWN_EXIT_CHAR; // right

  return;
}

const Point<int>& Town::getRandPointInGrid( )
{
  static Point<int> point;

  do
    point.setPos( rand( ) % m_MaxDimUsed, rand( ) % m_MaxDimUsed );
  while( !isGridEmptyAt( point ) );

  return point;
}

bool Town::isWithinGrid( const Point<int>& pos ) const
{
  // are coordinates passed within used grid space?
  return pos.getX( ) >= 0 && pos.getY( ) >= 0 &&
         pos.getX( ) < m_MaxDimUsed && pos.getY( ) < m_MaxDimUsed;
}

void Town::setGridAt( const Point<int>& pos, const char symbol )
{
  // are coordinates within the usable m_grid array?
  if ( isWithinGrid( pos ) )
    m_Grid[pos.getX( )][pos.getY( )] = symbol;
  else // display an error and terminate if they aren't
  {
    cout << "SET Could not set grid at " << pos << endl;
    exit( -1 );
  }

  return;
}

char Town::getGridAt( const Point<int>& pos ) const
{
  char val;

  // are coordinates within the usable m_grid array?
  if ( isWithinGrid( pos ) )
    val = m_Grid[pos.getX( )][pos.getY( )];
  else // display an error and terminate if they aren't
  {
    cout << "GET Could not get grid value at " << pos << "!" << endl;
    exit( -1 );
  }

  return val;
}

bool Town::isGridEmptyAt( const Point<int>& pos ) const
{
  // is grid empty at given coordinates?
  return getGridAt( pos ) == TOWN_EMPTY_SPACE;
}

Root& Town::getNextRoot( )
{
  if ( m_NumRoots <= 0 )
  {
    cout << "There are no more roots left to get!" << endl;
    exit( -1 );
  }

  return m_Roots[--m_NumRoots];
}

ostream& operator<<( ostream& os, const Town& town )
{
  // print out town grid
  for ( int i = 0; i < town.m_MaxDimUsed; ++i )
  {
    os << TOWN_GRID_SEP;

    for ( int j = 0; j < town.m_MaxDimUsed; ++j )
      os << town.m_Grid[i][j] << TOWN_GRID_SEP;

    os << "\n";
  }

  return os;
}
