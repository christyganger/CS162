/*
// Lab 4 written by christy wear.
// version 1.4
// thanks for bin search from https://www.geeksforgeeks.org/binary-search/
// Special thanks to michelle wear for testing.
// *feedback version 1.1: not sure whats going on..
// *response, added more couts.
// *feedback version 1.2: window closes can't see output
// *response, added windows appreciation for phallic objects to hold open window.
// *feedback version 1.3: I dont understand why i'm entering digit
// *response: Added, comments as to what that portion is doing
// update version 1.4: split functions to functions.cpp, added includes to header along with prototypes to clean up the program
*/

#include "function_header.h"

using namespace std;

// searches array for number
int binarySearch(const int* ptr_arr_new, int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;

        // If the element is present at the middle
        // itself
        if (ptr_arr_new[mid] == x)
            return mid;

        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (ptr_arr_new[mid] > x)
            return binarySearch(ptr_arr_new, l, mid - 1, x);

        // Else the element can only be present
        // in right subarray
        return binarySearch(ptr_arr_new, mid + 1, r, x);
    }

    // We reach here when element is not
    // present in array
    return -1;
}

// asks user to input array size.
void getSize(int &cin_buff_size)
{
        bool done = false;
        do
        {
            cout << "please enter number of size of array you want, between 10 and 20: " << "\n";
            cin >> cin_buff_size;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(2000, '\n');
                cout << "BAD INPUT" << "\n";
            }
           if ((cin_buff_size <= 20) && (cin_buff_size >= 10))
                done = true;

        }while(!done);
}


// creates dynamically sized array
int* createArray(int cin_buff_size)
{
    cout << " Creating an array of random numbers with size of " << cin_buff_size << "\n";

    // declare dynamic array
    int * ptr_arr_new = new int[cin_buff_size];
    //fill array randomly
        for(int i = 0; i < cin_buff_size; i++)
        {
            ptr_arr_new[i] = rand() % 100 + 1;
        }


return ptr_arr_new;
}

// sorts the new array
void sortArray(int* ptr_arr_new, int cin_buff_size)
{
    // sort
    cout << "The Array is now sorting" << "\n";
        int k, l, min_m;
        for(k = 0; k < cin_buff_size-1; k++)
        {
            min_m = k;
            for (l = k+1; l < cin_buff_size; l++)
                if(ptr_arr_new[l] < ptr_arr_new[min_m])
                min_m = l;

            swap(ptr_arr_new[min_m], ptr_arr_new[k]);
        }
}

// display the numebrs in the array
void displayArray(const int* ptr_arr_new, int cin_buff_size)
{
    cout << "\n\n\n\n\n";
    cout << "These are the " << cin_buff_size << " random numbers generated" << "\n";
    for(int j = 0; j < cin_buff_size; j++)
        cout << ptr_arr_new[j]<< "\n";
}

void get_search_numbers(int what_to_find[], const int how_many_to_search)
{
    cout << "Searching the " << how_many_to_search << " number's that where randomly generated." << "\n";
    cout << " I need you to enter 3 different numbers between 0 and 100 to look for, one at a time. " << "\n";
 for(int n =0; n < how_many_to_search; n++ )
 {
      bool done = false;
        do
        {
         // get input to search
         cout << "please enter the " << n+1 << " number to search array for: " << "\n";
         cin >> what_to_find[n];
         if (cin.fail())
            {
                cin.clear();
                cin.ignore(2000, '\n');
                cout << "BAD INPUT" << "\n";
            }


                if ((what_to_find[n] <= 100) && (what_to_find[n] >= 0))
                {
                    done = true;
                }

        }while(!done);
 }
}
