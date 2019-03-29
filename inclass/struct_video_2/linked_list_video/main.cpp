#include <iostream>
#include <cstdlib>
#include "list.h"

using namespace std;

int main()
{
    List Paul;

    for(int i = 0; i < 16; i++)
    {
        Paul.AddNode(i);
    }

    Paul.PrintList();

    Paul.DeleteNode(0);

    Paul.PrintList();
    return 0;
}
