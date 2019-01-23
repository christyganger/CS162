#include <iostream> // std::cin, std::cout, std::endl
#include <iomanip>  // std::setprecision, std::fixed
#include <vector>   // std::vector
#include <cstdio>   // std::exit(), std::system()
#include <locale>   //
#include <limits>
#include <sstream>
#include <thread>
#include <chrono>
#include "qolife.hpp"

void _clear() {
    char clear_screen[] = "clear";
    std::cout << std::flush;
    std::system( clear_screen );
}

/* This uses some simple math to print out some centered text and set a fill
 * character/s for each line. This can now take custom charcters on either side
 * but they will auto match each other if only one is provided. I have also
 * added the ability to set the speed lines are displayed at function call, as
 * well as setting a default width.*/
void _print_center( std::vector<std::string> tocenter,
        int width, int delay, char lfill, char rfill ) {
    int len = tocenter.size();
    if( rfill == '\n' )
        rfill = lfill;
    for ( int x = 0; x < len; x++ ) {
        int to_pad = width - tocenter[x].length();
        int left_pad = to_pad / 2;
        int right_pad = to_pad - left_pad;
        std::cout << std::string( left_pad, lfill )
            << tocenter[x]
            << std::string( right_pad, rfill )
            << std::endl;
        _sleep( delay );
    }
}

/* This function is used to scroll text in two ways. The first is scrolling
 * from right to left, much like a news ticker where text will scroll into and
 * then out of view. The second scrolls text in from left to right until the
 * text is fully in view. Useful for menu items and when you want to add a
 * little extra flair to printed text. */
void _scroller( std::string line, std::string direc, int width ) {
    std::string output = "";
    int len = line.size();
    if( width == 0 )
        width = line.size();
    if( direc == "right" ) {
        for( int n = len - 1; n >= 0; n-- ) {
            // Uses the substring function to control how much text shows.
            output = line.substr( n, len );
            std::cout << output;
            // Pause display for 30 milliseconds
            _sleep( 30 );
            // Flush the line, then return to beginning.
            std::cout << std::flush << '\r';
        }
    }
    else {
        for( int n = 0; n <= width + len; n++ ) {
            // Create line of spaces matching 'width' then append 'line'.
            output = std::string( width, ' ' ) + line;
            // Truncate start of 'line' each iteration until end of 'line'.
            output = output.substr( n, output.size() ) + std::string( n, ' ' );
            // Set end of line to match 'width' to create the scroll in effect.
            output.resize( width );
            std::cout << output;
            // Sleep for 80 milliseconds which seems to be a comfortable speed.
            _sleep( 80 );
            // Flush the line, then return to beginning.
            std::cout << std::flush << '\r';
        }
    }
    /* One more flush to allow for effects like loading bars that will them be
     * replaced on the same line with the requested information rather than
     * creating a new line every time. */
    std::cout << std::flush;
}

/* This prints a single line animated. No matter how long the line it will
 * always take approximately the same time to print as the delay between
 * characters decreases by 2/3 with every iteration.*/
void _print_line( int iters ) {
    int sleeper = 1000;
    for( int x = 0; x < iters; x++ ) {
        std::cout << '|';
        std::cout << std::flush;
        _sleep(sleeper);
        sleeper /= 1.66;
    }
}


/* This takes a double and sets the precision using a string stream object
 * where I can store the formatting then convert it to a string. */
std::string _dec_string( double num, int prec, bool fixed )
{
    std::ostringstream to_dec;
    if( fixed )
        to_dec << std::fixed;
    to_dec << std::setprecision( prec );
    to_dec << num;
    std::string dec = to_dec.str();
    return dec;
}

/* Get input from the user and check if valid input. Can also be given a string
 * for use as the prompt for the user allowing to change the prompt for each
 * call to this function, which is important as it will then become part of the
 * loop and won't be lost on subsequent iterations.*/
double long _g_positive( std::string prompt ) {
    double long num = 0;
    bool go = true;
    do {
        std::cout << prompt << std::endl;
        std::cout << "Entering a non number or 0 will exit" << std::endl;
        std::cin >> num;
        _cin_clear();
        if( num == 0 )
            return 0;
        if( num <= 0 )
            std::cout << "You must input a positive number." << std::endl;
        else
            go=false;
    } while( go );
    std::cout << std::endl;
    return num;
}

/* Iterate over a given string and change to lower case. I wonder if I should
 * guard against excessively long strings? */
std::string _to_lower(std::string& str) {
    std::string os;
    int len = str.size();
    for( auto x=0;x<len;x++ ) {
        os += tolower(str[x]);
    }
    return os;
}
