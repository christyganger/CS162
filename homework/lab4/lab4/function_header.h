/*
// Lab 4 written by christy wear.
// version 1.4
// thanks for bin search from https://www.geeksforgeeks.org/binary-search/
// Special thanks to michelle wear for testing.
// *feedback version 1.1: not sure whats going on..
// *response, added more couts.
// *feedback version 1.2: window closes can't see output
// *response, added windows appreciation for phallic objects to hold open window.
// *feedback version 1.3: I dont understand why i'm entering digit
// *response: Added, comments as to what that portion is doing
// update version 1.4: split functions to functions.cpp, added includes to header along with prototypes to clean up the program
// *response was the dialogs intentional, or left over debug?
// yes.
*/


#ifndef FUNCTION_HEADER_H_INCLUDED
#define FUNCTION_HEADER_H_INCLUDED
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cctype>

using namespace std;

int binarySearch(const int* ptr_arr_new, int l, int r, int x);
void getSize(int &cin_buff_size);
int* createArray(int const cin_buff_size);
void sortArray(int* ptr_arr_new, const int cin_buff_size);
void displayArray(const int* ptr_arr_new, const int cin_buff_size);
void get_search_numbers(int what_to_find[], const int how_many_to_search);


#endif // FUNCTION_HEADER_H_INCLUDED
