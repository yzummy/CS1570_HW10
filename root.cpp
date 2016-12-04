/*
  Programmer: Christopher O'Toole and Yunchao Zhang
  Date:
  File: root.cpp
  Purpose:
*/

#include "root.h"
using namespace std;

double Root::getRandDouble( const double min, const double max )
{
  return min + ( max - min ) * ( static_cast<double>( rand( ) ) / RAND_MAX );
}

Root::Root( )
{
  // make effect positive or negative by chance
  if( rand( ) % 2 ) // make effect negative
  {
    effVal = -getRandDouble( MIN_NEGATIVE_VAL, MAX_NEGATIVE_VAL );
    type = NEG_TYPE;
  }
  else              // make effect positive
  {
    effVal = getRandDouble( MIN_POSITIVE_VAL, MAX_POSITIVE_VAL );
    type = POS_TYPE;
  }
}
