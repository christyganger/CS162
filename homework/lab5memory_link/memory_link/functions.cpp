/*
Program written by christy wear
last modified: 3/26/2019
version 1.3

cis 162C+
*/
#include "header.h"

//welcome text.
void welcome()
{
    cout << welcome_out_text_1 << "\n";
    cout << welcome_out_text_2 << "\n";
    cout << welcome_out_text_3 << "\n";
}

// clears the play field each time it's played.
void clear_play_field(t_player *player_one, char *play_field)
{
    for (int i = 0; i < 16; i++)
    {
        play_field[i] = space_holder;
    }
    return;
}

// prints play field/ demo field/ or selected cards
void print_play_field(t_player *player_one, char *play_field, int *demo_field)
{
    // display 2 = math / no match, both selected. Anything above 1, runs it again.
    // display 4 = special case only runs for first card.
    if (player_one->display >= 1)
        if (player_one->display == 4)
        {
            cout << clear_screen;
            welcome();
            cout << "\n" << print_play_out_text_1 << player_one->move_1 << "\n";
            for(int i = 0; i < 4; i++)
                    {
                        cout <<  newline_seporate;
                        for(int j = 0; j < 4; j++)
                        {
                            cout << col_seporate;
                            cout << setw(2);
                            if (demo_field[player_one->move_1] == i*4+j)
                            {
                                cout << play_field[player_one->move_1];
                            }
                            else if (demo_field[player_one->move_2] == i*4+j)
                            {
                                cout << play_field[player_one->move_2];
                            }
                            else if (demo_field[i*4+j] == num_holder)
                            {
                                cout << space_holder;
                            }
                            else
                            {
                                cout << demo_field[i*4+ j];
                            }
                            cout << col_seporate;
                        }
                        cout << newline_seporate;
                    }

                player_one->display = 0;
                return;
        }
        if (player_one->debug == false)
            if (player_one->match == false)
                {

                    for(int i = 0; i < 4; i++)
                    {
                        cout <<  newline_seporate;
                        for(int j = 0; j < 4; j++)
                        {
                            cout << col_seporate;
                            cout << setw(2);
                            if (demo_field[player_one->move_1] == i*4+j)
                            {
                                cout << play_field[player_one->move_1];
                            }
                            else if (demo_field[player_one->move_2] == i*4+j)
                            {
                                cout << play_field[player_one->move_2];
                            }
                            else if (demo_field[i*4+j] == num_holder)
                            {
                                cout << space_holder;
                            }
                            else
                            {
                                cout << demo_field[i*4+ j];
                            }
                            cout << col_seporate;
                        }
                        cout << newline_seporate;
                    }

                    if(player_one->display > 1)
                        {
                            view_pause();
                        }
                    player_one->display = player_one->display-1;
                    player_one->move_1 = num_holder;
                    player_one->move_2 = num_holder;

                    return ;
                }

                if (player_one->match == true)
                {

                    for(int i = 0; i < 4; i++)
                    {
                        cout <<  newline_seporate;
                        for(int j = 0; j < 4; j++)
                        {
                            cout << col_seporate;
                            cout << setw(2);
                            if (demo_field[player_one->move_1] == i*4+j)
                            {
                                cout << play_field[player_one->move_1];
                            }
                            else if (demo_field[player_one->move_2] == i*4+j)
                            {
                                cout << play_field[player_one->move_2];
                            }
                            else if (demo_field[i*4+j] == num_holder)
                            {
                                cout << space_holder;
                            }
                            else
                            {
                                cout << demo_field[i*4+ j];
                            }
                            cout << col_seporate;
                        }
                        cout << newline_seporate;
                    }
                   if(player_one->display > 1)
                        {
                            view_pause();
                        }
                    player_one->display = player_one->display-1;
                    play_field[player_one->move_1] = space_holder;
                    play_field[player_one->move_2] = space_holder;
                    demo_field[player_one->move_1] = num_holder;
                    demo_field[player_one->move_2] = num_holder;
                    player_one->match = false;


                    return ;
                }


        if (player_one->debug == true)
            {
                cout << "\n\n" << print_play_debug_out_text << "\n\n";
                for(int i = 0; i < 4; i++)
                {
                cout <<  newline_seporate;
                for(int j = 0; j < 4; j++)
                {
                    cout << col_seporate;
                    cout << setw(2);
                    cout << play_field[i*4+ j];
                    cout << col_seporate;
                }
                cout << newline_seporate;
                }
                player_one->debug = false;
                return ;
            }
   }

