/*
   Programmers: Christopher O'Toole and Yunchao Zhang
   Date:
   File: hw10_functs.cpp
   Purpose:
*/

#include "hw10_functs.h"

short SimulationStat::numDays = 0;

ostream& operator<<( ostream& os, const SimulationStat& stat )
{
  const float statValPerDay = stat.val / stat.numDays;

  os << stat.desc;

  if ( stat.showAsPercent )
    os << statValPerDay * 100 << "%";
  else
    os << statValPerDay;

  return os;
}

void runSimulation( const Config& config, SimulationStat stats[] )
{
  static int timesCalled = 0;

  Town town( config, config.gridSize );
  Activist lisa( "Lisa" );
  Polluter homer( "Homer" );

  lisa.placeMeInMiddle( town );
  homer.placeMe( town );

  do
  {
    homer.randMove(town);
    lisa.move( town, homer.getPos( ) );
    if ( !timesCalled ) cout << town << endl;
  } while( !lisa.isInactive( ) );

  stats[TOXICITY_STAT].val += lisa.getToxicity( );
  ++stats[lisa.getInactiveState( ) - 1].val;
  ++timesCalled;

  return;
}

#include <windows.h>
#define WIN32_LEAN_AND_MEAN

void debugSetConsoleCursorPos( const short x, const short y )
{
  static const HANDLE output = GetStdHandle( STD_OUTPUT_HANDLE );
  COORD pos = { x, y };
  SetConsoleCursorPosition( output, pos );
}

void debugRunSimulation( const Config& config )
{
  Town town( config, config.gridSize );
  Activist lisa( "Lisa" );
  Polluter homer( "Homer" );

  lisa.placeMeInMiddle( town );
  homer.placeMe( town );

  do
  {
    homer.randMove(town);
    lisa.move( town, homer.getPos( ) );

    cout << town << endl;

    Sleep( 500 );
    debugSetConsoleCursorPos( 0, 0 );
  } while( !lisa.isInactive( ) );

  return;
}
