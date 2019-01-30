#include <iostream>

using namespace std;

recPerm(string word, string dest);
    {
         int length = stati_cast<int>(word.length());

         if ( length == 0)
            cout << dest << "\n";

         for(int i = 0; i < length; i++)
            recPerm(word.substr(1, length-1), dest+word[i]);
    }


int main()
{

    recPerm("abc", "");



    /*string example = "Little star";

    for(int i = 0; i < example.length(); i++)
    cout << example[i] << "\n";

    cout << example.length() << "\n";

    cout << example.find("s") << "\n";

    cout << example.substr(5,9) << "\n";
    */
    return 0;
}
