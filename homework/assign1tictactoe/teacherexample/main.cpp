//
//  main.cpp
//  TTT
//
//  Created by Jim Bailey on 1/6/17.
//  Copyright © 2017 jim. All rights reserved.
//

#include <iostream>
#include <locale>   // for tolower();

using namespace std;

    // constants for validating input
const int BIG_NUM = 100;
const char EOL = '\n';
const int ROW = 3;
const int COL = 3;
const char SPACE = ' ';

    // function prototypes
void instructions();
void displayBoard(char board[ROW][COL]);
void getMove(char board[ROW][COL], char player);
bool checkWin(char board[ROW][COL]);
bool checkTie(char board[ROW][COL]);
bool playAgain();


int main()
{
        // define variables
    char theBoard[3][3];
    char player = 'X';
    bool playing = true;
    
        // repeat until user wants to quit
    do {
        // initialize the game
        for(int i = 0; i < ROW; i++)
            for(int j = 0; j < COL; j++)
                theBoard[i][j] = SPACE;
        playing = true;
        player = 'X';
        
        instructions();
        
            // play until win or tie
        while (playing)
        {
            displayBoard(theBoard);
            cout << "Player " << player << " it is your turn." << endl;
            getMove(theBoard, player);
            if ( checkWin(theBoard) )
            {
                cout << "The final board is " << endl;
                displayBoard(theBoard);
                cout << "Player " << player << " won!" << endl;
                playing = false;
            }
            else
            {
                if ( checkTie(theBoard) )
                {
                    cout << "Tie, no one wins!"  << endl;
                    playing = false;
                }
            }

            player = (player == 'X')?'O':'X';
        }
    } while (playAgain());
    
    cout << "Thanks for playing my game." << endl;
    
    return 0;
}

    // display the instructions
void instructions()
{
    cout << "This is the game of Tic-Tac-Toe" << endl
        << "It is played on a 3x3 board. Each" << endl
        << "player in turn picks a loction to" << endl
        << "move to. The first player is X and" << endl
        << "the second is O. The game ends when" << endl
        << "one player gets three in a row or " << endl
        << "there are no more moves." << endl;
}

    // display the board
void displayBoard(char board[][COL])
{
        // This does it brute force rather than using loops
        // This makes it easier to see what is being output
    cout << "     1     2     3  " << endl;
    cout << "        |     |     " << endl;
    cout << " 1   " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << endl;
    
    cout << "   _____|_____|_____" << endl;
    cout << "        |     |     " << endl;
    
    cout << " 2   " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << endl;
    
    cout << "   _____|_____|_____" << endl;
    cout << "        |     |     " << endl;
    
    cout << " 3   " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << endl;
    
    cout << "        |     |     " << endl << endl;
}

    // get a move and update board
    // input is 1-3, so that a 0 indicates non-integer input
void getMove(char board[ROW][COL], char player)
{
    int row, col;
    bool valid = true;
    
        // get a move and verify that it is good
    do {
        valid = true;
        cout << "Enter a row and a column between 1 and 3" << endl;
        cin >> row >> col;
        if ( row > 0 and row <= ROW and col > 0 and col <= COL )
        {
                // legal move, now see if empty square
            if ( board[row-1][col-1] != SPACE )
            {
                cout << "That space is occupied, try again" << endl;;
                valid = false;
                cin.clear();
                cin.ignore(BIG_NUM, EOL);
            }
        }
            // not a legal move
        else
        {
            cout << "Your move is not on the board, try again" << endl;
            valid = false;
            cin.clear();
            cin.ignore(BIG_NUM, EOL);
        }
    } while ( !valid );
    cout << "Moving to " << row-1 << ", " << col-1 << endl;
    
    board[row-1][col-1] = player;
}

    // win if three in row
bool checkWin(char board[ROW][COL])
{               // diagonals
    if (    ( board[0][0] == board[1][1] and board[1][1] == board[2][2] and board[0][0] != SPACE )
        or  ( board[0][2] == board[1][1] and board[1][1] == board[2][0] and board[0][2] != SPACE )
                // rows
        or  ( board[0][0] == board[0][1] and board[0][1] == board[0][2] and board[0][0] != SPACE )
        or  ( board[1][0] == board[1][1] and board[1][1] == board[1][2] and board[1][0] != SPACE )
        or  ( board[2][0] == board[2][1] and board[2][1] == board[2][2] and board[2][0] != SPACE )
                // columns
        or  ( board[0][0] == board[1][0] and board[1][0] == board[2][0] and board[0][0] != SPACE )
        or  ( board[0][1] == board[1][2] and board[1][1] == board[2][1] and board[0][1] != SPACE )
        or  ( board[0][2] == board[1][2] and board[1][2] == board[2][2] and board[0][2] != SPACE )
        )
        return true;
    return false;
}

    // see if board full
bool checkTie(char board[ROW][COL])
{
        // if there are any spaces, not tie
    for(int i = 0; i < ROW; i++)
        for(int j = 0; j < COL; j++)
            if (board[i][j] == ' ')
                return false;
    
    return true;
}

    // checks to see if the user wants to go again
    // returns true if the response is 'Y' or 'y'
bool playAgain()
{
    char answer;
    cout << "Do you want to go again? (Y/N) ";
    cin >> answer;
    answer = tolower(answer);
    
        // validate intput
    do {
        if ( answer != 'y' and answer != 'n')
        {
            cout << "invalid input, need a 'Y' or 'N'" << endl;
            cin.clear();
            cin.ignore(BIG_NUM, EOL);
            cin >> answer;
            answer = tolower(answer);
        }
    } while (answer != 'y' and answer != 'n');
    
        // return true if they responded with y or Y
    return answer == 'y';
}

