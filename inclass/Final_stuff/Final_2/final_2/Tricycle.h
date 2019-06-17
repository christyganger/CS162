#ifndef TRICYCLE_H
#define TRICYCLE_H

#include <Vehicle.h>


class Tricycle : public Vehicle
{
    public:
    wheels() {return NumWheels}

    protected:

    private:
        int NumWheels = 3
};

#endif // TRICYCLE_H
