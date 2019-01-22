#include <iostream>
#include <cstdlib> // for random
#include <ctime> // for time

/*******************************
 *
 *Dungeon Crawl
 *
 * Finished Code By Lawrence Warner
 * CS 162 C++
 * Last Modified: 1/20/19
 *
 *******************************/

using namespace std;

struct Position
{
    int row, col;
    Position(int r = 0, int c = 0) : row(r), col(c) { }
};

    // Global Constants
        const int SIZE = 10;
        const int NUM_TRAPS = 6;
        const char SPACE = '.', PLAYER = '@', TRAP = '#', GOAL = '$';
        const Position PlayerStart(1, 1);
        const Position GoalPosition(SIZE-1, SIZE-1);

    // Function Declarations
        void displayInstructions(); // displays the instructions
        void createDungeon(char dungeon[][SIZE]); // sets up a dungeon with traps and treasure
        void displayDungeon(char dungeon[][SIZE], const Position& pos); // display the current dungeon state
        void getMove(Position& pos); // gets a valid move (W,S,A,D)
        bool checkMove(char dungeon[][SIZE], const Position& pos); // sees if move is onto checkCode object
        bool repeat(); // do you want to play again?

int main()
{
    // initialize random
    srand(static_cast<int>(time(NULL)));
    displayInstructions();

        // play again? loop
        do
            {
                // define variables
                char dungeon[SIZE][SIZE];

                createDungeon(dungeon);

                Position pos(PlayerStart);
                displayDungeon(dungeon, pos);

                do
                    {
                        getMove(pos);
                        system("cls");
                        displayDungeon(dungeon, pos);
                    }
                while (!checkMove(dungeon, pos));
            }
        while (repeat());
}

void displayInstructions()
{
    cout << " \n " << " \n "<< endl;
    cout << " * DUNGEON: a simple game for the terminal. The objective of the " << endl;
    cout << " * game is that the player (@) reaches the treasure ($) avoiding the traps (#). " << endl;
    cout << " * You will use (w) for up (s) for down (a) for left and (s) for right. " << endl;
    cout << " \n " << " \n "<< endl;
    cout << " \n " << endl;
    system(" pause ");
    system("cls");
}

ostream& operator<<(ostream& os, const Position& pos)
{
    return os << '[' << pos.row << ',' << pos.col << ']';
}

void createDungeon(char dungeon[][SIZE])
{
    for (int r = 0; r < SIZE; ++r)
        for (int c = 0; c < SIZE; ++c)
            dungeon[r][c] = SPACE;

    dungeon[GoalPosition.row][GoalPosition.col] = GOAL;
    // temporarily place player symbol in grid while we set the traps
    dungeon[PlayerStart.row][PlayerStart.col] = PLAYER;

    for (int trapCount = 0; trapCount < NUM_TRAPS; )
    {
        Position rnd(rand() % 10, rand() % 10);
        if (dungeon[rnd.row][rnd.col] != SPACE)
            continue;

        dungeon[rnd.row][rnd.col] = TRAP;
        ++trapCount;
    }

    // remove player symbol from grid
    dungeon[PlayerStart.row][PlayerStart.col] = SPACE;
}

void displayDungeon(char dungeon[][SIZE], const Position& pos)
{
    cout << " \n " << " \n "<< endl;
    for (int r = 0; r < SIZE; ++r)
    {
        for (int c = 0; c < SIZE; ++c)
            if (r == pos.row && c == pos.col)
                cout << PLAYER << ' ';
            else
                cout << dungeon[r][c] << ' ';
        cout << '\n';
    }
}

void getMove(Position& pos)
{
    Position newPos;

    while (true)
    {
        char move;

        while (true)
        {
            cout << "Move: ";
            cin >> move;
            if (move == 'w' || move == 's' || move == 'a' || move == 'd')
                break;
            cout << " \n Invalid direction, must be w, s, a, or d. \n";
        }

        newPos = pos;
        if      (move == 'w') --newPos.row;
        else if (move == 's') ++newPos.row;
        else if (move == 'a') --newPos.col;
        else if (move == 'd') ++newPos.col;

        if (newPos.col >= 0 && newPos.col < SIZE &&
            newPos.row >= 0 && newPos.row < SIZE)
            break;

        cout << " \n You can't move that way.\n";
    }
    pos = newPos;
}

bool checkMove(char dungeon[][SIZE], const Position& pos)
{
    if (dungeon[pos.row][pos.col] == TRAP)
    {
        cout << "\n You've landed on a TRAP! Game OVER... \n";
        return true;
    }
    if (dungeon[pos.row][pos.col] == GOAL)
    {
        cout << " \n You've captured the treasure! Good game! \n";
        return true;
    }
    return false;
}

bool repeat()
{
    bool done = false;
    char start_over;
    bool prog_end = true;
        // Restart or Exit App
            // ask user to start over
                while (prog_end)
                {
                    cout << " Would you like to another one? ";
                    cout << " [y/n]: ";
                    cin >> start_over;
                    cout << " \n " << endl;

                    switch (start_over)
                        {
                        case 'n':
                        case 'N':
                            cout << " Thanks for playing. \n" << endl;
                            // exit switch loop
                            done = false;
                            prog_end = false;
                            break;

                        case 'Y':
                        case 'y':
                            // exit switch loop
                            cin.clear();
                            cin.ignore();
                            prog_end = false;
                            done = true;
                            system("cls");
                            return true;
                            break;

                        default:
                            cout << " That's not valid input, please type Y for yes, or N for no \n" << endl;
                            cout << " \n " << endl;

                        break;
                        }


                }
return done;
}
