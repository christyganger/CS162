/*
This program is written by Christy Ganger for CIS 162c+
Version 1, completed 1/19/2010
Special thanks to Michelle Wear for alpha beta testing.
version1.2
fixed user needs prompt for pressing enter, and know which char they are.
version1.3
added comments to code.
got feedback "boring as fuck, no interaction similar to minesweeper but easier"
considering adding mobs, .. levels. some kind of interaction.
Noticed a bug , sometimes doesnt load the create dungeon to populate dungeon or continue..
version 1.4
added something_triggered function to clean up main a bit.
*/

#include <iostream>
//these includes from http://www.cplusplus.com/reference/cstdlib/srand/
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace std;

// max play field size
const int MAX_SIZE = 20;
// default field spot variables via assignment parameters
const char Play_Field = '.';
const char Player = '@';
const char space = ' ';
const char TRAP = '#';
const char CASH = '$';

// this prototype generates the base dungeon playfield.
void MakeDungeon(char level[][MAX_SIZE]);
// this prototype is to display current dungeon play field
void displayDungeon(char level[][MAX_SIZE], int win_counter, int lose_counter);
// this prototype is to populate the dungeon with traps and cache/win
void createDungeon(char level[][MAX_SIZE], int);
// gets the move from the player
char getMove();
// Checks the move is valid.
bool checkMove(char level[][MAX_SIZE],char move_char,int player_positionX, int player_positionY);
// updates the move to dungeon, records if move is a trigger, forwards that to main.
void updateDungeon(char level[][MAX_SIZE], bool can_move, char move_player, int player_positionX, int player_positionY, bool &istrigger, char &what_trigger);
// gets current player position for various functions
void playerposition(char level[][MAX_SIZE],int &player_positionX, int &player_positionY);
//something got triggered
bool trigger_something(bool is_trigger, char what_trigger, int &win_counter, int &lose_counter);
// asks to play again.
bool Play_Again();

int main()
{
    // seeds rand for placement of traps, cash.
    srand (time(NULL));
    // win and lose counters out here, so will work between loops
    int win_counter = 0;
    int lose_counter = 0;



    do  //start main loop
    {

        int current_level = 0; // variables for future,  for multiple levels
        int player_positionX = 0; // where is player x position
        int player_positionY = 0; // where is player y position
        char level_0[MAX_SIZE][MAX_SIZE]; // array for level
        char move_char; // character's move char for update dungeon
        bool done = false; // play loop
        bool is_trigger = false; // is there a playboard trigger?
        char what_trigger; // what is the trigger?

        MakeDungeon(level_0);  // make base dungeon in array
        displayDungeon(level_0, win_counter, lose_counter); // display base dungeon
        createDungeon(level_0, current_level); // populate dungeon

       do  // start play loop
        {
            displayDungeon(level_0, win_counter, lose_counter); // display current dungeon for loop
            move_char = getMove(); // ask user where to move, and save it in move_char for updatedungeon.
            playerposition(level_0, player_positionX, player_positionY); // find players current position
            updateDungeon(level_0, checkMove(level_0, move_char, player_positionX, player_positionY)
                          , move_char, player_positionX, player_positionY, is_trigger, what_trigger); // checks move is valid, if valid, updates the board, returns if trigger
            displayDungeon(level_0, win_counter, lose_counter); // display current dungeon for loop
            done = trigger_something(is_trigger, what_trigger, win_counter, lose_counter); // evaluates and responds to when something is triggered.

        }while(!done); // ends play loop
    }while(Play_Again()); //ends main loop
    return 0;  // return app over to system
}

// this function generates the base dungeon playfield.
void MakeDungeon(char level[][MAX_SIZE])
{
    for(int i = 0; i < MAX_SIZE;i++) // for each row of the playfield for max playfield size incriment
    {

        for(int j = 0; j < MAX_SIZE;j++) // for each column of the playfield for max playfield size incriment
            {
                level[i][j] = Play_Field;  // puts the character for play field '.' into each field of the array for each position of the array.

            }

    }
}

