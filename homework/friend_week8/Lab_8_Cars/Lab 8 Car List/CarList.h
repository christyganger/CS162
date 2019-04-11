#ifndef CARLIST_H
#define CARLIST_H

/*******************************
 *
 * Cars List
 *
 * Finished Code By Lawrence Warner
 * CS 162 C++
 * Last Modified: 3/10/19
 *
 *******************************/

#ifndef CAR_H
#include "Car.h"
#endif // CAR_H

struct Link {
    Car car;
    Link * next;
};

class CarList
{
    private:
        Link *head;

        // recursive methods
        void recDestruct(Link * ptr);
        bool recFind(Link * ptr, Car searchCar);

    public:
        CarList();
        ~CarList();

        void addCar(string vhlMake, string vhlColor, int vhlYear);
        bool findCar(string vhlMake, string vhlColor, int vhlYear);
        Car* removeHead();
        string displayList();
};

#endif // CARLIST_H
