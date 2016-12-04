/*
  Programmers: Christopher O'Toole and Yunchao Zhang
  Date:
  File: root.h
  Purpose:
*/

#ifndef ROOT_H
#define ROOT_H

#include <cstdlib>
#include <string>
using namespace std;

const string POS_TYPE = "truffle";
const string NEG_TYPE = "square";

const float MIN_NEGATIVE_VAL = 0.001;
const float MAX_NEGATIVE_VAL = 0.01;

const float MIN_POSITIVE_VAL = 0.05;
const float MAX_POSITIVE_VAL = 0.1;

const char ROOT_CHAR = 'R';

class Root
{
  private:
    string type;
    float effVal;

    double getRandDouble( const double min, const double max );

  public:
    Root( );
    string getType() const { return type; }
    float getEffVal() const { return effVal; }
};

#endif
