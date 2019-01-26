#include <iostream>

using namespace std;

int main()
{
    string twolength = "ab";
    cout << twolength.substr(0, 2) << "\n";

    string threelength = "abc";
    cout << threelength.substr(0, 3) << "\n";

    string fourlength = "abcd";
    cout << fourlength.substr(0,4) << "\n";

    if(twolength == threelength || twolength == fourlength)
    {
        cout <<"yes two length is equal to three" << "\n";
    }

        return 0;
}
