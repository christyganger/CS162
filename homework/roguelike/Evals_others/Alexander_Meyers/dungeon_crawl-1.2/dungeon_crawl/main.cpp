#include <iostream>
#include "dungeon.hpp"

using std::cout;
using std::cin;
using std::endl;

int main()
{
    srand(static_cast<int>(time(NULL)));

    std::string state = "";
    bool replay = false;

    do {
        /* Dungeon instance created. */
        Dungeon room;
        cout << "player y " << room.py << endl;
        cout << "player x " << room.px << endl;
        cout << "winner " << room.winner << endl;
        cout << "loser " << room.loser << endl;

        /* Create the room */
        initRoom( room );

        Monster * mon;
        mon = new Monster[NUMMONS];


        for( int m=0; m<NUMMONS; m++ ) {
            mon[m].initMon( room );
        }

        instructions( room );

        do {
            showRoom( room, "legend" );
            getMoves( room, mon );
        } while( !room.end );
        if( room.winner ) {
            cout << "You Won!!!!!!!! Goooooooooaaaaallllllll!!!!!!!!" << endl;
        }
        if( room.loser ) {
            cout << "The wall turns out to be a monster blocking you way.\n"
                "It eats you and takes the treasure." << endl;
        }

        _wait_enter();
        char input;
        cout << "Would you like to play again?" << endl;
        cin >> input;
        _cin_clear();
        if( input == 'y' or input == 'Y' )
            replay = true;
	else
            replay = false;
    } while( replay );

    cout << "Thank you for playing!" << endl;
    _sleep( 2000 );
    return 0;
}
