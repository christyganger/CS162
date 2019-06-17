#include <iostream>
#include "Mother.h"
#include "Daughter.h"



Mother::Mother()
{
    std::cout << "I am the mother constructor!" << "\n";
}

Mother::~Mother()
{
    std::cout << "Mother's Decostructor!" << "\n";
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

