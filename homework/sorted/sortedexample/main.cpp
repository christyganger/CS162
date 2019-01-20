#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <algorithm>

using namespace std;

// defines to say what code is compiled
// see below where they are used
//#define LIN_SEARCH
#define LIN_SEARCH

// fill with random numbers from 1 to 100
void fillArray(int arr[], int theSize);
// find an items using linear search
bool linFind(int arr[], int theSize, int value);
// find an item using binary search
bool binFind(int arr[], int theSize, int value);
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

    int value;
    cout << "What number to look for? " << endl;
    cin >> value;

#ifdef LIN_SEARCH // include following code if LIN_SEARCH

        // search with linear find function
    cout << value << (linFind(theArray, SIZE, value)?" is":" is not") << " in the array" << endl;

#endif

#ifdef BIN_SEARCH // include following code if BIN_SEARCH

        // use standard sort to sort it
    sort(theArray, theArray+SIZE);
    display(theArray, SIZE);

        // sort with binary find function
    cout << value << (binFind(theArray, SIZE, value)?" is":" is not") << " in the array" << endl;

#endif

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

// linear search
bool linFind(int arr[], int theSize, int theValue)
{
    for(int i = 0; i < theSize; i++)
        if ( arr[i] == theValue )
            return true;
    return false;
}

// binary search
bool binFind(int arr[], int theSize, int theValue)
{
    int low = 0;
    int high = theSize - 1;

    while ( low < high )
    {
        int mid = (low + high) / 2;
        if ( arr[mid] == theValue )
            return true;
        if ( arr[mid] > theValue )
            high = mid - 1;
        if ( arr[mid] < theValue )
            low =  mid + 1;
    }

    return false;
}
