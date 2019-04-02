#include <iostream>
#include <string>
#include "CreditCard.h"
using namespace std;

int main()
{
    bool done = false;
    // default test cast
    CreditCard newcard("christy", "ganger", "123 no", 11112222333344444, 50000);
    do
    {



    cout << "Hello " << newcard.getOwnerName() << "\n";
    cout << "welcome to Bank of Awesome" << "\n";
    cout << "The Credit card number " << newcard.getCardNumber() << "\n";
    cout << "Has a balance of " << newcard.getBalance() << "\n";

    char reply_q_1 = '\0';
    cout << "Are you charging something to your card? (y/n):" << "\n";
    cin >> reply_q_1;
    double charge = 0;
    if (reply_q_1 == 'y')
    {
        cout << "Please Type how much you would like to charge to your credit card: " << "\n";
        cin >> charge;
        bool successful_charge = false;
        successful_charge = newcard.makeCharge(charge);
        if (successful_charge == false)
        {
            cout << "transaction failed, not enough in your account." << "\n";
        }
        if (successful_charge == true)
        {
            cout << "Transaction successful." << "\n";
        }
    }

    cout << "would you like to make a payment? (y/n)" << "\n";
    char reply_q_2 = '\n';
    cin >> reply_q_2;
    double payment = 0;
    if (reply_q_2 == 'y')
    {
        cout << "Please type how much you'd like to pay off of your balance" << "\n";
        cin >> payment;
        bool successful_payment = false;
        successful_payment = newcard.payBalance(payment);
        if (successful_payment == false)
        {
            cout << "Negative Payments not allowed." << "\n";
        }
        if (successful_payment == true)
        {
            cout << "Payment accepted, balance will be updated" << "\n";
        }
    }
    char reply_q_3 = '\n';
    cout << "Would you like another transaction?" << "\n";
    cin >> reply_q_3;
    if(reply_q_3 == false)
    {
        done = true;
    }

    }while(!done);
    return 0;
}

