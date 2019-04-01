#include <iostream>
#include <string>
#include "CreditCard.h"
using namespace std;


CreditCard::CreditCard(string person, string first, string last, string address, string CCNumber, int Climit)
{
    person_internal = person;
    First_Name = first;
    Last_Name = last;
    Address = address;
    Card_Number = CCNumber;
    Credit_Limit = Climit;
}

double CreditCard::getBalance()
{
    //no idea where this comes from so for now.. answer to universe
    return 42;
}

string CreditCard::getCardNumber()
{
    return this->Card_Number;
}

string CreditCard::getOwnerName()
{
    return this->First_Name + this->Last_Name;
}

string CreditCard::getAddress()
{
    return this->Address;
}

double CreditCard::payBalance(double)
{
    //what??
    return 42;
}

bool CreditCard::makeChange()
{
    bool have_not_done_this_part_yet = true;
    return have_not_done_this_part_yet;
}

void CreditCard::setCreditLimit(double)
{

}
