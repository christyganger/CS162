#include <iostream>

using namespace std;

class Car{
    string model;
    string color;
    static int counter;
public:
    Car(string model, string color);
    Car();

    void setModel(string model);
    void setColor(string color);

    string getModel();
    string getColor();

    static int getCounter() { return counter; }
    const static int SIZE = 100;
    static Car* cars[SIZE];
};

int main()
{
    Car * myCar = new Car;
    Car * truck = new Car("Pickup", "Rusty");

    for(int i = 0; i < Car::getCounter(); i++)
        cout << Car::cars[i]->getColor() << " " << Car::cars[i]->getModel() << endl;
        cout << Car::getCounter() << "\n"; //added by christy

    delete myCar; //added by christy
    delete truck; //added by christy
    return 0;
}

// code for class
int Car::counter = 0;
Car* Car::cars[Car::SIZE];

Car::Car(string model, string color)
{
    this->model = model;
    this->color = color;

    cars[counter] = this;
    counter++;
}
Car::Car()
{
    model = "Ford";
    color = "Black";

    cars[counter] = this;
    counter++;
}

void Car::setModel(string m)
{
    model = m;
}
void Car::setColor(string c)
{
    color = c;
}

string Car::getColor()
{
    return color;
}
string Car::getModel()
{
    return model;
}
