#include "CarList.h"
#include <sstream>

/*******************************
 *
 * Cars List
 *
 * Finished Code By Lawrence Warner
 * CS 162 C++
 * Last Modified: 3/10/19
 *
 *******************************/

// constructor
    CarList::CarList()
    {
        head = nullptr;
    }

// destructor
    CarList::~CarList()
    {
        recDestruct(head);
    }

// destruct list
    void CarList::recDestruct(Link * ptr)
    {
        if ( ptr )
        {
            recDestruct(ptr->next);
            delete ptr;
        }
    }

// recursive search of the list
    bool CarList::recFind(Link * ptr, Car searchCar)
    {
        if ( ptr == nullptr )
            return false;
        if (ptr->car == searchCar )
            return true;
        return recFind(ptr->next, searchCar);
    }

// creates a new heap
    void CarList::addCar(string vhlMake, string vhlColor, int vhlYear)
    {
        Link * tempLink = new Link;
        tempLink->car.setMake(vhlMake);
        tempLink->car.setColor(vhlColor);
        tempLink->car.setYear(vhlYear);
        tempLink->next =  head;
        head = tempLink;
    }

// looks for a car on the list
    bool CarList::findCar(string vhlMake, string vhlColor, int vhlYear)
    {
        Car searchCar(vhlMake, vhlColor, vhlYear);
        return recFind(head, searchCar);
    }

// remove item from head and return its value
    Car* CarList::removeHead()
    {
            if ( head == nullptr )
            return nullptr;
            Link * tempLink = head;
            head = head->next;
            return  & tempLink->car;
    }

// build a string uses overloaded extraction operator in Car
string CarList::displayList()
    {
        stringstream buffer;

        // start at head
            Link * ptr = head;
            while ( ptr )
            {
                buffer << ptr->car << ", ";
                ptr = ptr->next;
            }
            return buffer.str();
    }
