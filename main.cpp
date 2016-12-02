/*
   Programmers: Christopher O'Toole and Yunchao Zhang
   Date:
   File: main.cpp
   Purpose:
*/

#include "hw10_functs.h"
#include "config.h"
#include "town.h"
#include "activist.h"
#include "polluter.h"
#include "root.h"
using namespace std;

int main()
{
  Config config( CONFIG_FILE_NAME );
  float stat[NUM_STATS] = { 0 };
  const string statDesc[] =
  {
    " Percentage of Exits                   : ",
    " Percentage of becoming wacked out     : ",
    " Percentage of catching the polluter   : ",
    " Percentage of death by loss of dignity: ",
    " Average toxicity when day is done     : "
  };

  srand( time( NULL ) );

  /*
  for( int i = 0; i < config.numDays; i++ )
    runSimulation( config, stat );
  */

  //***** Print out stats
  cout << "\nSimulation Stats Report: " << endl;

  for( int i = 0; i < NUM_STATS; i++ )
  {
    cout << statDesc[i];

    if ( i < NUM_STATS - 1 )
      showPercentage( stat[i], config.numDays );
    else
      cout << stat[4] / config.numDays << endl;
  }

  return 0;
}
