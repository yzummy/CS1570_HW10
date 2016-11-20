/*
   Programmer: Christopher O'Toole
   Date: 11/13/2016
   File: town.cpp
   Purpose: Definitions of functions pertaining to the Town class that manage
         access to the town's grid.
*/

#include "Town.h"

Town::Town( const short maxDimUsed ) : m_MaxDimUsed( maxDimUsed )
{
  // make sure maxDimUsed is valid before initializing object members
  if ( maxDimUsed <= 0 || maxDimUsed > TOWN_MAX_DIM )
  { // if not, display error an exit.
    cout << "The maxDimGrid param must be > 0 and < " << TOWN_MAX_DIM << "!"
         << endl;
    exit( -1 );
  }

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
  // midpoint x/y coordinate
  const int mid = m_MaxDimUsed / 2;

  // create top and bottom walls
  for ( int i = 0; i < m_MaxDimUsed; ++i )
  {
    m_Grid[0][i] = TOWN_WALL_CHAR;
    m_Grid[m_MaxDimUsed - 1][i] = TOWN_WALL_CHAR;
  }

  // create left and right walls
  for ( int i = 0; i < m_MaxDimUsed; ++i )
  {
    m_Grid[i][0] = TOWN_WALL_CHAR;
    m_Grid[i][m_MaxDimUsed - 1] = TOWN_WALL_CHAR;
  }

  // set exits
  m_Grid[0][mid] = TOWN_EXIT_CHAR; // top
  m_Grid[mid][0] = TOWN_EXIT_CHAR; // left
  m_Grid[m_MaxDimUsed - 1][mid] = TOWN_EXIT_CHAR; // bottom
  m_Grid[mid][m_MaxDimUsed - 1] = TOWN_EXIT_CHAR; // right

  return;
}

bool Town::isWithinGrid( const int x, const int y ) const
{
  // are coordinates passed within used grid space?
  return x > 0 && y > 0 && x < m_MaxDimUsed && y < m_MaxDimUsed;
}

void Town::setGridAt( const int x, const int y, const char symbol )
{
  // are coordinates within the usable m_grid array?
  if ( isWithinGrid( x, y ) )
    m_Grid[x][y] = symbol;
  else // display an error and terminate if they aren't
  {
    cout << "Could not set grid at ( " << x << ", " << y << " )!" << endl;
    exit( -1 );
  }

  return;
}

char Town::getGridAt( const int x, const int y ) const
{
  char val;

  // are coordinates within the usable m_grid array?
  if ( isWithinGrid( x, y ) )
    val = m_Grid[x][y];
  else // display an error and terminate if they aren't
  {
    cout << "Could not get grid value at ( " << x << ", " << y << " )!"
         << endl;
    exit( -1 );
  }

  return val;
}

bool Town::isGridEmptyAt( const int x, const int y ) const
{
  // is grid empty at given coordinates?
  return getGridAt( x, y ) == TOWN_EMPTY_SPACE;
}

ostream& operator<<( ostream& os, const Town& town )
{
  // print out town array
  for ( int i = 0; i < town.m_MaxDimUsed; ++i ) // for each row
  {
    os << TOWN_GRID_SEP;

    for ( int j = 0; j < town.m_MaxDimUsed; ++j ) // for each column
    {
      // print char at pos in grid and separate
      os << town.m_Grid[i][j];
      os << TOWN_GRID_SEP;
    }

    os << endl;
  }

  return os;
}