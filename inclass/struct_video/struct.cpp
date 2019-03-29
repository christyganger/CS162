//struct notes
//structure, holds items more than one data type.
//declare structure

#include <iostream>
#include <cmath>

struct newperson{ // called tag ;
// 2 members
char name[20];
int age;
};

//how to use it?

int main()
{
using namespace std;

newperson bucky =
{
"Bucky",
21
};
// declaring structure..
//how to use as variable?

newperson hoss =
{
    "hoss jones",
    45
};

cout << "my age is ";
cout << bucky.age << "\n";
cout << "my name is " << bucky.name << "\n";

cout << "my age is ";
cout << hoss.age << "\n";
cout << "my name is " << hoss.name << "\n";

getchar();
cout << "Press any key to continue." << "\n";
return 0;
}
