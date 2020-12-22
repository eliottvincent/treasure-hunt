/********************************************************************************************
 * Project: Treasure Hunt
 * File: menu.h
 * ------------------------------------------------------------------------------------------
 * Authors: Pierre Lethuillier, Eliott Vincent
 * License: This work is licensed under the Creative Commons
 *          Attribution-NonCommercial-ShareAlike 4.0 International License.
 *********************************************************************************************/

#ifndef menu_H
#define menu_H

#include <SDL2/SDL.h>
#include <cstdlib>
#include <iostream>
#include <string>
#include "sdlFunctions.h"
#include "plate.h"
#include "treasureHunt.h"
#include "button.h"
#include "player.h"

/**************** Name of the function **********************
∗ menu()			                                        *
∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗ Description ****************************
∗ It loads the necessary assets for the menu, and manages   *
* the gamestate                                             *
∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗ Input *************************************
∗ The screen's surface                                      *
∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗ Output ********************************
∗ The gamestate                                             *
************************************************************/
int menu(SDL_Surface *screen);

/**************** Name of the function **********************
∗ menuEvents()			                                    *
∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗ Description ****************************
∗ It manages the SDL events in the menu                     *
∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗ Input *************************************
∗ The buttons                                               *
∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗ Output ********************************
∗ The gamestate                                             *
************************************************************/
int menuEvents(Button *play, Button *quit);


/**************** Name of the function **********************
∗ drawMenu()			                                    *
∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗ Description ****************************
∗ It draws the menu on the screen                           *
∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗ Input *************************************
∗ The necessary surfaces                                    *
∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗ Output ********************************
∗ The menu                                                  *
************************************************************/
void drawMenu(SDL_Surface *screen, SDL_Surface *background, Button *play, Button *quit);

#endif
