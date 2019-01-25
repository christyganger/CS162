#include <iostream>
#include <fstream> // for get
#include <string> // peek , unget
#include <cctype> // peek isdigit


using namespace std;

int main()
{
    //getline example
    string name;
    cout << " please enter your name " << "\n";
    getline (cin, name);
    cout << "hello, " << name << "!\n";

    // get example  depreciated in c++11
    char str[256];

    cout << "enter name of existing text file: " << "\n";
    cin.get (str, 256);

    ifstream is(str);

    char c;
    while (is.get(c))
        cout << c;
    is.close();
    cout << "\n";

    //peek example
    cout << " please, enter a number or word " << "\n";
    cout.flush(); // make sure output is written

    cin >> ws; // eat leading white spaces
    int d = cin.peek();

    if (d == EOF )
    {
        return 1;
    }
    if (isdigit(d) )
    {
        int n;
        cin >> n;
        cout << " You entered the number " << n << "\n";

    }
    else
    {
        string str;
        cin >> str;
        cout << " you entered the words: " << str << "\n";
    }

    // unget
    cout << " please enter another number or word " << "\n";
    cin.ignore();
    char e = cin.get();

    if ( (e >= '0') && (e <= '9'))
    {
        int n1;
        cin.unget();
        cin >> n1;
        cout << "You entered a number: " << n1 << "\n";
        cin.unget();
        cin >> n1;
        cout << "last digit: " << n1 << "\n";

    }
    else
    {
        string str_1;
        cin.unget();
        getline(cin,str_1);
        cout << "You entered a word " << str_1 << "\n";
    }

    //put
    ofstream outfile ("storing.txt");
    char ch;
    bool done = false;
    cout << "Type some text (type a dot to finish):\n";
    while(!done)
        {

            cin.get(ch);
            if (ch == '\n' || ch == '\r')
               {
                  done = true;
               }
            else
            {
                cin.unget();
                cin.get(ch);
                outfile.put(ch);
            }

        }
    return 0;
}
