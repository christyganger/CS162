#include <iostream>

using namespace std;

int summer(int value)
{
    if (value == 0)
        return 0;
    return value+ summer(value-1);
}

int iterative(int value)
{
    int sum = 0;
    for(int i = value; i >=0; i--)
        sum+=i;
    return sum;
}
int main()
{
    cout << summer(100) << "\n";
    cout << iterative(100) << "\n";
    return 0;
}
