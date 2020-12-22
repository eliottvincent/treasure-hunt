/********************************************************************************************
 * Project: Treasure Hunt
 * File: menu.cc
 * ------------------------------------------------------------------------------------------
 * Authors: Pierre Lethuillier, Eliott Vincent
 * License: This work is licensed under the Creative Commons
 *          Attribution-NonCommercial-ShareAlike 4.0 International License.
 *********************************************************************************************/

 #include "menu.h"

int menu(SDL_Surface *screen)
{
    //we first load all the assets that are necessary to the menu
    TTF_Font *small = TTF_OpenFont("assets/font.ttf", 20);
    SDL_Surface *button_sprite = LoadImageTransparent("assets/button.png",0,255,255);
    SDL_Surface *background = load_image("assets/background.png");

    Button play = createButton(button_sprite, "Jouer", SCREEN_WIDTH/2 - 500/2, SCREEN_HEIGHT-150, small);
    Button quit = createButton(button_sprite, "Quitter", SCREEN_WIDTH/2 + 80/2, SCREEN_HEIGHT-150, small);

    bool done=false;
    int gamestate = 0;

    while(!done)
    {
        int startTicks = SDL_GetTicks();

        gamestate = menuEvents(&play, &quit);

        if(gamestate != 0)
            done = true;

        drawMenu(screen, background, &play, &quit);
        SDL_Flip(screen);

        manageFrames(startTicks);
    }
    SDL_FreeSurface(button_sprite);
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

void drawMenu(SDL_Surface *screen, SDL_Surface *background, Button *play, Button *quit)
{
    //we draw the background
    SDL_Rect backgroundPosition;
    backgroundPosition.x = 0;
    backgroundPosition.y = 0;

    SDL_BlitSurface(background, NULL, screen, &backgroundPosition);

    SDL_Flip(screen);

    //we draw the buttons on the screen
    drawButton(play, screen);
    drawButton(quit, screen);
}
