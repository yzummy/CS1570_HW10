/*
  Programmer: Christopher O'Toole and Yunchao Zhang
  Date: 
  File: root.cpp
  Purpose: define functions for root.h
*/

#include "root.h"
#include <cstdlib>
using namespace std;

root::root()
{
  bool isNeg = 0;
  if(rand() % 2)
    isNeg = 1;
  if(isNeg)
  {
    effVal = MIN_NEGATIVE + static_cast<float> (rand()) 
            / (static_cast<float> (RAND_MAX 
            / (MAX_NEGATIVE - MIN_NEGATIVE)));
    type = NEG_TYPE;         
  }else
  {
    effVal = MIN_POSITIVE + static_cast<float> (rand())
            / (static_cast<float> (RAND_MAX
            / (MAX_POSITIVE - MIN_POSITIVE)));
    type = POS_TYPE;
  }
}

string root::getType()
{
  return type;
}

float root::getEffVal()
{
  return effVal;
}
