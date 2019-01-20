/* Project Tic Tac Toe
Class: 162c++
Written by : Christy Ganger
Assignment 1
thanks to http://www.cplusplus.com/reference/cstdlib/rand/ for reminding me on how to do the srand.
Special thanks to my wife Michelle Wear, for testing and recommending changes.
*/
//includes
#include <iostream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace std;

//const
const int firstsize = 10;
const int secondsize = 12;

//prototypes

//selection of user X or O
void displayinstructions(char &xo, int number_player_wins, int number_player_losses, int number_ties);

//show boards both play board and demonstration of number placement
void showBoard(char boardcurrent[firstsize][secondsize],char ease_of_use_play_field_copy[firstsize][secondsize]);

//gets player moves
char getMove(char &xo);

//checks for win condition
bool checkWin(char xo, char xoPC, bool &PCwon, bool &won, const char *pointtofieldone, const char *pointtofieldtwo, const char *pointtofieldthree,
              const char *pointtofieldfour, const char *pointtofieldfive, const char *pointtofieldsix, const char *pointtofieldseven, const char *pointtofieldeight, const char *pointtofieldnine );

// checks if field is taken, and if it's ok to draw the xo or ask for another move
bool checkDraw(int movefield, char &xo, char *pointtofieldone, char *pointtofieldtwo, char *pointtofieldthree, char *pointtofieldfour,char *pointtofieldfive,
                char *pointtofieldsix, char *pointtofieldseven, char *pointtofieldeight, char *pointtofieldnine );

// checks for tie condition after move
bool checkTieNoWin(const char *pointtofieldone, const char *pointtofieldtwo, const char *pointtofieldthree, const char *pointtofieldfour,
const char *pointtofieldfive, const char *pointtofieldsix, const char *pointtofieldseven, const char *pointtofieldeight, const char *pointtofieldnine);

// computer player and move
bool PCplayer(char &xoPC, char *pointtofieldone, char *pointtofieldtwo, char *pointtofieldthree, char *pointtofieldfour,char *pointtofieldfive,
                char *pointtofieldsix, char *pointtofieldseven, char *pointtofieldeight, char *pointtofieldnine);

bool playagain();

