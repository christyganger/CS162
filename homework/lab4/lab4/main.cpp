#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main()
{
    srand(time(NULL));

    int cin_buff_size;

    // get input
    cout << "please enter number of size of array you want, between 10 and 20: " << "\n";
    cin >> cin_buff_size;
    // declare dynamic array
    int * ptr_arr_new = new int[cin_buff_size];
    //fill array randomly
        for(int i = 0; i < cin_buff_size; i++)
        {
            ptr_arr_new[i] = rand() % 100 + 1;
        }

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

    //display
    for(int j = 0; j < cin_buff_size; j++)
        cout << ptr_arr_new[j]<< "\n";

//get in for 3
int what_to_find[3];
cout << "please enter digits to search array for: " << "\n";
for(int n =0; n < 3; n++ )
    cin >> what_to_find[n];

    //binary search

        for(int p =0; p < 3; p++)
        {
            int mid = 0;
            int low = 0;
            int high = 0;
            high = cin_buff_size -1;
            mid = cin_buff_size / 2;
            bool done_with_find = false;
            while(!done_with_find)
            {
            if(what_to_find[p] > ptr_arr_new[mid])
            {
                low = mid + 1;

                mid = (low+ high) / 2;


            }
            if(what_to_find[p] < ptr_arr_new[mid])
            {

                high = mid-1;
                mid = (low+ high)/2;

            }
            if(what_to_find[p] == ptr_arr_new[mid])
            {
                done_with_find=true;
                cout << "found " << what_to_find[p] << "\n";

            }
            if(mid == cin_buff_size -1 || mid == 0)
            {
                cout << p << " not found" << "\n";
                done_with_find = true;

            }
            }
        }

    // clear heap array memory
    delete [] ptr_arr_new;
    return 0;
}
