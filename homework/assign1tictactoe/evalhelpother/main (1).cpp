#include <iostream>
#include <windows.h>
// included for random functions
#include <cstdlib>
// included to get the time for srand
#include <ctime>

/*******************************
 *
 *TicTacToe
 *
 * Finished Code By Lawrence Warner
 * CS 162 C++
 * Last Modified: 1/13/19
 *******************************/

using namespace std;

// Prototype Functions
    // global constants
        const char X = 'X';
        const char x = X;
        const char O = 'O';
        const char o = O;

        // play_again Strings
        const string restart_app = " \n Would you like to start over?";
        const string user_yn = " [y/n]: ";
        const string thanks_playing = " Thanks for playing. \n";
        const string error_entry = " That's not valid input, please type Y for yes, or N for no \n";
        const string new_line = " \n ";

        //Board Variables
        char Square1('1');
        char Square2('2');
        char Square3('3');
        char Square4('4');
        char Square5('5');
        char Square6('6');
        char Square7('7');
        char Square8('8');
        char Square9('9');

    // function declarations
        void showInstructions();
        char playerchoiceXO();
        char player_choice;
        char player1 = x;
        char player2 = o;
        void showBoard();
        void initBoard();
        char get_Move;
        int getMove(char &get_Move);
        char repeatMove();
        int repeat_Move();
        void updateBoard();
        bool win, tie;
        bool checkWin();
        bool checkTie();
        void TogglePlayer();
        bool repeat();
        bool play_again();



int main()
{
    // display instructions
        showInstructions();
    // Initialize board
        initBoard();

    // play again loop
    do
    {
        // get player choice of x or o

        playerchoiceXO();
            // repeat loop
            do
            {
                // game loop
                do
                    {
                        // display board
                        showBoard();
                        // get next move
                        getMove(get_Move);
                        repeatMove();
                        // update board
                        updateBoard();
                        // check for win
                        win = checkWin();
                        // check for tie
                        tie = checkTie();
                        // if game not over, swap player
                        if (not win and not tie)
                        {
                        // swap player
                        TogglePlayer();
                        }
                    }
                    while (not win and not tie);
                // display final board and congratulate winner
				if (win)
                    {
                    showBoard();
                    cout << " \n Congratulations " << player_choice << "'s you won." << endl;
                    break;
                    }
				else (tie);
                    {
                    showBoard();
                    cout << " \n The game was a tie. " << endl;
                    break;
                    }


            }
            while (repeat() );
    }
	while (play_again());
return 0;
}

