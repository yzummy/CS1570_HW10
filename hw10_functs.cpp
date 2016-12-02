/*
   Programmers: Christopher O'Toole and Yunchao Zhang
   Date:
   File: hw10_functs.cpp
   Purpose:
*/

#include "hw10_functs.h"
#include <iomanip>
using namespace std;

void showPercentage(const float num, const short totNum)
{
  float percent;
  percent = num / totNum * 100;
  cout << setprecision(5) << percent << "%" << endl;
  return;
}

void runSimulation( const Config& config, float stat[])
{
  //***** Construction of Town
  Town town( config.gridSize );
  cout << "\nInitial look of the town:\n" << endl;
  cout << town << endl;
  town.setDigLossCop( config.numPtsLostForTalkingToCop );
  town.setDigLossWall( config.numPtsLostForWallCollision );

  //***** Declare and place Activist
  Activist lisa("Lisa");
  cout << "\nInitial look of Activist: \n" << endl;
  cout << lisa << endl;

  lisa.placeMeInMiddle(town);
  cout << "\nPlace activist in middle of town: \n" << endl;
  cout << town << endl;

  //***** Declare and place Polluter
  Polluter homer("Homer");
  homer.placeMe(town);
  cout << "Town after randomly placing a Polluter:\n" << endl;
  cout << town << endl;

  //***** Initilize and place roots and cops
  town.initRoot( config.numRoots);
  town.initCops( config.numCops );

  //***** Let activist and polluter move
  do
  {
    if(!homer.getCaughtStatus())
    {
      homer.randMove(town);
      cout << "~~~~~~~homer status: " << homer.getCaughtStatus() << endl;
    }
    lisa.move(town, homer.getPosX(), homer.getPosY());
                                                      cout << town << endl;
                                                      cout << lisa << endl;

  }while(lisa.getState() != STATE_GONE);

  stat[4] += lisa.getToxicity();
  switch(lisa.getResult())
  {
    case 0:
      stat[0]++;
      break;
    case 1:
      stat[1]++;
      break;
    case 2:
      stat[2]++;
      break;
    case 3:
      stat[3]++;
      break;
    default:
      break;
  }

}
