#include <iostream>
#include "Sally.h"

Sally::Sally()
{
    //ctor
}

Sally::Sally(int a)
{
    num = a;
}

Sally Sally::operator+(Sally aso)
{
    Sally brandNew;
    brandNew.num = num + aso.num;
    return(brandNew);
}
