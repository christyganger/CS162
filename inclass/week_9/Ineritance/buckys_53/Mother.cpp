#include <iostream>
#include "Mother.h"
#include "Daughter.h"



Mother::Mother()
{
    //ctor
}

void Mother::sayName()
{
    std::cout << "CHRISTY!!!" << "\n";

}

void Mother::get_protectedv()
{
    std::cout << protectedv << "\n";
}

void Mother::set_protectedv(int tempint)
{
    protectedv = tempint;
}

