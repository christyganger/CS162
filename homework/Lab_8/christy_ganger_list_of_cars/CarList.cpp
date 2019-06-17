/*
Created by Christy Ganger
4/7/2019
cis 162c++
Lab 8
version 2
*/
#include "CarList.h"
#include "Car.h"
#include <string>
#include <sstream>


//default const
CarList::CarList()
{
    head = nullptr;
}

//virtual deconstructor
CarList::~CarList()
{
    recDestruct(head);
}

//adds value to a link
void CarList::addCar( std::string color, std::string make, int year)
{
    Link * tempLink = new Link;
    tempLink->this_car.setMake(make);
    tempLink->this_car.setColor(color);
    tempLink->this_car.setYear(year);
    tempLink->next = head;

    head = tempLink;
}


//nuke the list
void CarList::recDestruct(Link * ptr)
{
    if ( ptr )
        {
            recDestruct(ptr->next);

            delete ptr;
        }
}

//find the car helper
bool CarList::findCar( std::string color, std::string make, int year)
{

    Car temp_car(color,make,year);

        return recfind(head, temp_car);
}

// deletes the head
Car* CarList::removeHead()
{
    //empty
        if (head == nullptr)
            return nullptr;
        // not empty
        Link * tempLink = head;
        //update head
        head = head->next;

        return &tempLink->this_car;
}

//actually finds the car
bool CarList::recfind(Link * ptr, Car temp_car)
{
    //empty
        if (ptr == nullptr)
            return 0;
        // not empty
       if (ptr->this_car == temp_car)
        {return true;}
       return recfind(ptr->next, temp_car);
}

std::string CarList::displayList()
{
    std::stringstream buffer;

    //start at the head
    Link * ptr = head;

    // continue until at the end
    while( ptr != nullptr )
    {
        // get the value from the object pointed to by this link
       buffer << ptr->this_car;

        // update pointer
        ptr = ptr->next;

        //if not at end add comma to string
        if (ptr)
            buffer << ", ";
    }
    //return the string
    return buffer.str();
}

