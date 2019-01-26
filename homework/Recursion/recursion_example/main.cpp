#include <iostream>

using namespace std;

int recursive_fact(int start, int result)
{
if ( start <= 0 )
return result;
result *= start;
cout << "In function, result is " << result << endl;
return recursive_fact(start-1, result);
}

bool recursive_linear(int arr[], int size, int index, int value)
{
    if ( index == size )
        return false;
    if ( arr[index] == value )
    return true;
return recursive_linear(arr, size, ++index, value);
}

bool recursive_search(int theArray[], int lower, int upper, int value)
{
if ( lower > upper )
return false;
int index = (lower + upper) / 2;
if ( theArray[index] == value )
return true;
if ( theArray[index] > value )
return recursive_search(theArray, lower, index - 1, value);
else
return recursive_search(theArray, index + 1, upper, value);
}

int main()
{
    // factorial example
    const int LIMIT = 6;
    int result = 1;
    for(int i = LIMIT; i > 0; i--)
    {
        result = result * i;
        cout << "In loop, result is " << result << endl;
    }
    cout << "When done, result is "<< result << endl;

    //factorial example with recursion
    result = 1;
    result = recursive_fact(LIMIT, result);
    cout << "When done, result is "<< result << endl;

    //linear search example
    const int SIZE = 6;
    int arr[SIZE] = {1, 6, 2, 12, 19, -1};
    bool found = false;
    //int value = 12;
    int value = 7;
    for(int i = 0; i < SIZE; i++)
        if ( value == arr[i] )
        {
            found = true;
            break;
        }
    cout << "The value was" << (found?" ":" not ") << "present" << endl;

    // linear search with recursion
    found = false;
    value = 12;
    //int value = 7;
    found = recursive_linear(arr, SIZE, 0, value);
    cout << "The value was" << (found?" ":" not ") << "present" << endl;

    // binary search example
    const int SIZE_2 = 15;
    int theArray[SIZE_2] = {1, 3, 5, 7, 9, 12, 14, 16, 18, 20, 22, 30, 33, 40, 44};
    found = false;
    //int value = 25;
    value = 50;
    found = recursive_search(theArray, 0, SIZE_2, value);
    //found = interative_search(theArray, 0, SIZE, value);
    cout << "The number " << value << ( found?" was ":" was not " ) << "found." << endl;
    return 0;
}
