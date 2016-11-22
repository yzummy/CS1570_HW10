/*
  Programmer: Christopher O'Toole and Yunchao Zhang
  Date: 
  File: root.cpp
  Purpose: define functions for root.h
*/

#include "root.h"
using namespace;

root::root()
{
  bool isNeg = 0;
  if(rand() % 2)
    isNeg = 1;
  if(isNeg)
  {
    effVal = LOW_NEGATIVE + static_cast<float> (rand()) 
            / (static_cast<float> (RAND_MAX 
            / (HIGH_NEGATIVE - LOW_NEGATIVE)));
    type = NEG_TYPE;         
  }else
  {
    effVal = LOW_POSITIVE + static_cast<float> (rand())
            / (static_cast<float> (RAND_MAX
            / (HIGH_POSITIVE - LOW_POSITIVE)));
    type = POS_TYPE;
  }
}
