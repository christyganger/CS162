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
 cout << "Now searching for the numbers you entered." << "\n";
for(int p =0; p < how_many_to_search; p++)
{
    int result = binarySearch(ptr_arr_new, 0, cin_buff_size - 1, what_to_find[p]);
    (result == -1) ? cout << what_to_find[p] << " is not present in array"
           : cout << what_to_find[p] << " is present at index " << result;
    cout << "\n";
}

// clear heap array memory
delete [] ptr_arr_new;
cout << "Because Microsoft Windows maintains a vacuum on phallic objects even in non vacuum, Press enter to exit." << "\n";
std::cin.clear(); std::cin.ignore(INT_MAX, '\n');
std::cin.get();
return 0;
}

