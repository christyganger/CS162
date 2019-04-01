#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <string>

class Person
{
    public:
        Person();
        Person(std::string First_Name, std::string Last_Name, std::string Address);
        std::string get_First_Name();
        void set_First_Name();
        std::string get_Last_Name();
        void set_Last_Name();
        std::string get_Address();
        void set_Address();

    private:
        std::string First_Name;
        std::string Last_Name;
        std::string Address;
};

#endif // PERSON_H
