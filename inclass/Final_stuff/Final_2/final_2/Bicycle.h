#ifndef BICYCLE_H
#define BICYCLE_H

#include <Vehicle.h>


class Bicycle : public Vehicle
{
    public:
    wheels(){return NumWheels;}

    protected:

    private:
        int NumWheels = 2;
};

#endif // BICYCLE_H
