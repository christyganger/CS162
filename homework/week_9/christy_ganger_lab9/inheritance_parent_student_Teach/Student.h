#ifndef STUDENT_H
#define STUDENT_H
#include "Person.h"

class Student
{
    public:
        Student();
        ~Student();
        void Set_GPA(float);
        float Get_GPA(){return GPA;};
        std::string GetJob(){return "Student";};
    protected:

    private:
        float GPA;
};

#endif // STUDENT_H
