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

  openFile( config, CONFIG );
  config >> gridSize >> numRoots >> numCops >> numDays
         >> numPtsLostForWallCollision >> numPtsLostForTalkingToCop;

  cout << gridSize << " " << numRoots << " " << numCops << " " << numDays
       << " " << numPtsLostForWallCollision << " "
       << numPtsLostForTalkingToCop << endl;

  return 0;
}
