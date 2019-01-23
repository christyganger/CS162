#include "dungeon.hpp"

void Monster::initMon( Dungeon & room ) {
    bool freespot = false;
    while( !freespot ) {
        mony = rand() % DUNY;
        monx = rand() % DUNX;
        if( room.area[mony][monx] == '.' or mony >= DUNY or monx >= DUNX ) {
            freespot = true;
            room.area[mony][monx] = MON;
        }
    }
}

void Monster::moveMon( Dungeon & room ) {
    int direc = rand() % 2;
    if( direc == 0 ) {
        if( room.py > mony and room.area[mony+1][monx] == '.' ) {
            room.area[mony++][monx] = DOT;
            room.area[mony][monx] = MON;
        }
        if( room.py < mony and room.area[mony-1][monx] == '.' ) {
            room.area[mony--][monx] = DOT;
            room.area[mony][monx] = MON;
        }
    }
    if( direc == 1 ) {
        if( room.px > monx and room.area[mony][monx+1] == '.' ) {
            room.area[mony][monx++] = DOT;
            room.area[mony][monx] = MON;
        }
        if( room.px < monx and room.area[mony][monx-1] == '.' ) {
            room.area[mony][monx--] = DOT;
            room.area[mony][monx] = MON;
        }
    }
}
