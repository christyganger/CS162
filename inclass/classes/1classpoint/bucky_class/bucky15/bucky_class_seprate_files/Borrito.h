#ifndef BORRITO_H
#define BORRITO_H
#include <string>
#include <iostream>
using namespace std;
class Borrito
{
    public:
        Borrito();
        Borrito(string z);
        void setName(string x);
        string getName();
    private:
        string name;
        int age = 66;


};

#endif // BORRITO_H
