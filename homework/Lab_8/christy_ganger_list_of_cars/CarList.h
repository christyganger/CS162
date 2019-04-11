/*
Created by Christy Ganger
4/7/2019
cis 162c++
Lab 8
version 1
*/
#ifndef LIST_H
#define LIST_H
#include <string>
#include "Car.h"

struct Link {
    Car this_car;
    Link * next;

};
class CarList
{
    public:
        CarList();
        virtual ~CarList();
        void addCar(std::string, std::string, int);
        bool findCar(std::string, std::string, int);
        Car* removeHead();
        std::string displayList();

    protected:

    private:
       Link *head;
    bool recfind(Link * ptr, Car temp_car);
    void recDestruct(Link * ptr);
};

#endif // LIST_H
