//
//  recursion.cpp
//  Recursion
//
//  Created by jim bailey on 1/23/19.
//  This work by Jim Bailey is licensed under a Creative Commons Attribution 4.0 International License.
//

#include "recursion.h"
#include <iostream>

/*******************************
 *
 *Recursion
 *
 * Finished Code By Lawrence Warner
 * CS 162 C++
 * Last Modified: 1/29/19
 *
 *******************************/

using namespace std;

// this is your recursive palindrome program
// it might have different arguments, depending on how you solved the problem
bool recPalindrome(std::string word)
{
    // put your code here
        std::string::const_iterator fwd = word.begin();
        std::string::const_iterator rev = word.end();
        if( rev - fwd <= 1 ) return true;
        if( *fwd++ != *--rev ) return false;
        return isPalindrome( std::string( fwd, rev ) );
}


// this is the wrapper that calls your recursive palendrome testing program
bool isPalindrome(std::string word)
{
     // change this as needed for your recursive program
    return recPalindrome(word);
}

// this is your recursive subset generating program
// you might have a different set of arguments, depending on how you code it
void recPrintAllSubsets(std::string word, std::string output)
{
    // put your code here
        for (int i = 0; i < output.length(); i++)
            {
                std::string next = word + output[i];
                std::string remaining = output.substr(i+1);
                recPrintAllSubsets(next, remaining);
            }
        if( word.size() > 0 ) cout << word << ", ";
}

// this is the wrapper that calls your subset generating program
// change it to match your function signature
void printAllSubsets(std::string word)
{
    recPrintAllSubsets("", word);
}

