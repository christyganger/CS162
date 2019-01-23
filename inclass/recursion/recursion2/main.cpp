#include <iostream>

using namespace std;

bool LinFind(int arr[], int size, int value)
{
    for(int i = 0; i< size; i++)
    {if (arr[i] == value)
        {return true;}
    }
        return false;
}
int main()
{
    int arr[] = {1,3,5,7,9,11,13,15,17,19,21,23};
int value;
    do
    {
        cout << "enter number" << "\n";

        cin >> value;
        if(LinFind(arr, 12, value))
            cout << "found" << "\n";
        else
            cout << "not found" << "\n";
    }
    while (value != 0);
    return 0;
}
