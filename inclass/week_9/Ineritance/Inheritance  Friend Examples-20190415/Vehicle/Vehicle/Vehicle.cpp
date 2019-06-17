#include "Vehicle.h"

Vehicle Vehicle::operator++()
{
    ++speed;
    return *this;
}

Vehicle Vehicle::operator++(int)
{
    Vehicle temp = *this;
    speed++;
    return temp;
}


bool Airplane::setSpeed(float s)
{
    bool speedSet = false;
    if (altitude < 1500 || s > stallSpeed)
    {
        speed = s;
        speedSet = true;
    }
    return speedSet;
}
