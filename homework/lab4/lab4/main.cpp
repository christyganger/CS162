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
int binarySearch(int arr[], int l, int r, int x);
void getSize(int &cin_buff_size);
int* createArray(int cin_buff_size);
void sortArray(int* ptr_arr_new, int cin_buff_size);
void displayArray(const int* ptr_arr_new, int cin_buff_size);
int main()
{
srand(time(NULL));
int cin_buff_size;
        // get input
getSize(cin_buff_size);

int* ptr_arr_new = createArray(cin_buff_size);
sortArray(ptr_arr_new, cin_buff_size);
    //display
displayArray(ptr_arr_new, cin_buff_size);


//get in for 3
int what_to_find[3];

for(int n =0; n < 3; n++ )
 {
     // get input to search
     cout << "please enter digits to search array for: " << "\n";
     cin >> what_to_find[n];
    //binary search
       for(int p =0; p < 3; p++)
        {int result = binarySearch(ptr_arr_new, 0, cin_buff_size - 1, what_to_find[p]);
        (result == -1) ? cout << what_to_find[p] << " is not present in array"
                   : cout << what_to_find[p] << " is present at index " << result;
        cout << "\n";
        }
 }
// clear heap array memory
delete [] ptr_arr_new;
return 0;
}

int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;

        // If the element is present at the middle
        // itself
        if (arr[mid] == x)
            return mid;

        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);

        // Else the element can only be present
        // in right subarray
        return binarySearch(arr, mid + 1, r, x);
    }

    // We reach here when element is not
    // present in array
    return -1;
}

void getSize(int &cin_buff_size)
{
        cout << "please enter number of size of array you want, between 10 and 20: " << "\n";
        cin >> cin_buff_size;
}

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

void displayArray(const int* ptr_arr_new, int cin_buff_size)
{
    for(int j = 0; j < cin_buff_size; j++)
        cout << ptr_arr_new[j]<< "\n";
}
