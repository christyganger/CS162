#include "Borrito.h"
#include <iostream>
#include <string>

using namespace std;

Borrito::Borrito()
{

}
Borrito::Borrito(string z)
{
    setName(z);
}

void Borrito::setName(string x)
{
    name = x;
}

string Borrito::getName()
{
    return name;
}