int main()
{

    //main game loop starts here
    do

    {
        // variables reset on new game..
        static int number_player_wins = 0;
        static int number_player_losses = 0;
        static int number_ties = 0;
        char xo;
        char xoPC;
        bool done = false;
        bool playersturn = false;
        bool won = false;
        bool PCwon = false;
        bool verified_move = false;
        bool check_win = false;
        bool check_tie = false;
        /* initialize random seed: */
        srand (time(NULL));

        // randomises who goes first 1 = true player goes first 0 = comp goes first
        playersturn = rand() % 1 + 0;

        //blank playboard
        char boardcurrent[firstsize][secondsize] = {{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' '},{' ',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' '},
        {' ','_','_','_','|','_','_','_','|','_','_','_'},{' ',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' '},{' ',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' '},
        {' ','_','_','_','|','_','_','_','|','_','_','_'},{' ',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' '},{' ',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' '},
        {' ',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' '} },*pointtofieldone, *pointtofieldtwo, *pointtofieldthree, *pointtofieldfour, *pointtofieldfive, *pointtofieldsix,
        *pointtofieldseven, *pointtofieldeight, *pointtofieldnine;

        //blank demo board for placement
        char ease_of_use_play_field_copy[firstsize][secondsize] = {{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' '},{' ',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' '},
        {' ','_','_','_','|','_','_','_','|','_','_','_'},{' ',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' '},{' ',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' '},
        {' ','_','_','_','|','_','_','_','|','_','_','_'},{' ',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' '},{' ',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' '},
        {' ',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' '} },*point_to_field_ease_one, *point_to_field_ease_two, *point_to_field_ease_three, *point_to_field_ease_four,
         *point_to_field_ease_five, *point_to_field_ease_six, *point_to_field_ease_seven, *point_to_field_ease_eight, *point_to_field_ease_nine;

        //requests player select x or o, then assigns computer to opposite.
        displayinstructions(xo,number_player_wins,number_player_losses,number_ties);
         if(xo == 'X')
        {
            xoPC = 'O';
        }
        if (xo == 'O')
        {
            xoPC = 'X';
        }

        // populates pointers to playboard position to avoid magic numbers
        pointtofieldone = &boardcurrent[2][2];
        pointtofieldtwo = &boardcurrent[2][6];
        pointtofieldthree = &boardcurrent[2][10];
        pointtofieldfour = &boardcurrent[5][2];
        pointtofieldfive = &boardcurrent[5][6];
        pointtofieldsix = &boardcurrent[5][10];
        pointtofieldseven = &boardcurrent[8][2];
        pointtofieldeight = &boardcurrent[8][6];
        pointtofieldnine = &boardcurrent[8][10];

        //populates pointers to demo board position to avoid magic numbers
        point_to_field_ease_one = &ease_of_use_play_field_copy[2][2];
        point_to_field_ease_two = &ease_of_use_play_field_copy[2][6];
        point_to_field_ease_three = &ease_of_use_play_field_copy[2][10];
        point_to_field_ease_four = &ease_of_use_play_field_copy[5][2];
        point_to_field_ease_five = &ease_of_use_play_field_copy[5][6];
        point_to_field_ease_six = &ease_of_use_play_field_copy[5][10];
        point_to_field_ease_seven = &ease_of_use_play_field_copy[8][2];
        point_to_field_ease_eight = &ease_of_use_play_field_copy[8][6];
        point_to_field_ease_nine = &ease_of_use_play_field_copy[8][10];


        // assigns demo board number's with pointers
        *point_to_field_ease_one = '1';
        *point_to_field_ease_two = '2';
        *point_to_field_ease_three = '3';
        *point_to_field_ease_four  = '4';
        *point_to_field_ease_five = '5';
        *point_to_field_ease_six  = '6';
        *point_to_field_ease_seven = '7';
        *point_to_field_ease_eight = '8';
        *point_to_field_ease_nine = '9';


        // game play loop for turns starts here.
        while(!done)
        {
            //decides if it's players turn
            if (playersturn == true)
            {
                //switch to computer turn after this turn.
                playersturn = false;

                // gets move and verifies it's valid.
                verified_move  = checkDraw(getMove(xo), xo, pointtofieldone, pointtofieldtwo, pointtofieldthree, pointtofieldfour, pointtofieldfive,
                    pointtofieldsix, pointtofieldseven, pointtofieldeight, pointtofieldnine);

                // if move is valid do this
                if (verified_move  == true)
                {
                    //shows board and demo board
                    showBoard(boardcurrent,ease_of_use_play_field_copy);

                    // assigns win condition
                    check_win = checkWin(xo, xoPC, PCwon, won, pointtofieldone, pointtofieldtwo, pointtofieldthree, pointtofieldfour,
                                 pointtofieldfive, pointtofieldsix, pointtofieldseven, pointtofieldeight, pointtofieldnine);

                    //if there is win condition with this move..
                    if(check_win == true)
                    {
                        //if computer wins this move..
                        if(PCwon == true)
                        {
                            cout << "You lose!" << "\n";
                            number_player_losses++;
                             //set turn condition loop off.
                             done = true;

                             // ends turn condition loop
                             continue;
                        }

                        // if player wins
                        if(won == true)
                        {
                            cout << "You win!" << "\n";
                            number_player_wins++;
                             //set turn condition loop off.
                             done = true;

                             // ends turn condition loop
                             continue;
                        }


                    }
                    // if win condition is off..
                    if(check_win == false)
                    {
                        // check for tie condition assign true / false to check_tie
                        check_tie = checkTieNoWin(pointtofieldone, pointtofieldtwo, pointtofieldthree, pointtofieldfour,
                                 pointtofieldfive, pointtofieldsix, pointtofieldseven, pointtofieldeight, pointtofieldnine);

                                 // if tie condition exists
                                 if(check_tie == true)
                                    {
                                        cout << "It's a Tie Game." << "\n";
                                        number_ties++;
                                        // set turn condition loop off.
                                        done = true;

                                        // ends turn condition loop.
                                        continue;
                                    }
                    }

                }
                // if the move the player chose is invalid.
                if (verified_move  == false)
                {
                    //show the playboard , and demo number position board.
                    showBoard(boardcurrent,ease_of_use_play_field_copy);

                    cout << "invalid move" << "\n";
                    // gets a new move, verifies it with checkdraw to see if player move can be drawn and is valid.
                    checkDraw(getMove(xo), xo, pointtofieldone, pointtofieldtwo, pointtofieldthree, pointtofieldfour, pointtofieldfive,
                    pointtofieldsix, pointtofieldseven, pointtofieldeight, pointtofieldnine);
                }

            }

            // computer's turn!
            if (playersturn == false)
            {
                // sets player's turn next loop
                playersturn = true;

                // decides computers next move, and that it's valid, then draws it
                PCplayer(xoPC, pointtofieldone, pointtofieldtwo, pointtofieldthree, pointtofieldfour, pointtofieldfive, pointtofieldsix, pointtofieldseven,
                        pointtofieldeight, pointtofieldnine);

                //shows board after computer move, plus playboard numbered reference board.
                showBoard(boardcurrent,ease_of_use_play_field_copy);

                // checks for win condition, assigns true for win, false for no win to check_win
                check_win = checkWin(xo, xoPC, PCwon, won, pointtofieldone, pointtofieldtwo, pointtofieldthree, pointtofieldfour, pointtofieldfive, pointtofieldsix, pointtofieldseven,
                    pointtofieldeight, pointtofieldnine) ;

                 // if a win condition on computer player is detected do this.
                if(check_win == true)
                {

                    // if computer player won.
                    if(PCwon == true)
                    {
                        number_player_losses++;
                        cout << "You lose!" << "\n";
                        // end the turn condition loop.
                        done = true;
                        continue;
                    }

                    // if player won this round.. somehow?
                    if(won == true)
                    {
                        number_player_wins++;
                        cout << "You win!" << "\n";
                        // end the turn condition loop
                        done = true;
                        continue;
                    }

                }

                //if win doeesn't result from computer turn..
                if(check_win == false)
                    {
                        // check for tie condition.
                        check_tie = checkTieNoWin(pointtofieldone, pointtofieldtwo, pointtofieldthree, pointtofieldfour,
                                 pointtofieldfive, pointtofieldsix, pointtofieldseven, pointtofieldeight, pointtofieldnine);

                                 // if it's a tie, do this
                                 if(check_tie == true)
                                 {
                                     cout << "It's a Tie Game." << "\n";
                                    number_ties++;
                                     //end turn condition loop
                                     done = true;
                                     continue;
                                 }
                    }

            }




        }
        // check if player wants to play again for main loop, or end program.
    }while(!playagain());
    return 0;
}

