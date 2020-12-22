/********************************************************************************************
 * Project: Treasure Hunt
 * File: gain.h
 * ------------------------------------------------------------------------------------------
 * Authors: Pierre Lethuillier, Eliott Vincent
 * License: This work is licensed under the Creative Commons
 *          Attribution-NonCommercial-ShareAlike 4.0 International License.
 *********************************************************************************************/

#ifndef GAIN_H
#define GAIN_H

#include <iostream>
#include <fstream>
#include <string>
#include <climits>
#include "treasureHunt.h"
#include "../lib/sdlFunctions.h"
#include "button.h"
#include "player.h"

/**************** Name of the function **********************
∗ gain						                                *
∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗ Description ****************************
∗ It draws the "gain" screen we a player win     	        *
∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗ Input *************************************
∗ The screen's surface, the player who won                  *
∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗ Output ********************************
∗ The "gain" screen                                         *
************************************************************/
int gain(SDL_Window *screen, Player *winner);

/**************** Name of the function **********************
∗ gainEvents						                        *
∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗ Description ****************************
∗ It manages the events ont the "gain" screen      	        *
∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗ Input *************************************
∗ The buttons                                               *
∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗ Output ********************************
∗ The gamestate                                             *
************************************************************/
int gainEvents(Button *replay, Button *quit);

#endif
