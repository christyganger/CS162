#include <iostream>
#include "complex.h"

using namespace std;

int main()
{
    complex object_1(4);
    complex object_2(6);

        // display initial values of 4 and 6
    cout << object_1.getValue() << " " << object_2.getValue() << "\n";
    cout << object_1.getAddress() << " " << object_2.getAddress() << "\n";
        //copy object_1 to object_2 and show they ar eboth 4
    object_2 = object_1;
    cout << object_1.getValue() << " " << object_2.getValue() << "\n";
    cout << object_1.getAddress() << " " << object_2.getAddress() << "\n";
        // change object_2 and see that they are now 4 and 7
    object_2.setValue(7);
    cout << object_1.getValue() << " " << object_2.getValue() << "\n";
    cout << object_1.getAddress() << " " << object_2.getAddress() << "\n";
    return 0;

}