// this function is to display current dungeon play field
void displayDungeon(char level[][MAX_SIZE], int win_counter, int lose_counter)
{
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n";   // clears screen for new field display
    cout << "You have won " << win_counter << " times." << "\n";   // outs player dialog for wins
    cout << "You have lose " << lose_counter << " times." << "\n";  // outs player dialog for loses
    cout << "Your Character is the " << Player << " character on the board" << "\n"; // tells player which char is the player
    for(int k = 0; k < MAX_SIZE; k++) // starts a loop incrimnent of k for max size
    {

        for(int L = 0; L < MAX_SIZE; L++) // starts a loop incrimnent for l for max size
        {
            cout << level[k][L];   // displays play field char in each array spot for l and k (row column)
            cout << space; // puts a space between each so the field is less dense.
        }
        cout << "\n"; // moves to next row
    }
}

// this function is to populate the dungeon with traps and cache/win
void createDungeon(char level[][MAX_SIZE], int dung_level)
{
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n"; // clears screen from misc
    int where_put_playerX = rand() % MAX_SIZE; // generates random player position for X for start of game
    int where_put_playerY = rand() % MAX_SIZE; // generates random player position for Y for start of game
    int where_put_treasureX = rand() % MAX_SIZE; // generates random treasure position for X for start of game
    int where_put_treasureY = rand() % MAX_SIZE; // generates random treasure position for Y for start of game
    int trap_placeX = rand() % MAX_SIZE; // generates random trap position for X for start of game
    int trap_placeY = rand() % MAX_SIZE; // generates random trap position for Y for start of game
    bool done = false; // in function loop for generation of deungeon stuff
    int trapsset = 0; // var for counting traps

    // check for same location treasure and player
    do // start func loop
    {
        if (where_put_treasureX == where_put_playerX && where_put_treasureY == where_put_playerY) // checks if random treasure placement location is same as player's position
        {
            where_put_treasureX = rand() % MAX_SIZE; // picks a new random location for treasure
            where_put_treasureY = rand() % MAX_SIZE; // picks a new random location for treasure
            continue; // restarts loop
        }

    done = true; // ends loop if not same as player position
    }while(!done);   // ends treasure loop


    level[where_put_treasureX][where_put_treasureY] = CASH;    // place treasure
    int how_many_traps = rand() % ((MAX_SIZE-2) + dung_level)/2;  // initialises how many traps, via random generation of max dungeon - 2 for treasure and player, then adds future dungeon levels, devided by 2.
    // place player
    level[where_put_playerX][where_put_playerY] = Player; // places player
    // place traps.
    do // start trap generation loop
    {

        trap_placeX = rand() % MAX_SIZE;  // generates new trap location
        trap_placeY = rand() % MAX_SIZE; // generates new trap location
        if ((trap_placeX == where_put_treasureX || trap_placeX == where_put_playerX) &&
            (trap_placeY == where_put_treasureY || trap_placeY == where_put_playerY)) // checks if trap location is same as player, or treasure.
        {
            trap_placeX = rand() % MAX_SIZE;   // if true, generate new location
            trap_placeY = rand() % MAX_SIZE; // if true, generate new location
            continue; // restarts loop.
        }

         level[trap_placeX][trap_placeY] = TRAP;  // places the trap
    trapsset++;   // incriments the trap count
    }while(trapsset != how_many_traps);  // checks trap count  make sure it's not equal to how many traps are supposed to be there, if not .. continue loop.

}

