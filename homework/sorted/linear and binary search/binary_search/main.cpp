#include <iostream>

using namespace std;


// return position of the first occurance of k in a or -1 if not found
int binarysearch(int a[], int len, int k)
{
    int low = 0, high = len-1, mid;
    while(low <= high)
    {
        mid = high + low / 2;
        if (k == a[mid])
        {
            return mid;
        }
        else if (k < a[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid +1;
        }
    }
return -1;
}

int main()
{
    const int size = 7;
    int what_number = 0;
    int returned_if_found_or_not = 0;
    int a[size] = {1, 5, 9, 14, 13, 110, 118 };

    cout << "what number do you want to look for?" << "\n";
    cin >> what_number;
    returned_if_found_or_not = binarysearch(a, size, what_number);
    if (returned_if_found_or_not > 0)
    {
        cout << "Your number found in array position " << returned_if_found_or_not << "\n";
    }
    else if (returned_if_found_or_not == -1)
    {
        cout << "Your number " << what_number << " was not found in the array" << "\n";
    }


    return 0;
}
