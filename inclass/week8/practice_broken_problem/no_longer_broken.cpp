//Broken Program
//Find and fix the problems with this program

#include <iostream>

using namespace std;

class Demo {
     private:
          int value;
     public:
          int getValue() const { return value; }
          void setValue(int value) { this->value = value; }
};

void display( const Demo & d )
{
     cout << d.getValue() << endl;
}

void getInput( Demo & d )
{
     int value;
     cout << "Enter an integer";
     cin >> value;
     d.setValue(value);
}

int main()
{
    Demo sue;

    getInput(sue);
    display(sue);


    return 0;
}
