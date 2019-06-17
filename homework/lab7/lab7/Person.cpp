/*
Christy Ganger(wear)
CIS161c++
4/1/2019
Lab 7
Version 3
*/


#include "Person.h"

Person::Person()
{
    //default
}

Person::Person(std::string First_Name, std::string Last_Name, std::string Address)
{
    setFirstName(First_Name);
    setLastName(Last_Name);
    setAddress(Address);
}

std::string Person::getFirstName()
{
    return First_Name;
}

void Person::setFirstName(std::string set_account_first_name)
{
    First_Name = set_account_first_name;
}

std::string Person::getLastName()
{
    return Last_Name;
}

void Person::setLastName(std::string set_account_last_name)
{
    Last_Name = set_account_last_name;
}

std::string Person::getAddress()
{
    //stub
    return Address;
}

void Person::setAddress(std::string set_account_Address)
{
    Address = set_account_Address;
}
