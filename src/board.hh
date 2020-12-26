#ifndef BOARD_H
#define BOARD_H


#include <SDL2/SDL.h>
#include <string>
#include "combo.hh"
#include "../lib/sdl.hh"

/**************** Name of the structure *********************
∗ Board						                                *
∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗ Description ****************************
∗ It defines the parameters of the board        	        *
∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗ Input *************************************
∗ Nothing                                                   *
∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗ Output ********************************
∗ Nothing                                                   *
************************************************************/

struct Board
{
    int x;
    int y;
    float frame;
    Combo *combo1;
    Combo *combo2;
    SDL_Texture *player_1;
    SDL_Texture *player_2;
    SDL_Texture *background;
    SDL_Texture *coins;
};

/**************** Name of the function **********************
∗ buildboard()						                        *
∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗ Description ****************************
∗ It builds the board, with the parameters of the structure *
* "Board"                                                   *
∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗ Input *************************************
∗ x, y, both combos                                         *
∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗ Output ********************************
∗ i, the index of the frame                                 *
************************************************************/
Board buildBoard(int x, int y, Combo *combo1, Combo *combo2);

/**************** Name of the function **********************
∗ laodBoard()					                            *
∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗ Description ****************************
∗ It loads the board (players, coins, etc...)      	        *
∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗ Input *************************************
∗ The structure "Board", all the surfaces needed            *
∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗ Output ********************************
∗ All the surfaces created                                  *
************************************************************/
void loadBoard(Board &board, SDL_Texture *player_1, SDL_Texture *player_2, SDL_Texture *coins, SDL_Texture  *background);

/**************** Name of the function **********************
∗ drawBoard()				                                *
∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗ Description ****************************
∗ It draws the board on the screen               	        *
∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗ Input *************************************
∗ The font, all the surfaces created by loadBoard()         *
∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗ Output ********************************
∗ The board                                                 *
************************************************************/
void drawBoard(Board board,TTF_Font *font, SDL_Texture *player1, SDL_Texture *player2, int currentlyPlaying);

#endif