// displays instructions, and asks users to select X or O, if it's lower case, make it capital, verify it's an X or O
void displayinstructions(char &xo, int number_player_wins, int number_player_losses, int number_ties)
{
    cout << "\n\n\n";
    cout << "Current Player wins: " << number_player_wins << "\n";
    cout << "Current Player losses: " << number_player_losses << "\n\n\n";
    cout << "Current computer wins: " << number_player_losses << "\n";
    cout << "Current computer losses: " << number_player_wins << "\n\n\n";
    cout << "Current Tie games : " << number_ties << "\n";
    cout << "\n\n\n";

    if(number_player_wins == 0 && number_player_losses == 0 && number_ties == 0)
    {
        cout << "Welcome to Tic - Tac - Toe!" << "\n";
        cout << "To win you need to get a full row filled with your X or O, across, up and down, or diagnially" << "\n";
        cout << "To play First Select X or O" << "\n";
        cout << "Then Select which number of the field you'd like to place the X or O into." << "\n";

    }

    if(number_player_wins == number_player_losses && number_player_losses+number_player_wins != 0)
    {
        cout << "Computer says: \"You think you can beat me?\"" << "\n";
    }
    if(number_player_wins > number_player_losses)
    {
        cout << "Computer says: \"I was going easy on you!\"" << "\n";
    }

    if(number_player_losses > number_player_wins)
    {
        cout << "Computer says: \"How could you possibly lose? I was going easy on you!\"" << "\n";
    }

    if(number_ties > number_player_wins+number_player_losses)
    {
        cout << "Computer says: \"A tie?\"" << "\n";
        cout << "Computer says: \"That means I won and you lost.\"" << "\n";
        cout << "Computer says: \"Wait, .. That means you won and I lost.\"" << "\n";
        cout << "Computer says: \"No, I want a rematch!\"" << "\n";
    }

    // loop until user gives valid x,o, X , O
    do
    {
        cout << "Would you like to play as X or O?" << "\n";
        cin >> xo;

        // if lowercase,, .. convert to capital
        if (xo == 'x' || xo == 'o')
        {xo = xo-32;}

        //check for valid X O exit if it is.
    }while(!(xo == 'X' || xo == 'O'));

}

