
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
int menu();



void drawMenu(SDL_Texture *background, Button *play, Button *quit);

#endif
