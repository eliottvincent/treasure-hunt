/********************************************************************************************
 * Project: Treasure Hunt
 * File: board.h
 * ------------------------------------------------------------------------------------------
 * Authors: Pierre Lethuillier, Eliott Vincent
 * License: This work is licensed under the Creative Commons
 *          Attribution-NonCommercial-ShareAlike 4.0 International License.
 *********************************************************************************************/

#ifndef BOARD_H
#define BOARD_H


#include <SDL2/SDL.h>
#include <string>
#include "combo.h"
#include "../lib/sdlFunctions.h"

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
    SDL_Surface *player_1;
    SDL_Surface *player_2;
    SDL_Surface *background;
    SDL_Surface *coins;
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
void loadBoard(Board &board, SDL_Surface *player_1, SDL_Surface *player_2, SDL_Surface *coins, SDL_Surface  *background);

/**************** Name of the function **********************
∗ drawBoard()				                                *
∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗ Description ****************************
∗ It draws the board on the screen               	        *
∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗ Input *************************************
∗ The font, all the surfaces created by loadBoard()         *
∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗ Output ********************************
∗ The board                                                 *
************************************************************/
void drawBoard(Board board,TTF_Font *font, SDL_Window *screen, SDL_Surface *player1, SDL_Surface *player2, int currentlyPlaying);

#endif
