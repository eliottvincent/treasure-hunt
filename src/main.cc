/********************************************************************************************
 * Project: Treasure Hunt
 * File: main.cpp
 * ------------------------------------------------------------------------------------------
 * Authors: Pierre Lethuillier, Eliott Vincent
 * License: This work is licensed under the Creative Commons
 *          Attribution-NonCommercial-ShareAlike 4.0 International License.
 *********************************************************************************************/

#include <cstdlib>
#include <stdlib.h>
#include <iostream>
#include <SDL2/SDL.h>

#include "../lib/sdlFunctions.hh"
#include "treasureHunt.hh"
#include "game.hh"
#include "menu.hh"
#include "gain.hh"


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
  int gamestate = 0;
  bool quit     = false;

  srand(time(NULL));

  SDL_Init(SDL_INIT_EVERYTHING);
  TTF_Init();

  SDL_Window *window = SDL_CreateWindow(
    "My Game Window",

    SDL_WINDOWPOS_UNDEFINED,
    SDL_WINDOWPOS_UNDEFINED,

    WINDOW_WIDTH, WINDOW_HEIGHT,

    SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL
  );

  while(!quit)
  {
    switch(gamestate)
    {
      case 0:
        printf("0");
        gamestate = menu(window);

        break;
      case 1:
        // printf("1");
        // gamestate = game(window);

        break;
      case 2:
        printf("2");
        quit = true;

        break;
    }
  }

  // Close and destroy the window
  SDL_DestroyWindow(window);

  // Clean up
  TTF_Quit();
  SDL_Quit();

  return 0;
}
