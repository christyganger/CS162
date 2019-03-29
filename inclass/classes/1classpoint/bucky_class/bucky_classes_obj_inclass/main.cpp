#include <iostream>

using namespace std;

class BuckysClass{
private:

public:
    void coolSaying(){
        cout << "preaching to the choir" << "\n";
    }

};

int main()
{
    BuckysClass buckysObject;

    buckysObject.coolSaying();

    return 0;
}
