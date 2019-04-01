#ifndef CREDITCARD_H
#define CREDITCARD_H
#include <iostream>
#include <string>

class CreditCard
{
    public:
        CreditCard(std::string person, std::string first, std::string last, std::string address, std::string CCNumber, int Climit);
        double getBalance();
        std::string getCardNumber();
        std::string getOwnerName();
        std::string getAddress();
        double payBalance(double);
        bool makeChange();
        void setCreditLimit(double);

    private:
        std::string person_internal;
        std::string First_Name;
        std::string Last_Name;
        std::string Address;
        std::string Card_Number;
        double Credit_Limit;
        double Balance;
};

#endif // CREDITCARD_H