// function definitions
	void showInstructions()
	{
		cout << " \n " << " Tic-Tac-Toe " << endl;
		cout << " \n " << " Instructions " << endl;
		cout << " \n " << " 1. The game is played on a grid that's 3 squares by 3 squares. " << endl;
		cout << " \n " << " 2. You have a choice between X's and O's. " << endl;
        cout << "    Players take turns putting their marks in empty squares. " << endl;
		cout << " \n " << " 3. The first player to get 3 of their marks in a row (up, down, " << endl;
		cout << "    across, or diagonally) is the winner. " << endl;
		cout << " \n " << " 4. When all 9 squares are full, the game is over. If no player " << endl;
		cout << "    has 3 marks in a row, the game ends in a tie. " << endl;
		cout << " \n " << endl;
		system(" pause ");


	}

	// initialize game
	void initBoard()
	{
		cout << " \n " << "Initializing Board" << endl;
		cout << endl << "                                                            Loading" << endl;
        Sleep(1000);
            cout << "                                                          *";
        Sleep(1200);
            cout << "*";
        Sleep(1000);
            cout << "*";
        Sleep(1100);
            cout << "*";
        Sleep(500);
            cout << "*";
        Sleep(500);
            cout << "*";
        Sleep(1000);
            cout << "*";
        Sleep(1500);
            cout << "*";
        Sleep(2000);
            cout << "*";
        Sleep(2500);
            cout << "*";
        Sleep(3000);
            cout << "*";
        Sleep(4000);
        cout << " \n " << endl;
	}

    // get player choice of x or o
	char playerchoiceXO()
	{
	    cout << " \n " << " Would you like to be X's or O's?: ";
		cin >> player_choice;
		while ( player_choice == x || player_choice == X || player_choice == o || player_choice == O)
            {
                cout << " \n" << " Wrong input. Please, try again: ";

                //clear input buffer
                cin.clear();
                cin.ignore();

                cout << " \n" << " Please enter either and X or an O : ";
                cin >> player_choice;
            }
            if (player_choice == x || player_choice == X)
            {
                cout << " You have chosen to play " << player_choice << "'s" << endl;
                player1 = x;
            }
            else
            {
                cout << " You have chosen to play " << player_choice << "'s" << endl;
                player2 = o;
            }
        return player_choice;
	}

	// show board
	void showBoard()
	{
		//cout << "\033[2J\033[1;1H";
		cout << " \n " << endl;
		cout << "     -----+-----+-----" << endl;
		cout << "       " << Square1 << "  |  " << Square2 << "  |  " << Square3 << endl;
        cout << "     -----+-----+-----" << endl;
        cout << "       " << Square4 << "  |  " << Square5 << "  |  " << Square6 << endl;
        cout << "     -----+-----+-----" << endl;
        cout << "       " << Square7 << "  |  " << Square8 << "  |  " << Square9 << endl;
        cout << "     -----+-----+-----" << endl;

	}

	// get player move
	int getMove(char &get_Move)
	{
    cout << " \n It is player " << player_choice << "'s turn! " << endl;
        int get_select;
		cout << " \n " << " Pick a space you would like to play (1-9): ";
		cin >> get_select;
		cout << "christy debug getMove func line 226 " << get_select << "\n";
		do
        {
            while (get_select < 1 || get_select > 9)
            {
                cout << " ERROR: Please choose between 1-9!! " <<endl;
                cin.clear();
                cin.ignore();
                cout << " \n " << " Pick a space you would like to play (1-9): ";
                cin >> get_select;
            }
                cout << "\033[2J\033[1;1H";
            cout << "christy debug getMove func line 238 " << get_select << "\n";
            switch(get_select)
            {
                case 1:
                        if (get_select == 1)
                            {
                        get_Move = Square1;
                        Square1 = player_choice;
                        cout << " You have chosen space " << get_select << "." << endl;
                        break;
                            }
                case 2:
                        if (get_select == 2)
            {
                        get_Move = Square2;
                        Square2 = player_choice;
                        cout << " You have chosen space " << get_select << "." << endl;
                        break;
            }
                case 3:
                        if (get_select == 3)
            {
                        get_Move = Square3;
                        Square3 = player_choice;
                        cout << " You have chosen space " << get_select << "." << endl;
                        break;
            }
                case 4:
                        if (get_select == 4)
            {
                        get_Move = Square4;
                        Square4 = player_choice;
                        cout << " You have chosen space " << get_select << "." << endl;
                        break;
            }
                case 5:
                        if (get_select == 5)
            {
                        get_Move = Square5;
                        Square5 = player_choice;
                        cout << " You have chosen space " << get_select << "." << endl;
                        break;
            }
                case 6:
                        if (get_select == 6)
            {
                        get_Move = Square6;
                        Square6 = player_choice;
                        cout << " You have chosen space " << get_select << "." << endl;
                        break;
            }
                case 7:
                        if (get_select == 7)
            {
                        get_Move = Square7;
                        Square7 = player_choice;
                        cout << " You have chosen space " << get_select << "." << endl;
                        break;
            }
                case 8:
                        if (get_select == 8)
            {
                        get_Move = Square8;
                        Square8 = player_choice;
                        cout << " You have chosen space " << get_select << "." << endl;
                        break;
            }
                case 9:
                        if (get_select == 9);
            {
                        get_Move = Square9;
                        Square9 = player_choice;
                        cout << " You have chosen space " << get_select << "." << endl;
                        break;
            }
            }
        }while(!getMove);

		return get_Move;
	}

	// check for valid move
	char repeatMove()
	{
	    cout << " checking for valid move " << Square1 << endl;
	    cout << "christy debug repeatMove func line 323 " << get_Move << "\n";
	    switch(get_Move)
            {
                case 'o':
                        if (get_Move == 'o')
                            {
                            cout << " Space is used! " << endl;
                            cout << " Please select another space " << endl;
                            break;
                            }
                case 'x':
                        if (get_Move == 'x')
                            {
                            cout << " Space is used! " << endl;
                            cout << " Please select another space " << endl;
                            break;
                            }


            }
          return true;
	}

	// update board
	void updateBoard()
	{
		cout << " Updating board" << endl;
		cout << get_Move << endl;
		cout << player_choice << endl;
		cout <<  Square1 << endl;
	}

	// check for win
	bool checkWin()
	{
	    {
        if (Square1 == Square2 && Square2 == Square3)
            {
                return true;
            }
            else if (Square4 == Square5 && Square5 == Square6)
            {
                return true;
            }
            else if (Square7 == Square8 && Square8 == Square9)
            {
                return true;
            }
            else if (Square1 == Square4 && Square4 == Square7)
            {
                return true;
            }
            else if (Square2 == Square5 && Square5 == Square8)
            {
                return true;
            }
            else if (Square3 == Square6 && Square6 == Square9)
            {
                return true;
            }
            else if (Square1 == Square5 && Square5 == Square9)
            {
                return true;
            }
            else if (Square3 == Square5 && Square5 == Square7)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }

    // check for tie
	bool checkTie()
	{
            if (Square1 != '1' && Square2 != '2' && Square3 != '3'
                    && Square4 != '4' && Square5 != '5' && Square6 != '6'
                  && Square7 != '7' && Square8 != '8' && Square9 != '9')
            {
                return true;
            }
		return false;
	}

	// repeat
	bool repeat()
	{
        cout << " checking for repeat" <<  Square1 << endl;
		return true;
	}

	// toggle players
	void TogglePlayer()
            {
            if (player_choice == 'x')
                player_choice = 'o';

            else
                player_choice = 'x';
            }
// no inputs, return true if the user wants	to go again, false if they do not gfhfh
    bool play_again()
    {
        bool done = false;
        char start_over;
        bool prog_end = true;
                // Restart or Exit App
                    // ask user to start over
                    while (prog_end)
                    {
                                cout << restart_app << endl;
                                cout << user_yn;
                                cin >> start_over;
                                cout << new_line << endl;
                    switch (start_over)
                        {
                        case 'n':
                        case 'N':
                                cout << thanks_playing << endl;
                            // exit switch loop
                            done = false;
                            prog_end = false;

                            break;
                        case 'Y':
                        case 'y':
                            // exit switch loop
                            cin.clear();
                            cin.ignore();
                            cout << "\033[2J\033[1;1H";
                                prog_end = false;
                                done = true;

                            break;

                        default:
                                cout << error_entry << new_line;

                            break;
                            }


                    }
                    return done;
    }

