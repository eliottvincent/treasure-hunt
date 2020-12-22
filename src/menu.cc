/********************************************************************************************
 * Project: Treasure Hunt
 * File: menu.cc
 * ------------------------------------------------------------------------------------------
 * Authors: Pierre Lethuillier, Eliott Vincent
 * License: This work is licensed under the Creative Commons
 *          Attribution-NonCommercial-ShareAlike 4.0 International License.
 *********************************************************************************************/

#include "menu.hh"
#include "button.cc"

int menu()
{
  bool done     = false;
  int gamestate = 0;

  // we first load all the assets that are necessary to the menu
  TTF_Font *small            = TTF_OpenFont("assets/font.ttf", 20);
  SDL_Texture *button_sprite = load_image_transparent("assets/button.png",0,255,255);
  SDL_Texture *background    = load_image("assets/background.png");
  Button play                = createButton(button_sprite, "Jouer", WINDOW_WIDTH/2 - 500/2, WINDOW_HEIGHT-150, small);
  Button quit                = createButton(button_sprite, "Quitter", WINDOW_WIDTH/2 + 80/2, WINDOW_HEIGHT-150, small);

  while(!done)
  {
      int startTicks = SDL_GetTicks();

      gamestate = menuEvents(&play, &quit);

      if(gamestate != 0)
      {
        done = true;
      }

      drawMenu(background, &play, &quit);
      SDL_RenderPresent(renderer);

      manageFrames(startTicks);
  }

  return gamestate;
}

int menuEvents(Button *play, Button *quit)
{
    int gamestate = 0;
    SDL_Event event;

    while(SDL_PollEvent(&event))
    {
        //when the player clicks on the "play" button
        if(buttonEvent(&event, play))
        {
            gamestate = 1;
        }

        //when the player clicks on the "quit" button
        if(buttonEvent(&event, quit))
        {
            gamestate = 2;
        }

        //when the player quits the window
        if(event.type == SDL_QUIT)
        {
            gamestate = 2;
            break;
        }
    }
    return gamestate;
}

void drawMenu(SDL_Texture *background, Button *play, Button *quit)
{
    //we draw the background
    SDL_Rect backgroundPosition;
    backgroundPosition.x = 0;
    backgroundPosition.y = 0;

    SDL_RenderCopy(renderer, background, NULL, &backgroundPosition);

    SDL_RenderPresent(renderer);

    //we draw the buttons on the screen
    drawButton(play);
    drawButton(quit);
}
