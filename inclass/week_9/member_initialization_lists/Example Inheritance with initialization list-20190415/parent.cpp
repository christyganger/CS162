#include "parent.h"
Parent::Parent()
{
    cout << "constructing parent" << "\n";
}
~Parent::Parent()
{
    cout << "deconstructing parent" << "\n";
}
Parent::Parent(std::string n, int a)
{
    name = n;
    age = a;
}

std::string Parent::getName()
{
    return name;
}

int Parent::getAge()
{
    return age;
}

void Parent::setName(std::string n)
{
    name = n;
}

void Parent::setAge(int a)
{
    age = a;
}
