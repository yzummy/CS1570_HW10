/*
   Programmers: Christopher O'Toole and Yunchao Zhang
   Date:
   File: config.h
   Purpose:
*/

#ifndef CONFIG_H
#define CONFIG_H

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// configuration data file name
const string CONFIG_FILE_NAME = "config.dat";
const short NUM_STATS = 5;

struct Config
{
  short gridSize;
  short numRoots;
  short numCops;
  short numDays;
  short numPtsLostForWall;
  short numPtsLostForCop;
  float stat[NUM_STATS];

  Config( const string& configFileName );
};

// Desc: The openFile() function opens a stream given a fileName.
// Pre:  T is of type ifstream or ofstream
//       If T is of type ifstream, the file referred to by fileName must exist.
// Post: fileIn is opened in the calling function and connected to the
//    specified file.

template <typename T>
void openFile( T& fileIn, const string& fileName )
{
  fileIn.open( fileName );

  if ( !fileIn )
  {
    // print out error message and exit on failure to open file
    cout << "Error opening file " << fileName << "!" << endl;
    exit( -1 );
  }

  return;
}

#endif
