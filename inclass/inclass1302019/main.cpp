#include <iostream>

using namespace std;
 /*int * values()
 {
     int * value =  new int[6];
     for(int i = 0; i < 6; i++)
     value[i] = i *3 +2;
     //*value = 6;
    return value;
 }*/
int main()
{
    const int row = 10;
    const int col = 10;
    int arr[row][col];
    arr[0][0] = 44;
    int **(ptr[row][col]) = arr[row][col];

    cout << **(ptr) << "\n";
   /*int * ptr = values();
int apple(5);
   for(int i = 0; i < 6; i++)
   cout << *(ptr+i) << "\n";
   delete [] ptr;
*/
    return 0;
}
