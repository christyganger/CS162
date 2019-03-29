#include <iostream>

using namespace std;


bool recFind(int arr[],int length, int index, int value)

{

    if ( arr[index] == value )
    {
        return true;
    }
    if (index == length)
    {
        cout << index << "\n";
        return false;
    }
    else{
            return recFind(arr, length, index+1, value);

    }

}

int main()
{
    int array_size = 12;
    int array_one[array_size] = {1, 2, 3, 4, 5 ,6 ,7 ,8 ,9 , 10, 11, 12};
    cout << recFind(array_one, array_size, 0, 12) << "\n";

    cout << "Hello world!" << endl;
    return 0;
}