// generates the play field with symbols, and scrambles them
void populate_play_field(t_player *player_one, char *play_field)
{
    //generate random pairs

    for(int i = 0; i < 8; i++)
    {
            play_field[8+i] = symbol_arr[i];
            play_field[i] = symbol_arr[i];
    }
    // randomize the pairs.
    int n = size_play_field;
    for (int i = 0; i < n; i++)
    {
        int r = rand() % n;
        char temp = play_field[i];
        play_field[i] = play_field[r];
        play_field[r] = temp;
    }

    return;
}

// generates the 1-15 numbers for demo board
void populate_demo_board (t_player *player_one, int *demo_field)
{
    // generate array
    for(int i = 0; i < 16; i++)
    {

        demo_field[i] = i;
    }


    return;

}

//checks for needing to clear display before move, then gets new move
void get_move(t_player *player_one, char *play_field, int *demo_field)
{
    if (player_one->display == false)
    {

    cout << "\n" << get_move_out_text_1 << "\n";
    cin >> player_one->move_1;
    while(player_one->move_1 < 0 || player_one->move_1 > 15 || cin.fail() || play_field[player_one->move_1] == space_holder)
    {
        cin.clear();
        cin.ignore(1000,'\n');
        cout << get_move_out_text_2 << "\n";
        cin >> player_one->move_1;
    }

    player_one->display = 4;
    print_play_field(player_one, play_field, demo_field);

    cout << "\n" << get_move_out_text_3 << "\n";
    cin >> player_one->move_2;
    while(player_one->move_2 < 0 || player_one->move_2 > 15 || cin.fail() || play_field[player_one->move_2] == space_holder
          || player_one->move_1 == player_one->move_2)
    {
        cin.clear();
        cin.ignore(1000,'\n');
        cout << get_move_out_text_4 << "\n";
        cin >> player_one->move_2;
    }
    return;
    }
    else
    {
        print_play_field(player_one, play_field, demo_field);
        get_move(player_one, play_field, demo_field);
        return;
    }
}

// checks if player's move's match on the play field
void check_if_match(t_player *player_one, char *play_field)
{

    if (play_field[player_one->move_1] == play_field[player_one->move_2])
    {
        cout << clear_screen << check_match_out_text_1 << "\n";
        player_one->match = true;
        player_one->display = 2;


    } else
    { cout << clear_screen << check_match_out_text_2 << "\n";
        player_one->match = false;
        player_one->display = 2;
    }
        return ;
}

// checks to see if other cards are left.
bool check_for_win(t_player *player_one, char *play_field)
{
    bool done = false;
    int match_counter = 0;
    for(int i = 0; i < size_play_field; i++)
    {
        if (play_field[i] == space_holder)
            match_counter++;
    }
    if (match_counter == 16)
    {
        done = true;
        cout << clear_screen;
        cout << check_for_win_out_text_1 << "\n";
        cout << check_for_win_out_text_2 << "\n";
        getchar();
    }
    if (done == false)
        welcome();
    return done;
}

//pauses the game between showing cards selected, and demo board.
void view_pause()
{
    cout << view_pause_out_text_1 << "\n";
    getchar();
    cin.ignore();
    cout << clear_screen;
    return;
}

// ask user if wants to play again? if so .. resets everything starts over.
// if not exits.
bool play_again(t_player *player_one)
{
    char to_play_or_not_to_play;
    bool annoy_restate = true;
    do
    {
        cout << play_again_out_text_1;
        cout << play_again_out_text_2;
        cin >> to_play_or_not_to_play;
        while(cin.fail())
        {
            cin.ignore(1000,'\n');
            cout << play_again_out_text_3 << "\n";
            cin >> to_play_or_not_to_play;
        }
        switch(to_play_or_not_to_play)
        {
        case 'n':
        case 'N':
            cin.ignore(1000,'\n');
            cout << play_again_out_text_4 << "\n";
            getchar();
            cin.ignore();
            player_one->play_again = false;
            annoy_restate = false;
            break;

        case 'y':
        case 'Y':
            cin.ignore(1000,'\n');
            cout << play_again_out_text_5 << "\n";
            player_one->play_again = true;
            annoy_restate = false;
            break;
        default:
            cout << play_again_out_text_6 << "\n";
            cin.clear();
            cin.ignore(1000,'\n');
            break;
        }
    }while(annoy_restate);
    return player_one->play_again;
}
