#ifndef BOARD_H
#define BOARD_H


#include <SDL2/SDL.h>
#include <string>
#include "combo.hh"
#include "../lib/sdl.hh"

struct Board
{
    int x;
    int y;
    float frame;
    Combo *combo1;
    Combo *combo2;
    SDL_Texture *player_1;
    SDL_Texture *player_2;
    SDL_Texture *background;
    SDL_Texture *coins;
};

namespace Board {
  Board buildBoard(int x, int y, Combo *combo1, Combo *combo2);

  void loadBoard(Board &board, SDL_Texture *player_1, SDL_Texture *player_2, SDL_Texture *coins, SDL_Texture  *background);
  void drawBoard(Board board,TTF_Font *font, SDL_Texture *player1, SDL_Texture *player2, int currentlyPlaying);
}

#endif
