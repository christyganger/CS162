#ifndef VEHICLE_H_INCLUDED
#define VEHICLE_H_INCLUDED
#include <iostream>
using namespace std;

// Base class
class Vehicle
{
    protected:
    float speed;
    int direction;

    public:
    Vehicle() { speed = 0; direction = 0; }
    float getSpeed() { return speed; }
    int getDirection() { return direction; }
    void setSpeed(float s) { speed = s; }
    void setDirection(int d) { direction = d; }
    Vehicle operator++();   // increment the speed, pretfix
    Vehicle operator++(int);   // increment the speed, postfix
    ~Vehicle() { /*cout << "In destructor\n"; */}
};

// Subclass (inherits from Vehicle)
class Airplane:public Vehicle
{
    float altitude;
    float stallSpeed;

    public:
    Airplane() { altitude = 0; stallSpeed = 100; }
    float getAltitude() {return altitude; }
    void setAltitude(float a) { altitude = a; }
    bool setSpeed(float s);     // Overrides setSpeed in base class
    ~Airplane() { /*cout << "In Airplane destructor\n";*/ }
};












#endif // VEHICLE_H_INCLUDED