// Shows the playboard curent moves + available for next move without numbers, and one with numbers for reference.
void showBoard(char boardcurrent[firstsize][secondsize],char ease_of_use_play_field_copy[firstsize][secondsize])
{
    // couts each field in order to create the playboard.
    for(int i = 0; i < firstsize; i++)
    {
     for(int j = 0; j < secondsize; j++)
     {
        cout << boardcurrent[i][j];

     }
     cout << "\n";
    }

    //couts the demo boar array, for each field to create the demo board
    for(int i = 0; i < firstsize; i++)
    {
     for(int j = 0; j < secondsize; j++)
     {
        cout << ease_of_use_play_field_copy[i][j];

     }
     cout << "\n";
    }
}

// gets players move. verifies it's actually 1-9 int if not, request it again clearing any cin error.
char getMove(char &xo)
{
    // fields to clear or return on each move.
    int movefield;
    bool done_entering_field = false;


    // loop of user input
    while(!done_entering_field)
    {
        cout << "Player " << xo <<" Please select the field you wish to use:" << "\n";
        cin  >> movefield;
        if (cin.fail() or isdigit(movefield))
        {
            cin.clear();
            cin.ignore(2000,'\n');
            cout << " Please retype which field 1-9:";
            cin >> movefield;
        }
        if(movefield < 10 and movefield > 0)
        {
            done_entering_field = true;
        }
    }

    return movefield;
}

