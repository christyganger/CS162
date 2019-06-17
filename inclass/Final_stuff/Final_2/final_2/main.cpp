#include <iostream>

using namespace std;

class Vehicle
{
    public:
       void setPrice(int PriceSet) { price = PriceSet;};
       int getPrice() {return price;};

       void setSpeed(int SpeedSet) {speed = SpeedSet;};
       int getSpeed() {return speed;};
       int wheels() {return 0;};

    protected:

    private:
        int price;
        int speed;
};



class Bicycle : public Vehicle
{
    public:
    wheels(){return NumWheels;};

    protected:

    private:
        int NumWheels = 2;
};

class Tricycle : public Vehicle
{
    public:
    wheels() {return NumWheels;};

    protected:

    private:
        int NumWheels = 3;
};

int main()
{
    Vehicle * arr[2];
    arr[0] = new Bicycle;
    arr[1] = new Tricycle;

    arr[0]->setPrice(500);
    arr[1]->setPrice(50);

    cout << "The bicycle costs " << arr[0]->getPrice() << " and has " << arr[0]->wheels() << " wheels " << endl;
    cout << "The tricycle costs " << arr[1]->getPrice() << " and has " << arr[1]->wheels() << " wheels " << endl;

    delete arr[0];
    delete arr[1];

    return 0;

}
