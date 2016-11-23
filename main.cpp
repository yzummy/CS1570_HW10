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
  Town t(15);
  t.initRoot(10);
  for(int i=0;i<10;i++)
  {
   cout << "type: " << t.getArrRoot(i).getType()
        << "eff: " << t.getArrRoot(i).getEffVal() << endl;
  }
  cout << t;
  
  return 0;
}