// checks for win condition across / up down/ diagnal for computer and player
bool checkWin(char xo, char xoPC, bool &PCwon, bool &won, const char *pointtofieldone, const char *pointtofieldtwo, const char *pointtofieldthree, const char *pointtofieldfour,
const char *pointtofieldfive, const char *pointtofieldsix, const char *pointtofieldseven, const char *pointtofieldeight, const char *pointtofieldnine )
{
    //return value if winner detected
    bool winner = false;
    //player across win
    if (*pointtofieldone == xo && *pointtofieldtwo == xo && *pointtofieldthree == xo)
    {
        won = true;
        winner = true;
    }
    if (*pointtofieldfour == xo && *pointtofieldfive == xo && *pointtofieldsix == xo)
    {
        won = true;
        winner = true;
    }
    if (*pointtofieldseven == xo && *pointtofieldeight == xo && *pointtofieldnine == xo)
    {
        won = true;
        winner = true;
    }
    // player up and down win
    if (*pointtofieldone == xo && *pointtofieldfour == xo && *pointtofieldseven == xo)
    {
        won = true;
        winner = true;
    }
    if (*pointtofieldtwo == xo && *pointtofieldfive ==xo && *pointtofieldeight == xo)
    {
        won = true;
        winner = true;
    }
    if (*pointtofieldthree == xo && *pointtofieldsix==xo && *pointtofieldnine == xo)
    {
        won = true;
        winner = true;
    }
    //player diagnal win
    if (*pointtofieldone == xo && *pointtofieldfive == xo && *pointtofieldnine == xo)
    {
        won = true;
        winner = true;
    }
    if (*pointtofieldthree == xo && *pointtofieldfive == xo && *pointtofieldseven == xo)
    {
        won = true;
        winner = true;
    }
    //pc across win check
    if (*pointtofieldone == xoPC && *pointtofieldtwo == xoPC && *pointtofieldthree == xoPC)
    {
        PCwon = true;
        winner = true;
    }
    if (*pointtofieldfour == xoPC && *pointtofieldfive == xoPC && *pointtofieldsix == xoPC)
    {
        PCwon = true;
        winner = true;
    }
    if (*pointtofieldseven == xoPC && *pointtofieldeight == xoPC && *pointtofieldnine == xoPC)
    {
        PCwon = true;
        winner = true;
    }
    // pc up and down win
        if (*pointtofieldone == xoPC && *pointtofieldfour == xoPC && *pointtofieldseven == xoPC)
    {
        PCwon = true;
        winner = true;
    }
    if (*pointtofieldtwo == xoPC && *pointtofieldfive == xoPC && *pointtofieldeight == xoPC)
    {
        PCwon = true;
        winner = true;
    }
    if (*pointtofieldthree == xoPC && *pointtofieldsix==xoPC && *pointtofieldnine == xoPC)
    {
        PCwon = true;
        winner = true;
    }
    //pc diagnal win check
    if (*pointtofieldone == xoPC && *pointtofieldfive == xoPC && *pointtofieldnine == xoPC)
    {
        PCwon = true;
        winner = true;
    }
    if (*pointtofieldthree == xoPC && *pointtofieldfive == xoPC && *pointtofieldseven == xoPC)
    {
        PCwon = true;
        winner = true;
    }

    return winner;
}

// checks that user's move is valid to draw to the board.
bool checkDraw(int movefield, char &xo, char *pointtofieldone,  char *pointtofieldtwo, char *pointtofieldthree,  char *pointtofieldfour,
 char *pointtofieldfive, char *pointtofieldsix, char *pointtofieldseven, char *pointtofieldeight, char *pointtofieldnine )
{
    // sets valid move or not.
    bool isvalid = false;


        switch(movefield)
    {
    case 9:
        if (*pointtofieldnine == ' ')
        {
           *pointtofieldnine = xo;
            isvalid = true;
        }

        break;

    case 8:
        if (*pointtofieldeight == ' ')
        {
            *pointtofieldeight = xo;
            isvalid = true;
        }
        break;

    case 7:
        if (*pointtofieldseven == ' ')
        {
            *pointtofieldseven = xo;
            isvalid = true;
        }
        break;

    case 6:
        if (*pointtofieldsix == ' ')
        {
            *pointtofieldsix = xo;
            isvalid = true;
        }
        break;

    case 5:
        if (*pointtofieldfive == ' ')
        {
           *pointtofieldfive = xo;
            isvalid = true;
        }
        break;

    case 4:
        if (*pointtofieldfour == ' ')
        {
            *pointtofieldfour = xo;
            isvalid = true;
        }
        break;

    case 3:
        if (*pointtofieldthree == ' ')
        {
            *pointtofieldthree = xo;
            isvalid = true;
        }
        break;

    case 2:
        if (*pointtofieldtwo == ' ')
        {
            *pointtofieldtwo = xo;
            isvalid = true;
        }
        break;

    case 1:
        if (*pointtofieldone == ' ')
        {
            *pointtofieldone = xo;
            isvalid = true;
        }
        break;

    default:
        cout << "input check error in Getmove:" << "\n";
        break;

    }

    return isvalid;
}

