#ifndef CAR_H
#define CAR_H

/*******************************
 *
 * Cars List
 *
 * Finished Code By Lawrence Warner
 * CS 162 C++
 * Last Modified: 3/10/19
 *
 *******************************/

#include <string>
#include <iostream>
using namespace std;

class Car
{
    private:
        // Members
            string make, color;
            int year;

    public:

        // Constructors
            Car(){make = "Ford"; color = "Black" ; year = 1910;}
            Car(string vhlMake, string vhlColor, int vhlYear)
                { this->make = vhlMake; this->color = vhlColor; this->year= vhlYear; }

        // Setters
            void setMake(string vhlMake)      {this->make = vhlMake;}
            void setColor(string vhlColor)    {this->color = vhlColor;}
            void setYear(int vhlYear)         {this->year = vhlYear;}

        // Getters
            string getMake() const     {return this->make;}
            string getColor() const    {return this->color;}
            int    getYear() const     {return this->year;}

        // Equality class operator
friend bool operator==(const Car & lst, const Car & vhl);

        // Operator for Car class
friend ostream & operator<<(ostream & os,  const Car &vhl);

};

#endif // CAR_H
