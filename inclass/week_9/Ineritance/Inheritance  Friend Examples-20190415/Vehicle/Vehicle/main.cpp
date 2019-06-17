#include <iostream>
#include "Vehicle.h"
using namespace std;

int main()
{
    // Test the vehicle class
    Vehicle myVehicle;
    cout << myVehicle.getSpeed() << endl;
    cout << myVehicle.getDirection() << endl;
    myVehicle.setSpeed(1000);
    myVehicle.setDirection(90);
    cout << "Speed: " << myVehicle.getSpeed() << endl;
    cout << "Direction: " << myVehicle.getDirection() << endl;

    // Test the airplane class
    Airplane g6;
    g6.setSpeed(700);
    g6.setDirection(180);
    cout << "G6 is going " << g6.getSpeed() << " mph"
         << ", direction: " << g6.getDirection() << endl;

    // Thes the stall avoidance system (aka Airplane::setSpeed)
    g6.setAltitude(30000);
    cout << "G6 altitude: " << g6.getAltitude() << endl;
    cout << "Speed set: " << g6.setSpeed(50) << endl;
    cout << "G6 speed: " << g6.getSpeed() << endl;
    g6.setAltitude(1000);
    cout << "Speed set: " << g6.setSpeed(50) << endl;
    cout << "G6 speed: " << g6.getSpeed() << endl;

    // Test the overloaded operators
    cout << "Prefix ++ " << (++g6).getSpeed() << endl;
    cout << "G6 speed: " << g6.getSpeed() << endl;
    cout << "Postfix ++ " << g6++.getSpeed() << endl;
    cout << "G6 speed: " << g6.getSpeed() << endl;

    // Make a copy using the default copy constructor
    Airplane gulfstream(g6);
    cout << "Gulfstream is going " << gulfstream.getSpeed() << " mph"
         << ", direction: " << gulfstream.getDirection() << endl;

    return 0;
}