// computer player, random move decision checks that the move is valid, then submits it.
bool PCplayer(char &xoPC,char *pointtofieldone, char *pointtofieldtwo, char *pointtofieldthree, char *pointtofieldfour,char *pointtofieldfive,
                char *pointtofieldsix, char *pointtofieldseven, char *pointtofieldeight, char *pointtofieldnine)
{
    //check for valid move.
    bool isvalid = false;

    //loop to decide move, and if it's valid if not, decides another move.
    do{

            //randomly generates a new move
            int PCmoving = rand() % 9 + 1;

        // move fields if field is blank, then it's valid.
        switch(PCmoving)
        {
        case 9:
            if (*pointtofieldnine == ' ')
            {
               *pointtofieldnine = xoPC;
                isvalid = true;
                cout << "PC chose 9" << "\n";
            }

            break;

        case 8:
            if (*pointtofieldeight == ' ')
            {
                *pointtofieldeight = xoPC;
                isvalid = true;
                cout << "PC chose 8" << "\n";
            }
            break;

        case 7:
            if (*pointtofieldseven == ' ')
            {
                *pointtofieldseven = xoPC;
                isvalid = true;
                cout << "PC chose 7" << "\n";
            }
            break;

        case 6:
            if (*pointtofieldsix == ' ')
            {
                *pointtofieldsix = xoPC;
                isvalid = true;
                cout << "PC chose 6" << "\n";
            }
            break;

        case 5:
            if (*pointtofieldfive == ' ')
            {
               *pointtofieldfive = xoPC;
                isvalid = true;
                cout << "PC chose 5" << "\n";
            }
            break;

        case 4:
            if (*pointtofieldfour == ' ')
            {
                *pointtofieldfour = xoPC;
                isvalid = true;
                cout << "PC chose 4" << "\n";
            }
            break;

        case 3:
            if (*pointtofieldthree == ' ')
            {
                *pointtofieldthree = xoPC;
                isvalid = true;
                cout << "PC chose 3" << "\n";
            }
            break;

        case 2:
            if (*pointtofieldtwo == ' ')
            {
                *pointtofieldtwo = xoPC;
                isvalid = true;
                cout << "PC chose 2" << "\n";
            }
            break;

        case 1:
            if (*pointtofieldone == ' ')
            {
                *pointtofieldone = xoPC;
                isvalid = true;
                cout << "PC chose 1" << "\n";
            }
            break;

        default:
            cout << "input check error in PCplayer / PCmove:" << "\n";
            break;

        }
    }while(!isvalid);
return isvalid;
}

//checks the false win condition, for a tie condition.
bool checkTieNoWin(const char *pointtofieldone, const char *pointtofieldtwo, const char *pointtofieldthree, const char *pointtofieldfour,
const char *pointtofieldfive, const char *pointtofieldsix, const char *pointtofieldseven, const char *pointtofieldeight, const char *pointtofieldnine)
{
    //returned tie condition bool
    bool IsItATieGame = false;
    // looks for blank positions
    if (*pointtofieldone != ' ' && *pointtofieldtwo != ' ' && *pointtofieldthree != ' ' && *pointtofieldfour != ' ' && *pointtofieldfive != ' '
        && *pointtofieldsix != ' ' && *pointtofieldseven != ' ' && *pointtofieldeight != ' ' && *pointtofieldnine != ' ')
    {
        // if no positions are left, then it's a tie.
        IsItATieGame = true;
    }
    return IsItATieGame;
}

// asks user if they want to play again for exit of main loop.
bool playagain()
{
    //main play again bool to return.
    bool playagain = false;

    //loop bool for checking to play again or not with user input.
    bool cincheck = false;

    // user input variable characters
    char playing;

    //checks user input to play again
    while(!cincheck)
    {
        cout << "Would you like to play again? Y/N" << "\n";
        cin >> playing;
        // if cin fails, do to improper input.
        if(cin.fail())
        {
            // clear fail flag.
            cin.clear();
            // clear all input for 2000 characters
            cin.ignore(2000,'\n');
            // progress to next loop for new input
            continue;
        }

        //switch and check for valid input
        switch(playing)
        {
        case 'Y':
        case 'y':
            //set main loop to play again.
            playagain = false;
            // set input to valid, and exit playagain.
            cincheck = true;
            break;
        case 'N':
        case 'n':
            // set main loop to not play again but exit..
            playagain = true;
            // set input to valid, exit playagain function.
            cincheck = true;
            break;
        default:
            // input error, start loop again.
            cout << "invalid input" << "\n";
            break;
        }
    }
    return playagain;
}
