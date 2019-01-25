#include <iostream>

using namespace std;

void display (int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main()
{

    const int size = 7;
    int numb[size];
    int i, j;

    for (i = 0; i <= size-1; i++)
    {
        cout << "please enter number" << "\n";
        cin >> numb[i];
    }
    display(numb, size);
    for ( i = 0; i <= size -2; i++)
    {
        for (j = i+1; j <= size-1; j++)
        {
            int temp;

            if( numb[i] > numb[j])
            {
                temp = numb[i];
                numb[i] = numb[j];
                numb[j] = temp;
            }
        }
    }
    display(numb, size);
    return 0;
}
