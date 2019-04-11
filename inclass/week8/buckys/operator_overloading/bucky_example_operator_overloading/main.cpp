#include <iostream>
#include "Sally.h"
using namespace std;

int main()
{
    Sally a(55);
    Sally b(44);
    Sally c;

    c=a+b;

    cout << "A is " << a.num << "\n";
    cout << "B is " << b.num << "\n";
    cout << "C is " << c.num << "\n";
    return 0;
}
