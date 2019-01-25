/*
* modified from https://www.youtube.com/watch?v=oJ2qutVomG8
*/

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

void display(int arr[], int size)

{
    for(int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}
void insertion_sort(int arr[], int size)
{
    int j, temp;
    for(int i = 1; i < size; i++)
    {
        j=i;
        while(j > 0 && arr[j-1] > arr[j]) // (3, 2)
        {
            temp = arr[j];
            arr[j] = arr[j-1]; // swap number
            arr[j-1] = temp; // goes to next number
            j--;
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
       numbers[i] = (rand() % 10 +1) ;
       cout << numbers[i] << " ";
   }
   cout << "\n";
   insertion_sort(numbers, size);
    display(numbers, size);

    return 0;
}
