/*
Christy Ganger(wear)
CIS161c++
4/1/2019
Lab 7
Version 3
*/


#include <iostream>
#include <string>
#include "CreditCard.h"
using namespace std;

/*
CreditCard::CreditCard()
{
    //default
}
*/

CreditCard::CreditCard(string first, string last, string address, int CCNumber, double Climit)
{
    obj_for_data.setFirstName(first);
    obj_for_data.setLastName(last);
    obj_for_data.setAddress(address);
    Card_Number = CCNumber;
    Credit_Limit = Climit;

}

double CreditCard::getBalance()
{
    //no idea where this comes from so for now.. answer to universe
    return Balance;
}

int CreditCard::getCardNumber()
{
    return Card_Number;
}

std::string CreditCard::getOwnerName()
{
   std::string TEMP;
   TEMP = (obj_for_data.getFirstName() + " " + obj_for_data.getLastName());
   return TEMP;
}

std::string CreditCard::getAddress()
{
    return obj_for_data.getAddress();
}

bool CreditCard::payBalance(double payment_on_balance)
{
    bool is_valid = false;
    if(payment_on_balance  > 0)
    {
        Balance = (Balance-payment_on_balance);
        is_valid = true;
    }
    else
    {
        is_valid = false;
    }
    return is_valid;
}

bool CreditCard::makeCharge(double charge_amount)
{
    bool is_valid_transation = false;
    if(Balance+charge_amount <= Credit_Limit && charge_amount > 0)
    {
        Balance = (Balance+charge_amount);
        is_valid_transation = true;
    }
    else
    {
        is_valid_transation = false;
    }

    return is_valid_transation;
}

void CreditCard::setCreditLimit(double new_credit_limit)
{
    if(new_credit_limit >= 0)
       {
            Credit_Limit = new_credit_limit;
       }
}
