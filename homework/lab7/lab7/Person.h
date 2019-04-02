/*
Christy Ganger(wear)
CIS161c++
4/1/2019
Lab 7
Version 2
*/

#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <string>

class Person
{
    public:
        Person();
        Person(std::string, std::string, std::string);
        std::string getFirstName();
        void setFirstName(std::string);
        std::string getLastName();
        void setLastName(std::string);
        std::string getAddress();
        void setAddress(std::string);

    private:
        std::string First_Name;
        std::string Last_Name;
        std::string Address;
};

#endif // PERSON_H
