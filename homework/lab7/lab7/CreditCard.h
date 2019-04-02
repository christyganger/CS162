/*
Christy Ganger(wear)
CIS161c++
4/1/2019
Lab 7
Version 2
*/


#ifndef CREDITCARD_H
#define CREDITCARD_H
#include <iostream>
#include <string>
#include "Person.h"

class CreditCard
{
    public:
        //CreditCard();
        CreditCard(std::string, std::string, std::string, double, int);
        double getBalance();
        double getCardNumber();
        std::string getOwnerName();
        std::string getAddress();
        bool payBalance(double);
        bool makeCharge(double);
        void setCreditLimit(double);

    private:
        Person obj_for_data;
        double Card_Number = 0;
        double Credit_Limit = 0;
        double Balance = 0;
};

#endif // CREDITCARD_H
