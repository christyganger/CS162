/* Project Tic Tac Toe
Class: 162c++
Written by : Christy Ganger
Assignment 1
Special thanks to http://www.cplusplus.com/reference/cstdlib/rand/ for reminding me on how to do the srand.
*/
#include <iostream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <iomanip>

using namespace std;
const int firstsize = 10;
const int secondsize =12;
void displayinstructions(char &xo);
void showBoard(char boardcurrent[firstsize][secondsize],char ease_of_use_play_field_copy[firstsize][secondsize]);
char getMove(char &xo);
bool checkWin(char &xo, char &xoPC, bool &PCwon, bool &won, const char *pointtofieldone, const char *pointtofieldtwo, const char *pointtofieldthree,
              const char *pointtofieldfour, const char *pointtofieldfive, const char *pointtofieldsix, const char *pointtofieldseven, const char *pointtofieldeight, const char *pointtofieldnine );
bool checkDraw(int movefield, char &xo, char *pointtofieldone, char *pointtofieldtwo, char *pointtofieldthree, char *pointtofieldfour,char *pointtofieldfive,
                char *pointtofieldsix, char *pointtofieldseven, char *pointtofieldeight, char *pointtofieldnine );
bool checkTieNoWin(const char *pointtofieldone, const char *pointtofieldtwo, const char *pointtofieldthree, const char *pointtofieldfour,
const char *pointtofieldfive, const char *pointtofieldsix, const char *pointtofieldseven, const char *pointtofieldeight, const char *pointtofieldnine);
bool PCplayer(char &xoPC, char *pointtofieldone, char *pointtofieldtwo, char *pointtofieldthree, char *pointtofieldfour,char *pointtofieldfive,
                char *pointtofieldsix, char *pointtofieldseven, char *pointtofieldeight, char *pointtofieldnine);
bool playagain();

