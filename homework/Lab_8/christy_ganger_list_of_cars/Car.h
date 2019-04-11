/*
Created by Christy Ganger
4/7/2019
cis 162c++
Lab 8
version 1
*/
#ifndef CAR_H
#define CAR_H
#include <string>
#include <iostream>

class Car
{
    public:
        Car(){make_of_car = "Ford", color_of_car = "Black", year_of_car = 1910;}
        virtual ~Car() {};
        Car(std::string color_of_car,std::string make_of_car, int year_of_car){
            this->make_of_car = make_of_car;
            this->color_of_car = color_of_car;
            this->year_of_car = year_of_car;
        }
        int getYear(){return year_of_car;}
        std::string getMake(){return make_of_car;}
        std::string getColor(){return color_of_car;}
        void setColor(std::string colour){color_of_car = colour;}
        void setMake(std::string make_of_car){this->make_of_car = make_of_car;}
        void setYear(int year_of_car){this->year_of_car = year_of_car;}

          friend bool operator==(const Car & car_compare, const Car & car_compare2 )
        {
            if (car_compare.make_of_car == car_compare2.make_of_car &&
                car_compare.color_of_car == car_compare2.color_of_car &&
                car_compare.year_of_car == car_compare2.year_of_car)
                    {
                        return true;
                    }

            return false;
        }

    friend std::ostream & operator<<(std::ostream & out, Car & car_out)
    {
        out << car_out.getYear()  << " " << car_out.getMake()
        << " " << car_out.getColor();
        return out;
    }

    protected:

    private:
        std::string make_of_car;
        std::string color_of_car;
        int year_of_car;
};

#endif // CAR_H
