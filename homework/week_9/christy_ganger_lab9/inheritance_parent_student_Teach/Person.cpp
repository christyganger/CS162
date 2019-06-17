#include "Person.h"
Person::Person()
    {
        SetFirstName("");
        SetLastName("");
        SetAge(0);
        SetLnumber("");
    }
Person::Person(std::string Incoming_New_FirstName, std::string Incoming_New_LastName, int Incoming_New_Age, std::string Incoming_New_Lnumber)
    {
        SetFirstName(Incoming_New_FirstName);
        SetLastName(Incoming_New_LastName);
        SetAge(Incoming_New_Age);
        SetLnumber(Incoming_New_Lnumber);
    }

