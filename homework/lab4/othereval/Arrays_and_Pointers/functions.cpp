#include "function.h"

/*******************************
 *
 * Practice with Arrays and Pointers
 *
 * Finished Code By Lawrence Warner
 * CS 162 C++
 * Last Modified: 2/3/19
 *
 *******************************/

using namespace std;



// searches array for number

int binarySearch(const int* array_new, int l, int r, int x)

{

    if (r >= l)
    {
        int mid = l + (r - l) / 2;
        if (array_new[mid] == x)
            return mid;
        if (array_new[mid] > x)
            return binarySearch(array_new, l, mid - 1, x);
        return binarySearch(array_new, mid + 1, r, x);
    }
    // No number present in array
    return -1;

}

// asks user to input array size.

void getSize(int &user_size)

{
    bool done = false;
        do
        {
            cout << "\n";
            cout << " Welcome to my Practice with Arrays and Pointers Assignment" << "\n";
            cout << "\n";
            cout << " Please enter the size of array you want, between 10 and 20: ";
            cin >> user_size;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(2000, '\n');
                cout << " Error: BAD INPUT" << "\n\n\n\n";
            }
           if ((user_size <= 20) && (user_size >= 10))
                done = true;
        }while(!done);

}

// creates dynamically sized array

int* createArray(int user_size)

{
        cout << "\n";
        cout << " Creating an array of random numbers with size of " << user_size << "\n";

    // declare dynamic array
        int * array_new = new int[user_size];

    //fill array randomly
        for(int i = 0; i < user_size; i++)
        {
            array_new[i] = rand() % 100 + 1;
        }
    return array_new;
}

// sorts the new array

void sortArray(int* array_new, int user_size)

{
    // sort
    cout << " The Array is now sorting " << "\n";
        int k, l, min_m;
        for(k = 0; k < user_size-1; k++)
        {
            min_m = k;
            for (l = k+1; l < user_size; l++)
                if(array_new[l] < array_new[min_m])
                min_m = l;
            swap(array_new[min_m], array_new[k]);
        }

}

// display the numebrs in the array

void displayArray(const int* array_new, int user_size)

{
    cout << "\n";
    cout << " These are the " << user_size << " random numbers generated: " ;

    for(int j = 0; j < user_size; j++)
        cout << array_new[j]<< " ";
}

void get_numbers(int user_number[], const int number_search)

{
    cout << "\n" << "\n";
    cout << " Please enter 3 different numbers between 0 and 100 to look for, one at a time. " << "\n";

    for(int n =0; n < number_search; n++ )
    {
      bool done = false;

        do
        {

         // get input to search
            cout << " Please enter the " << n+1 << " number to search array for: ";
            cin >> user_number[n];

            if (cin.fail())
                {
                cin.clear();
                cin.ignore(2000, '\n');
                cout << "Error: BAD INPUT" << "\n\n\n";
                }
            else if ((user_number[n] <= 100) && (user_number[n] >= 0))
                {
                done = true;
                }
        }while(!done);

    }

}
