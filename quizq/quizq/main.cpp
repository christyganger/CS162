#include <iostream>
#include <iomanip>

using namespace std;

const int SIZEofA = 5;
void func_fill_array(int arr[][SIZEofA], const int SIZEofA);

void func_display_array(const int arr[][SIZEofA], const int SIZEofA);
int main()

{


  int arr[SIZEofA][SIZEofA];
  func_fill_array(arr, SIZEofA);

  func_display_array(arr, SIZEofA);

    return 0;

}
void func_fill_array(int arr[][SIZEofA], const int SIZEofA)
{
    for(int i =0; i< SIZEofA; i++)
    {
        int k = 0;
        for(int j = 0; j< SIZEofA; j++)
        {
            if (j == 0 || i == 0)
            {
                arr[i][j] = (i+1)*(j+1);
            }

            else
            {
                arr[i][j] = (i+1)*(j+1);
            }

        }
        arr[i][k] = i+1*k+1;
    }


}

void func_display_array(const int arr[][SIZEofA], const int SIZEofA)
{
    for(int i = 0; i < SIZEofA; i++)
    {
        for(int j = 0; j < SIZEofA; j++)
        {
            cout << setw(2);
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }

}


/*int length;
    cout << "Enter the number of values" << endl;
    cin >> length;

    int array[length];

    cout << "Now enter the values, one per line" << endl;

    for(int i = 0; i < length; i++) // start with i = 0
        cin >> array[i];

    int smallest = array[0];  //start with zero not o
    for(int i = 0; i < length; i++) // start with 0
        if ( smallest > array[i] )
            smallest = array[i];

    cout << "The smallest value is " << smallest << endl;
*/
/*
    const int SIZE = 6; // 6 not 5

    int arr[SIZE] = { 1, 3, 5, 7, 9 , 11 };

    for(int i = 0; i < SIZE; i++) // needs to be i< SIZE .. or i <= SIZE-1
        cout << arr[i] << endl;
*/