int main()
{

    do

    {
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
        playersturn = rand() % 1 + 0;
        char boardcurrent[firstsize][secondsize] = {{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' '},{' ',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' '},
        {' ','_','_','_','|','_','_','_','|','_','_','_'},{' ',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' '},{' ',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' '},
        {' ','_','_','_','|','_','_','_','|','_','_','_'},{' ',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' '},{' ',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' '},
        {' ',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' '} },*pointtofieldone, *pointtofieldtwo, *pointtofieldthree, *pointtofieldfour, *pointtofieldfive, *pointtofieldsix,
        *pointtofieldseven, *pointtofieldeight, *pointtofieldnine;
        char ease_of_use_play_field_copy[firstsize][secondsize] = {{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' '},{' ',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' '},
        {' ','_','_','_','|','_','_','_','|','_','_','_'},{' ',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' '},{' ',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' '},
        {' ','_','_','_','|','_','_','_','|','_','_','_'},{' ',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' '},{' ',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' '},
        {' ',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' '} },*point_to_field_ease_one, *point_to_field_ease_two, *point_to_field_ease_three, *point_to_field_ease_four,
         *point_to_field_ease_five, *point_to_field_ease_six, *point_to_field_ease_seven, *point_to_field_ease_eight, *point_to_field_ease_nine;

        displayinstructions(xo);
         if(xo == 'X')
        {
            xoPC = 'O';
        }
        if (xo == 'O')
        {
            xoPC = 'X';
        }

        pointtofieldone = &boardcurrent[2][2];
        pointtofieldtwo = &boardcurrent[2][6];
        pointtofieldthree = &boardcurrent[2][10];
        pointtofieldfour = &boardcurrent[5][2];
        pointtofieldfive = &boardcurrent[5][6];
        pointtofieldsix = &boardcurrent[5][10];
        pointtofieldseven = &boardcurrent[8][2];
        pointtofieldeight = &boardcurrent[8][6];
        pointtofieldnine = &boardcurrent[8][10];

        point_to_field_ease_one = &ease_of_use_play_field_copy[2][2];
        point_to_field_ease_two = &ease_of_use_play_field_copy[2][6];
        point_to_field_ease_three = &ease_of_use_play_field_copy[2][10];
        point_to_field_ease_four = &ease_of_use_play_field_copy[5][2];
        point_to_field_ease_five = &ease_of_use_play_field_copy[5][6];
        point_to_field_ease_six = &ease_of_use_play_field_copy[5][10];
        point_to_field_ease_seven = &ease_of_use_play_field_copy[8][2];
        point_to_field_ease_eight = &ease_of_use_play_field_copy[8][6];
        point_to_field_ease_nine = &ease_of_use_play_field_copy[8][10];


        *point_to_field_ease_one = '1';
        *point_to_field_ease_two = '2';
        *point_to_field_ease_three = '3';
        *point_to_field_ease_four  = '4';
        *point_to_field_ease_five = '5';
        *point_to_field_ease_six  = '6';
        *point_to_field_ease_seven = '7';
        *point_to_field_ease_eight = '8';
        *point_to_field_ease_nine = '9';



        while(!done)
        {
            if (playersturn == true)
            {

                playersturn = false;
                verified_move  = checkDraw(getMove(xo), xo, pointtofieldone, pointtofieldtwo, pointtofieldthree, pointtofieldfour, pointtofieldfive,
                    pointtofieldsix, pointtofieldseven, pointtofieldeight, pointtofieldnine);
                if (verified_move  == true)
                {
                    showBoard(boardcurrent,ease_of_use_play_field_copy);

                    check_win = checkWin(xo, xoPC, PCwon, won, pointtofieldone, pointtofieldtwo, pointtofieldthree, pointtofieldfour,
                                 pointtofieldfive, pointtofieldsix, pointtofieldseven, pointtofieldeight, pointtofieldnine);
                    if(check_win == true)
                    {
                        if(PCwon == true)
                        {
                            cout << "You lose!" << "\n";
                             done = true;
                        }
                        if(won == true)
                        {
                            cout << "You win!" << "\n";
                             done = true;
                        }


                    }
                    if(check_win == false)
                    {
                        check_tie = checkTieNoWin(pointtofieldone, pointtofieldtwo, pointtofieldthree, pointtofieldfour,
                                 pointtofieldfive, pointtofieldsix, pointtofieldseven, pointtofieldeight, pointtofieldnine);
                                 if(check_tie == true)
                                    {
                                        cout << "It's a Tie Game." << "\n";
                                        done = true;
                                    }
                    }

                }
                if (verified_move  == false)
                {
                    showBoard(boardcurrent,ease_of_use_play_field_copy);
                    cout << "invalid move" << "\n";
                    checkDraw(getMove(xo), xo, pointtofieldone, pointtofieldtwo, pointtofieldthree, pointtofieldfour, pointtofieldfive,
                    pointtofieldsix, pointtofieldseven, pointtofieldeight, pointtofieldnine);
                }

            }
            if (playersturn == false)
            {
                playersturn = true;
                PCplayer(xoPC, pointtofieldone, pointtofieldtwo, pointtofieldthree, pointtofieldfour, pointtofieldfive, pointtofieldsix, pointtofieldseven,
                        pointtofieldeight, pointtofieldnine);
                showBoard(boardcurrent,ease_of_use_play_field_copy);
                check_win = checkWin(xo, xoPC, PCwon, won, pointtofieldone, pointtofieldtwo, pointtofieldthree, pointtofieldfour, pointtofieldfive, pointtofieldsix, pointtofieldseven,
                    pointtofieldeight, pointtofieldnine) ;
                if(check_win == true)
                {
                    if(PCwon == true)
                    {
                        cout << "You lose!" << "\n";
                        done = true;
                    }
                    if(won == true)
                    {
                        cout << "You win!" << "\n";
                        done = true;
                    }

                }
                if(check_win == false)
                    {
                        check_tie = checkTieNoWin(pointtofieldone, pointtofieldtwo, pointtofieldthree, pointtofieldfour,
                                 pointtofieldfive, pointtofieldsix, pointtofieldseven, pointtofieldeight, pointtofieldnine);
                                 if(check_tie == true)
                                 {
                                     cout << "It's a Tie Game." << "\n";
                                     done = true;
                                 }
                    }

            }




        }
    }while(!playagain());
    return 0;
}

