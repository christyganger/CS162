#include <iostream>
#include <algorithm>
using namespace std;

void recursion(string word, string word_check, unsigned len, unsigned index, int a, int b)
{
if (static_cast<unsigned>(b) == len)
{
    a=0;
    b=1;
}
if (index == len)
{
    return;
}
for(unsigned i =0; i <= word_check.length(); i++)
    {
        cout << ",";

            cout << word_check.substr(i);
    }
cout << "\n";

swap(word_check[a], word_check[b]);

for(unsigned i =0; i <= word_check.length(); i++)
    {
        cout << ",";

            cout << word_check.substr(i);
    }
cout << "\n";

if (word_check!=word)
    {
        a++;
        b++;
        index++;
        recursion(word, word_check, len, index, a, b);
    }

return;
}

void recursion_helper(string word)
{
    recursion(word, word, word.length(), 0, 0 , 1);
}

int main()
{

string word = "abcd";
    recursion_helper(word);
    return 0;
}


