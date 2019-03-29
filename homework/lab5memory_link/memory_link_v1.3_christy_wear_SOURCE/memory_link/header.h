/*
Program written by christy wear
last modified: 3/26/2019
version 1.3
cis 162C+
*/

#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include "const_global_and_text.h"

using namespace std;


struct t_player {
bool play_again = false;
bool debug = false;
bool match = false;
int display = 1;
int move_1 = num_holder;
int move_2 = num_holder;
};

//welcome text.
void welcome();

// clears the play field each time it's played.
void clear_play_field(t_player *player_one, char *play_field);

// prints play field/ demo field/ or selected cards
void print_play_field(t_player *player_one, char *play_field, int *demo_field);

// generates the play field with symbols, and scrambles them
void populate_play_field(t_player *player_one, char *play_field);

// generates the 1-15 numbers for demo board
void populate_demo_board (t_player *player_one, int *demo_field);

//checks for needing to clear display before move, then gets new move
void get_move(t_player *player_one, char *play_field, int *demo_field);

// checks if player's move's match on the play field
void check_if_match(t_player *player_one, char *play_field);

// checks to see if other cards are left.
bool check_for_win(t_player *player_one, char *play_field);

//pauses the game between showing cards selected, and demo board.
void view_pause();

// ask user if wants to play again? if so .. resets everything starts over.
// if not exits.
bool play_again(t_player * player_one);

#endif // HEADER_H_INCLUDED
