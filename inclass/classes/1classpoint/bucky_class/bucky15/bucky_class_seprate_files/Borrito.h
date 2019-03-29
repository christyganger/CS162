#ifndef BORRITO_H
#define BORRITO_H
#include <string>
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


};

#endif // BORRITO_H
