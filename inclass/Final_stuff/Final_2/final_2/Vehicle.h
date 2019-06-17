#ifndef VEHICLE_H
#define VEHICLE_H


class Vehicle
{
    public:
        setPrice(int PriceSet) { price = PriceSet;};
        getPrice() {return price;};

        setSpeed(int SpeedSet) {speed = SpeedSet;};
        getSpeed() {return speed;};
        virtual wheels() {return NumWheels;};
    protected:

    private:
        int price;
        int speed;
};

#endif // VEHICLE_H
