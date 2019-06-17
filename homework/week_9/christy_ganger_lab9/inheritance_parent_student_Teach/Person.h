#ifndef PERSON_H
#define PERSON_H
#include <string>

class Person
{
    public:
        Person();
        ~Person(){};
        Person(std::string, std::string,int ,std::string);
        void SetFirstName(std::string New_FirstName){FirstName = New_FirstName;};
        void SetLastName(std::string New_LastName){LastName = New_LastName;};
        void SetAge(int New_Age){Age = New_Age;};
        void SetLnumber(std::string New_Lnumber){Lnumber = New_Lnumber;};

        std::string Get_FirstName(){return FirstName;};
        std::string Get_LastName(){return LastName;};
        int Get_Age(){return Age;};
        std::string Get_Lnumber(){return Lnumber;};
        std::string Get_Job(){return "Undefined";};

    protected:

    private:
        std::string FirstName;
        std::string LastName;
        int Age;
        std::string Lnumber;
};

#endif // PERSON_H
