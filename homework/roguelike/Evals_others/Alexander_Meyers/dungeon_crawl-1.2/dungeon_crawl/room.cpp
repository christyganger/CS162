#include <iostream>
#include <iomanip>
#include "dungeon.hpp"

using std::cout;
using std::cin;
using std::endl;

void initRoom( Dungeon & r ) {
    for( int y=0; y<DUNY; y++ ) {
        for( int x=0; x<DUNX; x++ ) {
            r.area[y][x] = DOT;
        }
    }
    r.py = dRand('y');
    r.px = dRand('x');
    r.area[r.py][r.px] = PLAYER;
    placeObj( r, TRES );
    for( int d=0; d<5; d++ )
        placeObj( r, BORD );
}

void placeObj( Dungeon & r, char obj ) {
    int y = dRand('y'), x = dRand('x');
    while( r.area[y][x] != '.' ) {
        y = dRand('y');
        x = dRand('x');
    }
    r.area[y][x] = obj;
}
