#include <iostream>

using namespace std;
void printArray(int theArray[], int sizeOfArray);

int main()
{
    int sizearray = 3;
    int sizeofjess = 6;
    int bucky[sizearray] = {20,54,675};
    int jessica[sizeofjess] = {54,24,7,8,9,99};
    cout << "first array" << "\n";
    printArray(bucky, sizearray);
    cout << "second array" << "\n";
    printArray(jessica, sizeofjess);
    return 0;
}

void printArray(int theArray[], int sizeOfArray){
    for(int x = 0; x < sizeOfArray;x++)
    {
        cout << theArray[x] << "\n";
    }

}
