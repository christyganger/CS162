/*
// Lab 4 written by christy wear.
// version 1
// thanks for bin search from https://www.geeksforgeeks.org/binary-search/
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

int binarySearch(const int* ptr_arr_new, int l, int r, int x);
void getSize(int &cin_buff_size);
int* createArray(int const cin_buff_size);
void sortArray(int* ptr_arr_new, const int cin_buff_size);
void displayArray(const int* ptr_arr_new, const int cin_buff_size);
void get_search_numbers(int what_to_find[], const int how_many_to_search);

int main()
{
srand(time(NULL));
int cin_buff_size;

// get input
getSize(cin_buff_size);
// make array
int* ptr_arr_new = createArray(cin_buff_size);
// sort array
sortArray(ptr_arr_new, cin_buff_size);
    //display
displayArray(ptr_arr_new, cin_buff_size);

int how_many_to_search = 3;
//get in for 3
int what_to_find[how_many_to_search];
// loop 3 times input
get_search_numbers(what_to_find,how_many_to_search);

 //binary search 3 times
for(int p =0; p < how_many_to_search; p++)
{
    int result = binarySearch(ptr_arr_new, 0, cin_buff_size - 1, what_to_find[p]);
    (result == -1) ? cout << what_to_find[p] << " is not present in array"
           : cout << what_to_find[p] << " is present at index " << result;
    cout << "\n";
}

// clear heap array memory
delete [] ptr_arr_new;
return 0;
}

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
    for(int j = 0; j < cin_buff_size; j++)
        cout << ptr_arr_new[j]<< "\n";
}

void get_search_numbers(int what_to_find[], const int how_many_to_search)
{
 for(int n =0; n < how_many_to_search; n++ )
 {
     // get input to search
     cout << "please enter digits to search array for: " << "\n";
     cin >> what_to_find[n];
 }
}