// gets the move from the player
char getMove()
{
    char player_move;  // declare variable for player's move.
    bool done = false; // loop bool.
    do // loop for getting move.
    {
        cout << "Use W, S , A , D " << "\n";   // out to player dialog instructions
        cout << "Press Enter after typing the letter, to move." << "\n"; // out to player dialog instructions
        cin >> player_move; // takes in input from user puts it in player_move;
        switch(player_move) // starts switch for deciding what to do with the data inputted.
        {
        case 'w':   // if input is w
        case 'W':   // if input is W
            player_move = 'w';  // puts the move into this variable.
            done = true; // ends loop
            break; // ends switch

        case 's':  // if input is s
        case 'S': // if input is S
            player_move = 's'; // put the move into this variable.
            done = true; // ends loop
            break; // ends switch

        case 'a': // if input is a
        case 'A': // if input is A
            player_move = 'a'; // put move into this variable.
            done = true; // end loop
            break; // ends switch

        case 'd': // if input is d
        case 'D': // if input is D
            player_move = 'd'; // put move into this variable.
            done = true; // ends loop
            break; // ends switch

        default:  // if input is anything else
            cout << "invalid move" << "\n"; // outs to player invalid move.
            cin.clear(); // clears cin.fail flag that wrong input got put in char.
            cin.ignore(2000, '\n'); // clears input buffer for 2000 chars.
            break; // ends switch

        }
    }while(!done); // if not false or .. true.. then continue loop, if not true or .. false.. end loop
return player_move; //returns player's move
}

// Checks the move is valid.
bool checkMove(char level[][MAX_SIZE],char move_return_getmove,int player_positionX, int player_positionY)
{
  bool isvalid = false; // sets bool to false for return default.

      switch(move_return_getmove) // starts switch for input to make sure user isn't trying to leave the play field.. causing array overflow or underflow
      {
        case 'w': // if input is w
        case 'W': // if input W
            if (player_positionX > 0) // if player x postion is greater than zero this move is valid
            {

                isvalid = true;  // the move is is valid

            }

            break; // exit switch

        case 's': // if input is s
        case 'S': // if input is S
            if (player_positionX < MAX_SIZE-1) // if player position x is less than max size of array
            {

                isvalid = true; // the move is valid
            }

            break; // exit switch

        case 'a': // if input is a
        case 'A': // if input is A
            if (player_positionY > 0) // if player position y is greater than zero
            {

                isvalid = true; // this move is valid
            }

            break; // exit switch

        case 'd': // if input is d
        case 'D': // if input is D
            if (player_positionY < MAX_SIZE-1) // if player position is less than max size of array
            {

                isvalid = true; // this move is valid
            }

            break; // exit switch
      }


 return isvalid; // returns if the move is valid or not
}

// updates the move to dungeon, records if move is a trigger, forwards that to main.
void updateDungeon(char level[][MAX_SIZE], bool can_move, char move_player,int player_positionX, int player_positionY, bool &is_trigger, char &what_trigger)
{

while(can_move) // loops while move hasn't been made yet.
   {switch(move_player) // switch checks move type
      {
        case 'w': // if move is w
        case 'W': // if move is W
            if (player_positionX > 0) // if move is greater than 0 !redundant check
            {

                if(level[player_positionX-1][player_positionY] != Play_Field) // checks if board position is already filled
                {
                    is_trigger = true; // says yes there is something there already
                    what_trigger = level[player_positionX-1][player_positionY]; // copies what's already there into the trigger field for later
                }
                level[player_positionX-1][player_positionY] = Player; // moves player character to new position
                level[player_positionX][player_positionY]= Play_Field; // removes old player character from field, and places normal play field

            }
            can_move = false; // ends while loop as turn is done.

            break; // exits switch

        case 's': // if move is s
        case 'S': // if move is S
            if (player_positionX < MAX_SIZE-1) // checks if move is less than max play field !redundant check
            {
                if(level[player_positionX+1][player_positionY] != Play_Field) // checks if board position is already filled
                {
                    is_trigger = true; // says yes there is something there already
                    what_trigger = level[player_positionX+1][player_positionY]; // copies what's already there into the trigger field for later
                }
                level[player_positionX+1][player_positionY] = Player; // moves player character to new position
                level[player_positionX][player_positionY]= Play_Field; // removes old player character from field, and places normal play field
            }
            can_move = false; // ends while loop as turn is done.

            break; // exits switch

        case 'a': // if move is a
        case 'A': // if move is A
            if (player_positionY > 0) // if move is greater than 0 !redundant check
            {
                if(level[player_positionX][player_positionY-1] != Play_Field) // checks if board position is already filled
                {
                    is_trigger = true; // says yes there is something there already
                    what_trigger = level[player_positionX][player_positionY-1]; // copies what's already there into the trigger field for later
                }
                level[player_positionX][player_positionY-1] = Player; // moves player character to new position
                level[player_positionX][player_positionY]= Play_Field; // removes old player character from field, and places normal play field
            }
            can_move = false; // ends while loop as turn is done.

            break; // exits switch

        case 'd': // if move is d
        case 'D': // if move is D
            if (player_positionY < MAX_SIZE-1) // checks if move is less than max play field !redundant check
            {

                if(level[player_positionX][player_positionY+1] != Play_Field) // checks if board position is already filled
                {
                    is_trigger = true; // says yes there is something there already
                    what_trigger = level[player_positionX][player_positionY+1]; // copies what's already there into the trigger field for later
                }
                level[player_positionX][player_positionY+1] = Player; // moves player character to new position
                level[player_positionX][player_positionY]= Play_Field; // removes old player character from field, and places normal play field
            }
            can_move = false; // ends while loop as turn is done.

            break; // exits switch
      }
   }

}

