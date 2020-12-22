#ifndef game_H
/********************************************************************************************
 * Project: Treasure Hunt
 * File: game.h
 * ------------------------------------------------------------------------------------------
 * Authors: Pierre Lethuillier, Eliott Vincent
 * License: This work is licensed under the Creative Commons
 *          Attribution-NonCommercial-ShareAlike 4.0 International License.
 *********************************************************************************************/

#define game_H

#include <SDL2/SDL.h>
#include <cstdlib>
#include <iostream>
#include <string>
#include "../lib/sdlFunctions.hh"
#include "plate.hh"
#include "treasureHunt.hh"
#include "button.hh"
#include "player.hh"
#include "combo.hh"
#include "board.hh"
#include "gain.hh"

/**************** Name of the function **********************
∗ game						                                *
∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗ Description ****************************
∗ It loads the assets and creates the game's logic 	        *
∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗ Input *************************************
∗ The screen's surface                                      *
∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗ Output ********************************
∗ The gamestate                                             *
************************************************************/
int game(SDL_Window *screen);

/**************** Name of the function **********************
∗ manageClick						                        *
∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗ Description ****************************
∗ It manages the clicks ers of the board        	        *
∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗ Input *************************************
∗ The SDL events, the players                               *
∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗ Output ********************************
∗ Nothing                                                   *
************************************************************/
void manageClick(SDL_Event &event, Player players[], int &current_turn, Map tiles);

/**************** Name of the function **********************
∗ getOtherPlayer    		                                *
∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗ Description ****************************
∗ It checks if the players need to turn or not     	        *
∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗ Input *************************************
∗ The players                                               *
∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗ Output ********************************
∗ The turn of the player                                    *
************************************************************/
Player getOtherPlayer(Player players[], int currentTurn);

/**************** Name of the function **********************
∗ doesAPlayerWon()		                                    *
∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗ Description ****************************
∗ It checks if a player won                        	        *
∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗ Input *************************************
∗ The player, the plate                                     *
∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗ Output ********************************
∗ The winner                                                *
************************************************************/
int doesAPlayerWon(Player players[], Map tiles);

#endif
