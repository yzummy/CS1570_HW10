/*
   Programmers: Christopher O'Toole and Yunchao Zhang
   Date:
   File: point.h
   Purpose:
*/

#ifndef POINT_H
#define POINT_H

#include <cstdlib>
using namespace std;

const int UP = 0;
const int RIGHT = 1;
const int LEFT = 2;
const int DOWN = 3;
const int MAX_DIRECTION_ID = 3;

template <class T>
class Point
{
  public:
    //Desc:
    //Pre:
    //Post:

    Point( ) : m_X( 0 ), m_Y( 0 ) { }

    //Desc:
    //Pre:
    //Post:

    Point( const T& x, const T& y ) : m_X( x ), m_Y( y ) { }

    //Desc:
    //Pre:
    //Post:

    void setPos( const T& x, const T& y ) { m_X = x; m_Y = y; }

    //Desc:
    //Pre:
    //Post:

    const T& getX( ) const { return m_X; }

    //Desc:
    //Pre:
    //Post:

    const T& getY( ) const { return m_Y; }

    //Desc:
    //Pre:
    //Post:

    Point<T> randMove( ) const;

    //Desc:
    //Pre:
    //Post:

    Point<T> moveTowards( const Point<T>& pos ) const;

    //Desc:
    //Pre:
    //Post:

    friend ostream& operator<<( ostream& os, const Point<T>& point )
    {
      os << "( " << point.m_X << ", " << point.m_Y << " )";
      return os;
    }

  private:
    T m_X;
    T m_Y;
};

template <typename T>
Point<T> Point<T>::randMove( ) const
{
  Point<T> temp( *this );

  switch( rand( ) % ( MAX_DIRECTION_ID + 1 ) )
  {
  case UP:    temp.m_Y -= 1; break;
  case DOWN:  temp.m_Y += 1; break;
  case RIGHT: temp.m_X += 1; break;
  case LEFT:  temp.m_X -= 1; break;
  }

  return temp;
}

template <class T>
Point<T> Point<T>::moveTowards( const Point<T>& pos ) const
{
  Point<T> temp( *this );

  if ( temp.m_X > pos.getX( ) )
    temp.m_X -= 1;
  else if ( temp.m_X < pos.getX( ) )
    temp.m_X += 1;
  else if ( temp.m_Y > pos.getY( ) )
    temp.m_Y -= 1;
  else if ( temp.m_Y < pos.getY( ) )
    temp.m_Y += 1;

  return temp;
}

#endif
