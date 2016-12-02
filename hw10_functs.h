/*
   Programmers: Christopher O'Toole and Yunchao Zhang
   Date:
   File: hw10_functs.h
   Purpose:
*/

#ifndef HW10_FUNCTS_H
#define HW10_FUNCTS_H

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "config.h"
#include "town.h"
#include "activist.h"
#include "polluter.h"
#include "root.h"
using namespace std;

// Desc:
// Pre:
// Post:

void runSimulation( const Config& config, float stat[]);

// Desc:
// Pre:
// Post:

void showPercentage(const float num, const short totNum);

#endif