void displayinstructions(char &xo)
{
    cout << "Welcome to Tic - Tac - Toe!" << "\n";
    cout << "To win you need to get a full row filled with your X or O, across, up and down, or diagnially" << "\n";
    cout << "To play First Select X or O" << "\n";
    cout << "Then Select which number of the field you'd like to place the X or O into." << "\n";
    do
    {
        cout << "Would you like to play as X or O?" << "\n";
        cin >> xo;
        if (xo != 'X' || xo != 'O')
        {xo = xo-32;}

    }while(!(xo == 'X' || xo == 'O'));


}
void showBoard(char boardcurrent[firstsize][secondsize],char ease_of_use_play_field_copy[firstsize][secondsize])
{
    for(int i =0; i < firstsize; i++)
    {
     for(int j =0; j < secondsize; j++)
     {
        cout << boardcurrent[i][j];

     }
     cout << "\n";
    }


    for(int i =0; i < firstsize; i++)
    {
     for(int j =0; j < secondsize; j++)
     {
        cout << ease_of_use_play_field_copy[i][j];

     }
     cout << "\n";
    }
}
char getMove(char &xo)
{
    int movefield;
    bool done_entering_field = false;



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
bool checkWin(char &xo, char &xoPC, bool &PCwon, bool &won, const char *pointtofieldone, const char *pointtofieldtwo, const char *pointtofieldthree, const char *pointtofieldfour,
const char *pointtofieldfive, const char *pointtofieldsix, const char *pointtofieldseven, const char *pointtofieldeight, const char *pointtofieldnine )
{
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

bool checkDraw(int movefield, char &xo, char *pointtofieldone,  char *pointtofieldtwo, char *pointtofieldthree,  char *pointtofieldfour,
 char *pointtofieldfive, char *pointtofieldsix, char *pointtofieldseven, char *pointtofieldeight, char *pointtofieldnine )
{
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

bool playagain()
{
    bool playagain = false;
    bool cincheck = false;
    char playing;
    while(!cincheck)
    {
        cout << "Would you like to play again? Y/N" << "\n";
        cin >> playing;
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(2000,'\n');
            continue;
        }
        switch(playing)
        {
        case 'Y':
        case 'y':
            playagain = false;
            cincheck = true;
            break;
        case 'N':
        case 'n':
            playagain = true;
            cincheck = true;
            break;
        default:
            cout << "invalid input" << "\n";
            break;
        }
    }
    return playagain;
}

bool PCplayer(char &xoPC,char *pointtofieldone, char *pointtofieldtwo, char *pointtofieldthree, char *pointtofieldfour,char *pointtofieldfive,
                char *pointtofieldsix, char *pointtofieldseven, char *pointtofieldeight, char *pointtofieldnine)
{
    bool isvalid = false;

    do{
            int PCmoving = rand() % 9 + 1;

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

bool checkTieNoWin(const char *pointtofieldone, const char *pointtofieldtwo, const char *pointtofieldthree, const char *pointtofieldfour,
const char *pointtofieldfive, const char *pointtofieldsix, const char *pointtofieldseven, const char *pointtofieldeight, const char *pointtofieldnine)
{
    bool IsItATieGame = false;
    if (*pointtofieldone != ' ' && *pointtofieldtwo != ' ' && *pointtofieldthree != ' ' && *pointtofieldfour != ' ' && *pointtofieldfive != ' '
        && *pointtofieldsix != ' ' && *pointtofieldseven != ' ' && *pointtofieldeight != ' ' && *pointtofieldnine != ' ')
    {
        IsItATieGame = true;
    }
    return IsItATieGame;
}
