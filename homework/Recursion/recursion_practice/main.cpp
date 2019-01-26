#include <iostream>

using namespace std;


bool isPalindrome(string str);
bool isStringPalindrome(string str, int first, int last);
bool recStringPalindrome(string str, int first, int last);


int main()
{
        string str;
        cout << " enter a string " << "\n";
        getline(cin, str);
        cout << "\n";
        if (isPalindrome(str))
        {
            cout << str << " is a palindrome (via recursion) " << "\n";

        }
        else
        {
            cout << str << " is NOT a palindrome (via recursion) " << "\n";
        }
    return 0;
}


bool isPalindrome(string str)
{
  return recStringPalindrome( str, 0, str.length()-1);
}


bool isStringPalindrome(string str, int first, int last)

{

}

bool recStringPalindrome(string str, int first, int last)
{
    if(str.length() == 1)
    {
        return true;
    }

    if(first >= last)
    {
        return true;
    }

    if(str[first] != str[last])
    {
        return false;
    }
    return recStringPalindrome(str, first +1, last -1);


}
