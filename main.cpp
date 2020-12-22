/********************************************************************************************
 * Project: Treasure Hunt
 * File: main.cpp
 * ------------------------------------------------------------------------------------------
 * Authors: Pierre Lethuillier, Eliott Vincent
 * License: This work is licensed under the Creative Commons
 *          Attribution-NonCommercial-ShareAlike 4.0 International License.
 *********************************************************************************************/

#include <SDL2/SDL.h>
#include "treasureHunt.h"
#include "sdlFunctions.h"
#include "game.h"
#include "menu.h"
#include "gain.h"
#include <cstdlib>

/**************** Name of the function **********************
∗ main()			                                        *
∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗ Description ****************************
∗ It launches the gamestate logic                           *
∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗ Input *************************************
∗ Nothing                                                   *
∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗ Output ********************************
∗ Nothing                                                   *
************************************************************/
int main()
{
    SDL_Surface *screen;
    srand(time(NULL));
    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();
    screen=SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32, SDL_SWSURFACE);

    int gamestate = 0;
    bool quit=false;

    while(!quit)
    {
        switch(gamestate)
        {
        case 0:
            gamestate = menu(screen);
            break;
        case 1:
            gamestate = game(screen);
            break;
        case 2:
            quit=true;
            break;
        }
    }
    TTF_Quit();
    SDL_Quit();
    return 0;
}
