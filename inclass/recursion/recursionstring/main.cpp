#include <iostream>

using namespace std;

string recReverse(string value, int start)
{
    if (start == value.length() )
    return "";
return value[start] + recReverse(value, start+1);
}

string reverser(string value)
{
    return recReverse(value, 0);
}



int main()
{
    string value;

    do
    {
        cout << "Type something " << "\n";
        getline(cin,value);
        cout << reverser(value) << "\n";
            }while(value != "");
    cout << "Hello world!" << endl;
    return 0;
}
