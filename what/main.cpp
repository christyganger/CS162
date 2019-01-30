#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

void recursion(string word, string output, unsigned index, unsigned amount_of_letters)
{


if (amount_of_letters == word.length())
{
    return;
}

if (index == word.length())
{
    amount_of_letters++;
  return recursion(word, output, 0, amount_of_letters);
}


        output = word.substr(index, amount_of_letters) + ",";




index++;
recursion(word, output, index, amount_of_letters);


cout << output;
}

void recursion_helper(string word)
{
    string output = " ";
    recursion(word,output, 0, 0);
}

int main()
{

string word = "abcd";
    recursion_helper(word);
    return 0;
}


