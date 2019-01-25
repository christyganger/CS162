#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

// fill with random numbers from 1 to 100
void fillArray(int arr[], int theSize);
// sort from smallest to largest
void mySort(int arr[], int theSize);
// display, five numbers per line
void display(int arr[], int theSize);

int main()
{
    srand(static_cast<int>(time(NULL)));
    
    const int SIZE = 20;
    int theArray[SIZE];
    
    fillArray(theArray, SIZE);
    cout << "Unsorted: " << endl;
    display(theArray, SIZE);
    cout << "Sorted:" << endl;
    mySort(theArray, SIZE);
    display(theArray, SIZE);

    return 0;
}
// fill with random numbers from 1 to 100
void fillArray(int arr[], int theSize)
{
    for(int i = 0; i < theSize; i++)
        arr[i] = rand() % 100 + 1;
}

// display the array, five items per line
void display(int arr[], int theSize)
{
    const int NUMS_PER_ROW = 5;
    int counter = 0;
    for(int i = 0; i < theSize; i++)
    {
        cout << setw(6) << arr[i];
        counter++;
        if (counter >= NUMS_PER_ROW)
        {
            counter = 0;
            cout << endl;
        }
    }
}

// using selection sort to sort from smallest to largest
void mySort(int arr[], int theSize)
{
    
}


