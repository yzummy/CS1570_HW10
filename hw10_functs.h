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
using namespace std;

// configuration data file name
const char CONFIG[] = "config.dat";

// Desc: The openFile() function opens a stream given a fileName.
// Pre:  T is of type ifstream or ofstream
//       If T is of type ifstream, the file referred to by fileName must exist.
// Post: fileIn is opened in the calling function and connected to the
//    specified file.

template <typename T>
void openFile( T& fileIn, const char fileName[] )
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

// Desc:
// Pre:
// Post:

void runSimulation( );

#endif
