#include <iostream>
#include "Mother.h"
#include "Daughter.h"


using namespace std;
Daughter::Daughter()
{
    //ctor
}

void Daughter::doSomething()
{
    publicv = 54;
    protectedv = 55;

}
