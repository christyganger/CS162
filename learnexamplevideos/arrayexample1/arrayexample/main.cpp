#include <iostream>

using namespace std;

int main()
{
    int sizes = 5;
    int bucky[sizes] = {66,75,2,43,99};

    // prints field 4 for bucky starts with 0 cout << bucky[3] << "\n";
    for (int i = 0; i < sizes; i++)
    {
      cout << bucky[i] << " this is index " << i << " and is the " << i+1 << " number"<< "\n";
    }
    return 0;

}
