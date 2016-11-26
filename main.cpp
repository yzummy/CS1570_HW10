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
  srand(time(NULL));
  
  
  openFile( config, CONFIG );
  config >> gridSize >> numRoots >> numCops >> numDays
         >> numPtsLostForWallCollision >> numPtsLostForTalkingToCop;

  cout << gridSize << " " << numRoots << " " << numCops << " " << numDays
       << " " << numPtsLostForWallCollision << " "
       << numPtsLostForTalkingToCop << endl;
  
  //*** Construction of Town
  Town t(gridSize);
  cout << "\nTown initially looks like this:\n";
  cout << t << endl;
  t.setDigLossCop(numPtsLostForTalkingToCop);
  t.setDigLossWall(numPtsLostForWallCollision);
  
  
  //*** Construction and functionality of Activist & Town
  Activist lisa("Lisa");
  cout << "\nActivist initially looks like this:\n";
  cout << lisa << endl;
  
  lisa.placeMeInMiddle(t);
  cout << "\nAfter placing Activist in middle of town:\n";
  cout << t << endl;
  
  //*** Moves
  cout << "MOVESSSS MOVESSSS mOVESSSS" << endl;
  lisa.randMove(t);
  cout << t << endl;
  
  //***Polluter
  Polluter homer("Homer");
  homer.placeMe(t);
  cout << "Town after randomly placing a Polluter:\n";
  cout << t << endl;
  
  for(int i = 0; i < 5; i++)
  {
    cout << "MovesSSS MOVESSS" << endl;
    homer.randMove(t);
    cout << t << endl;
  }


  // put roots and cops
  t.initRoot(numRoots);
                                        cout << "initialized nth roots: " << numRoots << endl;
  t.initCops(numCops);
  for(int i=0;i<numRoots;i++)
  {
   cout << "type: " << t.getArrRoot(i).getType()
        << " eff: " << t.getArrRoot(i).getEffVal() << endl;
  }
  
  // move with roots and cops
  for(int i = 0; i < 10; i++)
  {
    cout << "MovesSSS MOVESSS activist" << endl;
    lisa.move(t, homer.getPosX(), homer.getPosY());
    cout << t << endl;
    cout << lisa << endl;
  }



  
  
  cout << t;
  
  return 0;
}
