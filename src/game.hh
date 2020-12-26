
#define game_H

#include <SDL2/SDL.h>
#include <cstdlib>
#include <iostream>
#include <string>
#include "../lib/sdl.hh"
#include "plate.hh"
#include "treasureHunt.hh"
#include "button.hh"
#include "player.hh"
#include "combo.hh"
#include "board.hh"
#include "gain.hh"

extern SDL_Renderer *renderer;

int game();

void manageClick(SDL_Event &event, Player players[], int &current_turn, Map tiles);

Player getOtherPlayer(Player players[], int currentTurn);

int doesAPlayerWon(Player players[], Map tiles);

#endif
