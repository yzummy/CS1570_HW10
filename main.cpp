/*
   Programmers: Christopher O'Toole and Yunchao Zhang
   Date:
   File: main.cpp
   Purpose:
*/

#include "hw10_functs.h"

int main()
{
  Config config( CONFIG_FILE_NAME ); // config file object
  SimulationStat stats[NUM_STATS] = // array of simulation stat objecs.
  {
    { "\tActivist exited and got caught by the EPA : ", true,  0 },
    { "\tActivist became wacked out                : ", true,  0 },
    { "\tActivist successfully caught the polluter : ", true,  0 },
    { "\tActivist died by loss of dignity          : ", true,  0 },
    { "\tAverage toxicity when day is done         : ", false, 0 }
  };

  // set numDays for each SimulationStat object.
  SimulationStat::numDays = config.numDays;

  // set the static members of the town class
  Town::numPtsLostForCop = config.numPtsLostForCop;
  Town::numPtsLostForWall = config.numPtsLostForWall;

  // initialize pseudo random number generator
  srand( time( NULL ) );

  if ( DEBUG )
    debugRunSimulation( config );
  else // run simulation for the number of days set by the config file
  {
    for ( int i = 0; i < config.numDays; i++ )
      runSimulation( config, stats );

    // print out stats
    cout << "\nSimulation Statistics (percentages signify the percent of "
         << "simulated days that something occurs)" << endl;

    for( int i = 0; i < NUM_STATS; i++ )
      cout << stats[i] << endl;
  }

  return 0;
}
