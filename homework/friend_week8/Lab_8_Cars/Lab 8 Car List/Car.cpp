#include "Car.h"

/*******************************
 *
 * Cars List
 *
 * Finished Code By Lawrence Warner
 * CS 162 C++
 * Last Modified: 3/10/19
 *
 *******************************/

// Equality class operator
    bool operator==(const Car & lst, const Car & vhl)
    {
        bool result  = ( lst.make == vhl.make && lst.color == vhl.color && lst.year == vhl.year);
        return result;
    }

// Operator for Car class
    ostream & operator<<(ostream & os,  const Car &vhl)
    {
        os << vhl.make << " " << vhl.color << " " << vhl.year;
        return os;
    }
