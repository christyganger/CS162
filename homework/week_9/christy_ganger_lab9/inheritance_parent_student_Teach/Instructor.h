#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H
#include "Person.h"

class Instructor : public Person
{
    public:
        Instructor(std::string);
        ~Instructor(){};
    void Set_Office_Hours(std::string);
    void SetFirstName(){instruct_P->SetFirstName(std::string)};
    std::string Get_Office_Hours(){return Office_Hours;};
    std::string GetJob(){return "Instructor";};
    protected:

    private:
        std::string Office_Hours;

};

#endif // INSTRUCTOR_H
