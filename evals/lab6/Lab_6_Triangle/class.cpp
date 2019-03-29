#include "header.hpp"

/*******************************
 *
 * Triangle Class
 *
 * Finished Code By Lawrence Warner
 * CS 162 C++
 * Last Modified: 2/21/19
 *
 *******************************/

void Triangle::setA(int set_A)
    {
        A = set_A;
    }

void Triangle::setB(int set_B)
    {
        B = set_B;
    }

void Triangle::setC(int set_C)
    {
        C = set_C;
    }

int Triangle::getA()
    {
        return A;
    }

int Triangle::getB()
    {
        return B;
    }

int Triangle::getC()
    {
        return C;
    }

bool Triangle::isEquilateral()
    {
       if(A == B and B == C)
        {
            return true;
       }
       else return false;
    }

bool Triangle:: isScalene()
    {
       if( A != B and B != C and A != C)
        {
            return true;
       }
       else return false;
    }

bool Triangle::isIsosceles()
    {
      if(A == B or A == C)
      {
          return true;
          }
     else return false;
    }

bool Triangle::isRight()
    {
      if( ((A*A) + (B*B)) == (C*C) )
        {
            return true;
        }
      else return false;
    }
