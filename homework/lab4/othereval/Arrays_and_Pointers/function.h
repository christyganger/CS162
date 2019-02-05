#ifndef FUNCTION_H_INCLUDED
#define FUNCTION_H_INCLUDED
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cctype>

/*******************************
 *
 * Practice with Arrays and Pointers
 *
 * Finished Code By Lawrence Warner
 * CS 162 C++
 * Last Modified: 2/3/19
 *
 *******************************/

using namespace std;



int binarySearch(const int* array_new, int l, int r, int x);

void getSize(int &user_size);

int* createArray(int const user_size);

void sortArray(int* array_new, const int user_size);

void displayArray(const int* array_new, const int user_size);

void get_numbers(int user_number[], const int number_search);





#endif // FUNCTION_H_INCLUDED
