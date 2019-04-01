#include <iostream>
#include "Borrito.h"
#include <string>

using namespace std;

int main()
{
    Borrito bo;
    Borrito bo2("testing");
    bo.setName("hi");
    cout << bo.getName() << "\n";
    cout << bo2.getName() << "\n";

    return 0;
}
