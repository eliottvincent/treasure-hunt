#ifndef BUTTON_H
#define BUTTON_H

#include <SDL2/SDL.h>
#include <cstdlib>
#include <string>
#include "../lib/sdl.hh"

struct Button
{
    int x;
    int y;
    int width;
    int height;

    SDL_Texture *sprite;
    TTF_Font *font;

    std::string text;
};

Button createButton(SDL_Texture *psprite, std::string text, int px, int yp, TTF_Font *font);

void drawButton(Button *pbutton);
bool buttonEvent(SDL_Event *event, Button *button);

#endif
