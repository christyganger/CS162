//Find and fix the problems with this program

#include <iostream>

using namespace std;

class Demo {
     private:
          int value;
     public:
          int getValue() { return value; }
          void setValue(int value) { value = value; }
};

void display( const Demo & d )
{
     cout << d.getValue() << endl;
}

void getInput( const Demo & d )
{
     cout << "Enter an integer";
     cin >> value;
     d.setValue(value);
}

int main()
{
    Demo sue;

    sue.getinput();
    sue.display();

    return 0;
}
