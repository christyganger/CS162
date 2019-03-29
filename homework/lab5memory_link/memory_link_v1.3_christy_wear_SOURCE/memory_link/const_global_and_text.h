/*
Program written by christy wear
last modified: 3/26/2019
version 1.3
cis 162C+
*/
#ifndef CONST_GLOBAL_AND_TEXT_H_INCLUDED
#define CONST_GLOBAL_AND_TEXT_H_INCLUDED
#include "header.h"
using namespace std;


const char space_holder = ' ';
const int num_holder = -1;
const string newline_seporate = "\n |- - - - - - - - - - -|\n";
const string col_seporate = " |";
const int size_symbol = 8;
const int size_play_field = 16;
const char symbol_arr[size_symbol] = {'@','#','$','%','~','&','+','!'};
const string clear_screen = "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
const string welcome_out_text_1 = "Welcome to the game \"memory\". ";
const string welcome_out_text_2 = "This is where you pick two cards, those two cards are checked for match and displayed";
const string welcome_out_text_3 = "If they are a match, they are removed from the play field.";
const string print_play_out_text_1 = "First card selected as number ";
const string print_play_debug_out_text = "***DEBUG SCREEN ***";
const string get_move_out_text_1 = "please select first card ";
const string get_move_out_text_2 = "selection invalid, please select first card, . ";
const string get_move_out_text_3 = "please select second card ";
const string get_move_out_text_4 = "selection invalid, please select second card";
const string check_match_out_text_1 = "     MATCH FOUND!!";
const string check_match_out_text_2 = "     MATCH NOT FOUND!";
const string check_for_win_out_text_1 = "congratulations on winning!!!";
const string check_for_win_out_text_2 = "press Enter, or Return to continue";
const string view_pause_out_text_1 = "Press Enter, or Return once you've memorized the cards.";
const string play_again_out_text_1 = "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
const string play_again_out_text_2 = " Would you like to play again? (Y\\n): ";
const string play_again_out_text_3 = "BAD INPUT, BAD! Go sit in the corner!";
const string play_again_out_text_4 = "Thanks for playing:) , press Enter, or Return to close this window ";
const string play_again_out_text_5 = "YAY! Enjoy your next round, it's on me!";
const string play_again_out_text_6 = "That's not (y)es or (n)o, Please type something less gibberish";

#endif // CONST_GLOBAL_AND_TEXT_H_INCLUDED
