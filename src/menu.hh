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

// #include <SDL2/SDL.h>
// #include <cstdlib>
// #include <iostream>
// #include <string>
// #include "../lib/sdl.hh"
// #include "plate.hh"
#include "treasureHunt.hh"
#include "button.hh"
// #include "player.hh"

extern SDL_Renderer *renderer;

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
int menu();

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
void drawMenu(SDL_Texture *background, Button *play, Button *quit);

#endif
