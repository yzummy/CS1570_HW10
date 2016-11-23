/*
  Programmers: Christopher O'Toole and Yunchao Zhang
  Date: 
  Instructor: Clayton Price
  File: root.h
  Purpose: define root class
*/

#ifndef ROOT_H
#define ROOT_H

#include <iostream>
using namespace std;

const string POS_TYPE = "truffle";
const string NEG_TYPE = "square";
const float MIN_NEGATIVE = -0.01;
const float MAX_NEGATIVE = -0.001;
const float MIN_POSITIVE = 0.05;
const float MAX_POSITIVE = 0.1;
const char ROOT_SYMBOL = 'R';

class root
{
private:
  string type;
  float effVal;
  
public:
  root();
  string getType();
  float getEffVal();     
};

#endif
