#include <iostream>
#include <iomanip>
#include <string>
#include "dungeon.hpp"

using std::cout;
using std::cin;
using std::endl;

void getMoves( Dungeon & r, Monster * mon ) {
    std::string moves = "";
    cout << "Input the sequence of moves you would like to make." << endl;
    cin >> moves;
    _cin_clear();

    for( auto m : moves ) {

        int y = r.py;
        int x = r.px;

        /* switch on each character of the string the player entered to
         * determine direction of movement. */
        switch( m ) {
            case 'W':
            case 'w':
                y--;
                break;
            case 'A':
            case 'a':
                x--;
                break;
            case 'S':
            case 's':
                y++;
                break;
            case 'D':
            case 'd':
                x++;
                break;
            default:
                cout << "You trip over you own feet because you forgot how to run." << endl;
        }

        /* Checks whether each of the moves entered is valid and breaks the
         * chain for any that are incorrect. Will still parse the correct parts
         * that precede the error. (Lends a bit of humor as it can happen in
         * the middle of movement that the player trips over their own feet.)
         * */
        if( y<DUNY and y>=0 and x<DUNX and x>=0 and checkMove( r, y, x ) ) {
            movePlayer( r, y, x );
            for( int m=0; m<NUMMONS; m++ ) {
                mon[m].moveMon( r );
            }
            showRoom( r, "" );
            cout << endl;
            /* Pauses for a brief period so it looks like the players movement
             * is being animated across the board. */
            _sleep( 300 );
        }
        else {
            /* I like this one. */
            cout << "You run into a wall and break your nose." << endl;
            _sleep( 2000 );
            break;
        }
    }
}

void movePlayer( Dungeon & r, int y, int x ) {
    /* Previous cords of the player. */
    r.area[r.py][r.px] = DOT;
    /* New cords of player on board. */
    r.area[y][x] = PLAYER;
    /* Recording new cords. */
    r.py = y;
    r.px = x;
}

int dRand( char cord ) {
    int temp = 0;
    if( cord == 'y' ) {
        temp = rand() % DUNY;
    }
    if( cord == 'x' ) {
        temp = rand() % DUNX;
    }
    return temp;
}

bool checkMove( Dungeon & r, int y, int x ) {
    bool valid = false;
    if( r.area[y][x] == DOT ) {
        valid = true;
    }
    if( r.area[y][x] == TRES ) {
        r.end = true;
        r.winner = true;
        valid = true;
    }
    if( r.area[y][x] == MON ) {
        r.end = true;
        r.winner = false;
        r.loser = true;
        valid = false;
    }
    return valid;
}
