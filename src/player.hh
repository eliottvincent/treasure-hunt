#ifndef PLAYER_H
#define PLAYER_H

#include <SDL2/SDL.h>
#include <cmath>
#include <climits>
#include "../lib/sdl.hh"
#include "plate.hh"

struct Player
{
    int id;
    SDL_Texture *sprite;
    Vector2 position;
    Vector2 coords;
    Vector2 velocity;
    Vector2 target;
    int points;
    int combo;
    int lastCoin;
    float frame;
    int turn;
};

Player createPlayer(int id, Vector2 position, SDL_Texture *sprite);

void destroyPlayer(Player &player);
void stopPlayer(Player &player);
void movePlayer(Player &player, Vector2 destination, Map tiles);
void drawPlayer(Player player);

bool updatePlayer(Player &player, Map tiles);
bool getCoinPlayer(Player &player, Map tiles);

#endif
