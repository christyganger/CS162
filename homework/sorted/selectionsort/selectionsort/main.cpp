/*
* this is a modified version of https://www.youtube.com/watch?v=iMH2BgOnu60
to demonstrate selection sort
*/

#include <iostream>  // couts
#include <ctime> // for time
#include <cstdlib> // srand

using namespace std;

void display( int arr[], int size)
{
    for(int i=0; i<size; i++)
    {
        cout << arr[i] << " ";
    }
}

void selection_sort(int arr[], int size)
{

    int first, temp;
    for(int i =size-1; i > 0; i--)   {
        first = 0;

        cout << "checking order of numbers for the " << i << " time(s)" << "\n";

        for(int j=1; j<=i; j++)  {
             display(arr, size);
        cout << "\n";
            cout << " is " << arr[j] << " larger than   "<< arr[first] << "\n";
            if(arr[j] > arr[first])
                    {
                cout << " decided " << arr[j] << " is larger than " << arr[first] << "\n";

                first = j;

            }

            temp = arr[first];

            arr[first]=arr[i]; /

            arr[i]=temp;
        cout << "\n\n\n\n\n";
        }
    }
}

int main()
{
    const int size = 10;
    int numbers[size];
    srand(unsigned(time(0)));
    for(int i = 0; i < size; i++)
    {
        numbers[i] = (rand() % 10) +1;
        cout << numbers[i] << " ";

    }
    cout << "\n";

    selection_sort(numbers, size);
    display(numbers, size);
    return 0;
}
