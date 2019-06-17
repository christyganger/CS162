#include "Instructor.h"

Instructor::Instructor(std::string New_Office_Hours)
{
    Set_Office_Hours(New_Office_Hours);
}

void Instructor::Set_Office_Hours(std::string New_Office_Hours)
{
    Office_Hours = New_Office_Hours;
}
