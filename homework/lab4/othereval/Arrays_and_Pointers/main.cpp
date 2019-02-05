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





int main()

{

srand(time(NULL));

int user_size;



// get input

    getSize(user_size);

// make array

    int* array_new = createArray(user_size);

// sort array

    sortArray(array_new, user_size);

//display

    displayArray(array_new, user_size);

    int number_search = 3;

//get 3 numbers

    int user_number[number_search];

// loop 3 times

    get_numbers(user_number,number_search);

//binary search 3 times

cout << "\n";
cout << " Now searching for the numbers you entered." << "\n";

    for(int p =0; p < number_search; p++)

{

    int result = binarySearch(array_new, 0, user_size - 1, user_number[p]);

    (result == -1) ? cout << " " << user_number[p] << " is not in array!"

    : cout << " " << user_number[p] << " is in the array! ";

    cout << "\n";

}



// clear memory

        delete [] array_new;

    std::cin.get();

return 0;

}

