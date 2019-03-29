#include <iostream>

using namespace std;

void array_1();
void display_1();
void memory_1();

int main()

{

    array_1();
    display_1();
    memory_1();
return 0;
}

void array_1()
{
   int *square = new int[10];
   int *squares = square;
}
void display_1()
{
    int i;
    for(i = 1; *squares[i] <= 10; ++i)
    {
        cout << "["<< i << "]";
    }
}
void memory_1()
{
    delete [] *squares;
}
