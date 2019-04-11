#include <iostream>

using namespace std;

class Stankfist{
public:
    Stankfist(){stinkyVar=0;}

private:
    int stinkyVar;

    friend void stinkysFriend(Stankfist &sfo);
};


void stinkysFriend(Stankfist &sfo)
{
    sfo.stinkyVar=99;
    cout << sfo.stinkyVar << "\n";
}

int main()
{
    Stankfist yay;
    stinkysFriend(yay);
    return 0;
}
