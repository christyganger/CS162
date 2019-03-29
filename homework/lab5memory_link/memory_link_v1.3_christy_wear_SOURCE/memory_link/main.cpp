/*
Program written by christy wear
last modified: 3/26/2019
version 1.3
cis 162C+
*/
#include "header.h"

int main()
{
    welcome();
    t_player *player_one = new t_player;

    char *play_field = new char [size_play_field];
    int *demo_field = new int [size_play_field];

    srand(time(NULL));
    do{
    populate_demo_board(player_one, demo_field);

    clear_play_field(player_one, play_field);

    //playfield

    print_play_field(player_one, play_field, demo_field);

    //populate playfield
    populate_play_field(player_one, play_field);
    bool play_loop_done = false;

    do{

        get_move(player_one, play_field, demo_field);

        check_if_match(player_one, play_field);
        print_play_field(player_one, play_field, demo_field);

    //debug
    //player_one->debug = true;
    //print_play_field(player_one);

    play_loop_done = check_for_win(player_one, play_field);
    }while(!play_loop_done);

    }while(play_again(player_one));
    delete play_field;
    delete demo_field;
    delete player_one;
    return 0;
}
