/********************************************************************************************
 * Project: Treasure Hunt
 * File: combo.h
 * ------------------------------------------------------------------------------------------
 * Authors: Pierre Lethuillier, Eliott Vincent
 * License: This work is licensed under the Creative Commons
 *          Attribution-NonCommercial-ShareAlike 4.0 International License.
 *********************************************************************************************/

#ifndef COMBO_H
#define COMBO_H

#include <SDL2/SDL.h>
#include <iostream>
#include "player.hh"
#include "../lib/sdlFunctions.hh"

/**************** Name of the strcture **********************
∗ Combo						                                *
∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗ Description ****************************
∗ It defines the parameters of the combo        	        *
∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗ Input *************************************
∗ Nothing                                                   *
∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗ Output ********************************
∗ Nothing                                                   *
************************************************************/
struct Combo
{
    int x;
    int y;
    float frame;
    Player *player;
    int lastCombo;
};

/**************** Name of the function **********************
∗ createCombo						                        *
∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗ Description ****************************
∗ It creates the combo                            	        *
∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗ Input *************************************
∗ The coordinates, the player (player1 or player2)          *
∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗ Output ********************************
∗ The combo                                                   *
************************************************************/
Combo createCombo(int x, int y, Player *player);

/**************** Name of the function **********************
∗ drawCombo						                            *
∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗ Description ****************************
∗ It draws the combo on the screen's surface       	        *
∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗ Input *************************************
∗ The created combo, the font, the screen's surface         *
∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗ Output ********************************
∗ The Combo                                                   *
************************************************************/
void drawCombo(Combo combo, TTF_Font *font,  SDL_Window *screen);

#endif
