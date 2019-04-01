#include <iostream>
#include "Hannah.h"
using namespace std;
Hannah::Hannah(int num):h(num)
{

}

void Hannah::printCrap()
{
    cout << "h=" << h << "\n";
    cout << "this->h=" << this->h << "\n";
    cout << "(*this).h=" << (*this).h << "\n";

}
