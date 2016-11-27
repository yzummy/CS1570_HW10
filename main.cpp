/*
   Programmers: Christopher O'Toole and Yunchao Zhang
   Date:
   File: main.cpp
   Purpose:
*/

#include "hw10_functs.h"
#include "town.h"
#include "activist.h"
#include "polluter.h"
#include "root.h"
#include <iomanip>
using namespace std;

int main()
{
  ifstream config;
  short gridSize = 0;
  short numRoots = 0;
  short numCops = 0;
  short numDays = 0;
  short numPtsLostForWallCollision = 0;
  short numPtsLostForTalkingToCop = 0;
  float stat[numStats];
  srand(time(NULL));
  
  
  openFile( config, CONFIG );
  config >> gridSize >> numRoots >> numCops >> numDays
         >> numPtsLostForWallCollision >> numPtsLostForTalkingToCop;

  cout << gridSize << " " << numRoots << " " << numCops << " " << numDays
       << " " << numPtsLostForWallCollision << " "
       << numPtsLostForTalkingToCop << endl;
  
  for(int i = 0; i < numStats; i++)
    stat[i] = 0;
  
  for(int i = 0; i < numDays; i++)
  {
    runSimulation(gridSize, numRoots, numCops, 
                  numPtsLostForWallCollision, 
                  numPtsLostForTalkingToCop, stat);                  
  }
  
  //***** Print out stats
  cout << "\nSimulation Stats Report: " << endl;
  cout << " Percentage of Exits                   : "; 
  showPercentage(stat[0], numDays);
  cout << " Percentage of becoming wacked out     : ";
  showPercentage(stat[1], numDays);
  cout << " Percentage of catching the polluter   : ";
  showPercentage(stat[2], numDays);
  cout << " Percentage of death by loss of dignity: ";
  showPercentage(stat[3], numDays);
  cout << " Average toxicity when day is done     : "
       << setprecision(5) << stat[4] / numDays << endl;
  for(int i = 0; i < numStats; i++)
  {
    cout << "~~i: " << stat[i] << endl;
  }
  cout << "num of days: " << numDays  << endl;

  
  
    
  return 0;
}
