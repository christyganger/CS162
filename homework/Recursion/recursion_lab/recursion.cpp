//
//  recursion.cpp
//  Recursion
//
//  Created by jim bailey on 1/23/19.
//  This work by Jim Bailey is licensed under a Creative Commons Attribution 4.0 International License.
//

#include "recursion.h"
#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

// this is your recursive palindrome program
// it might have different arguments, depending on how you solved the problem
bool recPalindrome(std::string word, int first = 0, int last =0)
{
if(word.length() == 1)
    {
        return true;
    }

    if(first >= last)
    {
        return true;
    }

    if(word[first] != word[last])
    {
        return false;
    }
    return recPalindrome(word, first +1, last -1);


// put your code here


    // dummy return to keep compiler happy, delete

}


// this is the wrapper that calls your recursive palendrome testing program
bool isPalindrome(std::string word)
{
     // change this as needed for your recursive program
    return recPalindrome( word, 0, word.length()-1);
}

// this is your recursive subset generating program
// you might have a different set of arguments, depending on how you code it
void recPrintAllSubsets(std::string word, int b, int a, int d)
{
int sizeofword = word.length();
char word_array[sizeofword+1];
word.copy(word_array, sizeofword);
char temp;
int c = 0;
cout << word.substr(c, b) << ", ";
if (d >= sizeofword)
 {
     b--;
     a=0;
     d=1;
  return;
 }
if (b == 0)
{
temp = word_array[a];
word_array[a] = word_array[d];
 word_array[d] = temp;
for(unsigned i =0; i > word.length()-1; i++)
 {word = word_array[i];}
a++;
d++;
b = sizeofword;
return;}
    recPrintAllSubsets(word, b, a , d);
//recPrintAllSubsets(word, output, n, counter);

}

// this is the wrapper that calls your subset generating program
// change it to match your function signature
void printAllSubsets(std::string word)
{
    recPrintAllSubsets(word, word.length(), 0, 1);
}

