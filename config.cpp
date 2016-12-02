#include "config.h"

Config::Config( const string& configFileName )
{
  ifstream in;
  openFile( in, configFileName );
  in >> gridSize >> numRoots >> numCops >> numDays
     >> numPtsLostForWallCollision >> numPtsLostForTalkingToCop;
}
