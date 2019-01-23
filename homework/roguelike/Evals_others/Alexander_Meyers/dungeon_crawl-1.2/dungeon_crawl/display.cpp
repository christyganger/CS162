#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <map>
#include "dungeon.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;

void instructions( Dungeon & r ) {

    showRoom( r, "intro" );
    _wait_enter();
    showRoom( r, "instructions" );
    _wait_enter();
}

void showRoom( Dungeon & r, string item ) {
    std::stringstream side = sideBar( item );
    string line;
    for( int l=0; l<20; l++ )
        cout << "\n";
    /* There is a space between each element of the board, so the top and
     * bottom borders need to be twice the width + 3 */
    cout << std::string(DUNX*2+3, BORD) << endl;
    /* Build the interior and side walls of the dungeon. */
    for( int y=0; y<DUNY; y++ ) {
        cout << BORD << " ";
        for( int x=0; x<DUNX; x++ ) {
            cout << r.area[y][x] << " ";
        }
        cout << BORD << " ";
        if( std::getline( side, line ) and y < DUNY )
            cout << line;
        cout << endl;
    }
    cout << std::string(DUNX*2+3, BORD) << endl;
}

std::stringstream sideBar( string item ) {
    std::stringstream out;

    if( item=="intro" )
        out << "This is a simple dungeon crawl.\n"
              "Your goal is to get to the end\n"
              "without running into, or getting\n"
              "trapped by enemies.\n\n"

              "Input using 'wasd' as a sequence,\n"
              "and your moves will match.\n\n"
              "Good luck!!!";

    if( item=="instructions" )
        out << "w = Up\n\na = Left\n\ns = Down\n\nd = Right";

    if( item=="legend" )
        out << PLAYER << " = Player\n\n"
            << MON    << " = Monster\n\n"
            << BORD   << " = Wall/Obstacle\n\n"
            << TRES   << " = Treasure";
    return out;
}
