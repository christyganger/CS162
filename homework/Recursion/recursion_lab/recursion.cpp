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

///// referenced this code from youtube video, plan to revisit after
// I figured the second part out.. bit more practice with recursion.
// https://www.youtube.com/watch?v=GqANqWsOJpo
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
void recPrintAllSubsets(std::string word,string output, unsigned index, unsigned amount_of_letters)
{
if (amount_of_letters == word.length())
{
    return;
}

if (index == word.length())
{
    amount_of_letters++;
  return recPrintAllSubsets(word, output, 0, amount_of_letters);
}

output = word.substr(index, amount_of_letters) + ",";
index++;
 recPrintAllSubsets(word, output, index, amount_of_letters);

cout << output;
return;


//recPrintAllSubsets(word, output, n, counter);

}

// this is the wrapper that calls your subset generating program
// change it to match your function signature
void printAllSubsets(std::string word)
{
    recPrintAllSubsets(word, "", 0, 0);
}