// gets current player position for various functions
void playerposition(char level[][MAX_SIZE],int &player_positionX, int &player_positionY)
{
    player_positionX = 0; // resets known player position x
    player_positionY = 0; // resets known player position y
  //look for player
  for(int i = 0; i < MAX_SIZE; i++) // iterates i (row) while max size of board isnt reached.
  {
      for(int j = 0; j < MAX_SIZE; j++) // iterates j (column) while max size of board isnt reached.
      {
          if (level[i][j] == Player) // checks if current array position of board i j is player character
          {
              player_positionX = i; // sets player x to current iteration of i (row)
              player_positionY = j; // sets player y to current iteration of j (column)
          }
      }
  }
}


//something got triggered
bool trigger_something(bool is_trigger, char what_trigger, int &win_counter, int &lose_counter)
{
    bool done = false; // internal version of done .. to set and return for main.
    if(is_trigger == true) // evaluates if trigger is true, what itis, and responds accordingly.
            switch(what_trigger) // switch for which trigger to valuate
            {
            case TRAP:      // if trigger is a trap do this.
                cout << "You triggered a trap!" << "\n";    // outs to player dialog
                cout << "BOOM!, you died." << "\n"; // outs to player dialog
                done = true; // exits play loop
                lose_counter++;   // incriments loses
            break; // exit switch
            case CASH: // trigger if cash do this.
                cout << "You win!" << "\n"; // outs to player dialog
                win_counter++; // incriments wins
                done = true; // exits play loop
            break; // exit switch.
            default: // if invalid trap check was given
                cout << "Error with trap" << "\n"; // outs to player debug info

            break; // exits switch

            }
return done;
}

// asks to play again.
bool Play_Again()
{
    char play; // sets char variable for input
    bool done_play_loop = false; // sets while loop bool to default false
    bool return_to_play_or_not; // sets bool for returning if player wants to play again or not
    do // starts do while loop
    {


    cout << "Would you like to play again?" << "\n"; // out user dialog for input
    cin >> play; // puts user input here.
    switch(play) // starts switch to evaluate answer
    {
    case 'Y': // if user input = Y
    case 'y':// if user input = y
        done_play_loop = true; // ends user input check loop
        return_to_play_or_not = true; // sets return bool for play again to true
        break; // exits switch
    case 'N': // if user input = N
    case 'n': // if user input = n
        done_play_loop = true; // ends user input check loop
        return_to_play_or_not = false; // sets return bool for play again to false
        break; // exits switch
    default: // if input is something else
        cout << "Wrong input" << "\n"; // out dialog to user to enter data again.
        cin.clear(); // clears fail of input error
        cin.ignore(2000, '\n'); // clears input buffer for next loop
        break; // exits switch
    }
    }while(!done_play_loop); // ends input loop

return return_to_play_or_not; // returns the bool value of return_to_play_or_not to play loop of main.
}
