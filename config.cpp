/*
   Programmers: Christopher O'Toole and Yunchao Zhang
   Date:
   File: config.cpp
   Purpose:
*/

#include "config.h"

Config::Config( const string& configFileName )
{
  ifstream in;
  openFile( in, configFileName );
  in >> gridSize >> numRoots >> numCops >> numDays
     >> numPtsLostForWall >> numPtsLostForCop;
}
