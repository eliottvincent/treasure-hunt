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

#include "../lib/sdl.hh"
#include "treasureHunt.hh"
// #include "game.cc"
#include "menu.cc"


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
  IMG_Init(IMG_INIT_PNG);
  TTF_Init();

  window = SDL_CreateWindow(
    "My Game Window",

    SDL_WINDOWPOS_CENTERED,
    SDL_WINDOWPOS_CENTERED,

    WINDOW_WIDTH, WINDOW_HEIGHT,

    SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL
  );

  renderer = SDL_CreateRenderer(window, -1, 0);

  while(!quit)
  {
    switch(gamestate)
    {
      case 0:
        printf("0");
        gamestate = menu();

        break;
      case 1:
        printf("1");
        // gamestate = game();

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
  IMG_Quit();
  TTF_Quit();
  SDL_Quit();

  return 0;
}
