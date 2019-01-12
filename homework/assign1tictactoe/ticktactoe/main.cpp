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

using namespace std;
const int firstsize = 10;
const int secondsize =12;
void displayinstructions(char &xo);
void showBoard(char boardcurrent[firstsize][secondsize]);
char getMove(char &xo);
bool checkWin(char &xo, char &xoPC, bool &PCwon, bool &won, const char *pointtofieldone, const char *pointtofieldtwo, const char *pointtofieldthree,
              const char *pointtofieldfour, const char *pointtofieldfive, const char *pointtofieldsix, const char *pointtofieldseven, const char *pointtofieldeight, const char *pointtofieldnine );
bool checkDraw(int movefield, char &xo, char *pointtofieldone, char *pointtofieldtwo, char *pointtofieldthree, char *pointtofieldfour,char *pointtofieldfive,
                char *pointtofieldsix, char *pointtofieldseven, char *pointtofieldeight, char *pointtofieldnine );
bool PCplayer(char &xoPC, char *pointtofieldone, char *pointtofieldtwo, char *pointtofieldthree, char *pointtofieldfour,char *pointtofieldfive,
                char *pointtofieldsix, char *pointtofieldseven, char *pointtofieldeight, char *pointtofieldnine);
bool playagain();

int main()
{
    char xo;
    char xoPC;
    bool done = false;
    bool playersturn = false;
    bool won = false;
    bool PCwon = false;
    /* initialize random seed: */
    srand (time(NULL));
    playersturn = rand() % 1 + 0;
    do
        {char boardcurrent[firstsize][secondsize] = {{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' '},{' ',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' '},
        {' ','_','_','_','|','_','_','_','|','_','_','_'},{' ',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' '},{' ',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' '},
        {' ','_','_','_','|','_','_','_','|','_','_','_'},{' ',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' '},{' ',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' '},
        {' ',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' '} },*pointtofieldone, *pointtofieldtwo, *pointtofieldthree, *pointtofieldfour, *pointtofieldfive, *pointtofieldsix,
        *pointtofieldseven, *pointtofieldeight, *pointtofieldnine;


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

        *pointtofieldone = '1';
        *pointtofieldtwo = '2';
        *pointtofieldthree = '3';
        *pointtofieldfour  = '4';
        *pointtofieldfive = '5';
        *pointtofieldsix  = '6';
        *pointtofieldseven = '7';
        *pointtofieldeight = '8';
        *pointtofieldnine = '9';


        while(!done)
        {
            if (playersturn == true)
            {

                playersturn = false;
                if (checkDraw(getMove(xo), xo, pointtofieldone, pointtofieldtwo, pointtofieldthree, pointtofieldfour, pointtofieldfive,
                    pointtofieldsix, pointtofieldseven, pointtofieldeight, pointtofieldnine) == true)
                {
                    showBoard(boardcurrent);
                    if(checkWin(xo, xoPC, PCwon, won, pointtofieldone, pointtofieldtwo, pointtofieldthree, pointtofieldfour,
                                 pointtofieldfive, pointtofieldsix, pointtofieldseven, pointtofieldeight, pointtofieldnine) == true)
                    {
                        if(PCwon == true)
                        {
                            cout << "You lose!" << "\n";
                        }
                        if(won == true)
                        {
                            cout << "You win!" << "\n";
                        }
                        done = true;
                        continue;
                    }

                }
                if (checkDraw(getMove(xo), xo, pointtofieldone, pointtofieldtwo, pointtofieldthree, pointtofieldfour, pointtofieldfive,
                    pointtofieldsix, pointtofieldseven, pointtofieldeight, pointtofieldnine) == false)
                {
                    showBoard(boardcurrent);
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
                showBoard(boardcurrent);
                if(checkWin(xo, xoPC, PCwon, won, pointtofieldone, pointtofieldtwo, pointtofieldthree, pointtofieldfour, pointtofieldfive, pointtofieldsix, pointtofieldseven,
                    pointtofieldeight, pointtofieldnine ) == true)
                      {
                        if(PCwon == true)
                        {
                            cout << "You lose!" << "\n";
                        }
                        if(won == true)
                        {
                            cout << "You win!" << "\n";
                        }
                        done = true;
                        continue;
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

    }while(!(xo == 'X' || xo == 'O'));


}
void showBoard(char boardcurrent[firstsize][secondsize])
{
    for(int i =0; i < firstsize; i++)
    {
     for(int j =0; j < secondsize; j++)
     {
        cout << boardcurrent[i][j];
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
    //pc win check
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
        if (*pointtofieldnine == '9')
        {
           *pointtofieldnine = xo;
            isvalid = true;
        }

        break;

    case 8:
        if (*pointtofieldeight == '8')
        {
            *pointtofieldeight = xo;
            isvalid = true;
        }
        break;

    case 7:
        if (*pointtofieldseven == '7')
        {
            *pointtofieldseven = xo;
            isvalid = true;
        }
        break;

    case 6:
        if (*pointtofieldsix == '6')
        {
            *pointtofieldsix = xo;
            isvalid = true;
        }
        break;

    case 5:
        if (*pointtofieldfive == '5')
        {
           *pointtofieldfive = xo;
            isvalid = true;
        }
        break;

    case 4:
        if (*pointtofieldfour == '4')
        {
            *pointtofieldfour = xo;
            isvalid = true;
        }
        break;

    case 3:
        if (*pointtofieldthree == '3')
        {
            *pointtofieldthree = xo;
            isvalid = true;
        }
        break;

    case 2:
        if (*pointtofieldtwo == '2')
        {
            *pointtofieldtwo = xo;
            isvalid = true;
        }
        break;

    case 1:
        if (*pointtofieldone == '1')
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
            if (*pointtofieldnine == '9')
            {
               *pointtofieldnine = xoPC;
                isvalid = true;
            }

            break;

        case 8:
            if (*pointtofieldeight == '8')
            {
                *pointtofieldeight = xoPC;
                isvalid = true;
            }
            break;

        case 7:
            if (*pointtofieldseven == '7')
            {
                *pointtofieldseven = xoPC;
                isvalid = true;
            }
            break;

        case 6:
            if (*pointtofieldsix == '6')
            {
                *pointtofieldsix = xoPC;
                isvalid = true;
            }
            break;

        case 5:
            if (*pointtofieldfive == '5')
            {
               *pointtofieldfive = xoPC;
                isvalid = true;
            }
            break;

        case 4:
            if (*pointtofieldfour == '4')
            {
                *pointtofieldfour = xoPC;
                isvalid = true;
            }
            break;

        case 3:
            if (*pointtofieldthree == '3')
            {
                *pointtofieldthree = xoPC;
                isvalid = true;
            }
            break;

        case 2:
            if (*pointtofieldtwo == '2')
            {
                *pointtofieldtwo = xoPC;
                isvalid = true;
            }
            break;

        case 1:
            if (*pointtofieldone == '1')
            {
                *pointtofieldone = xoPC;
                isvalid = true;
            }
            break;

        default:
            cout << "input check error in PCplayer / PCmove:" << "\n";
            break;

        }
    }while(!isvalid);
return isvalid;
}
