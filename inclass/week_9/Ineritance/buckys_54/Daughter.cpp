#include <iostream>
#include "Mother.h"
#include "Daughter.h"


using namespace std;
Daughter::Daughter()
{
    cout << "I am the Daughter's constructor" << "\n";
}

Daughter::~Daughter()
{
    std::cout << "Daughter's Deconstructor!" << "\n";
}

void Daughter::doSomething()
{
    publicv = 54;
    protectedv = 55;

}
