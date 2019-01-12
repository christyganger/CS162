#include <iostream>

using namespace std;

int main()
{
    int sizeoffirstarray = 2;
    int sizeofsecondarray = 3;
    int sally[sizeoffirstarray][sizeofsecondarray] = {{2,3,4},{8,9,10}};
    // sally is multidimentional array or array with 2 arrays
    // 2,3,4
    // 8,9,10
    for (int i = 0; i < sizeoffirstarray; i++)
    {
        for (int j = 0; j < sizeofsecondarray; j++)
        {
            cout << sally[i][j] << " " ;

        }
        cout << "\n";
    }


    return 0;
}
