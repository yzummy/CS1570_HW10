/*
   Programmers: Christopher O'Toole and Yunchao Zhang
   Date:
   File: hw10_functs.h
   Purpose:
*/

#ifndef HW10_FUNCTS_H
#define HW10_FUNCTS_H

#include <ctime>
#include "config.h"
#include "town.h"
#include "activist.h"
#include "polluter.h"
using namespace std;

const short TOXICITY_STAT = 4;
const bool DEBUG = false;

struct SimulationStat
{
  string desc;
  bool showAsPercent;
  float val;

  static short numDays;

  // Desc:
  // Pre:
  // Post:

  friend ostream& operator<<( ostream& os, const SimulationStat& stat );
};

// Desc:
// Pre:
// Post:

void runSimulation( const Config& config, SimulationStat stats[] );

void debugSetConsoleCursorPos( const short x, const short y );
void debugRunSimulation( const Config& config );

#endif
