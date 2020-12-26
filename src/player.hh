#ifndef PLAYER_H
#define PLAYER_H

#include <SDL2/SDL.h>
#include <cmath>
#include <climits>
#include "../lib/sdl.hh"
#include "plate.hh"

/**************** Name of the structure *********************
∗ Player()			                                        *
∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗ Description ****************************
∗ It defines the parameter of the player                    *
∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗ Input *************************************
∗ Nothing                                                   *
∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗ Output ********************************
∗ Nothing                                                   *
************************************************************/
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

/**************** Name of the function **********************
∗ createPlayer()			                                *
∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗ Description ****************************
∗ It creates a player with the help of the strcture         *
* "Player"                                                  *
∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗ Input *************************************
∗ The id of the player, his position, the sprite            *
∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗ Output ********************************
∗ The player                                                *
************************************************************/
Player createPlayer(int id, Vector2 position, SDL_Texture *sprite);

/**************** Name of the function **********************
∗ deletePayer() 			                                *
∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗ Description ****************************
∗ It deletes a player                                       *
∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗ Input *************************************
∗ The player                                                *
∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗ Output ********************************
∗ Nothing                                                   *
************************************************************/
void destroyPlayer(Player &player);

/**************** Name of the function **********************
∗ stopPlayer()    			                                *
∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗ Description ****************************
∗ It stops the mouvment of a player                         *
∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗ Input *************************************
∗ The player                                                *
∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗ Output ********************************
∗ Nothing                                                   *
************************************************************/
void stopPlayer(Player &player);

/**************** Name of the function **********************
∗ deletePayer() 			                                *
∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗ Description ****************************
∗ It updates a player                                       *
∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗ Input *************************************
∗ The player                                                *
∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗ Output ********************************
∗ Nothing                                                   *
************************************************************/
bool updatePlayer(Player &player, Map tiles);

/**************** Name of the function **********************
∗ movePlayer() 			                                    *
∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗ Description ****************************
∗ It moves a player                                         *
∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗ Input *************************************
∗ The player, his destination                               *
∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗ Output ********************************
∗ Nothing                                                   *
************************************************************/
void movePlayer(Player &player, Vector2 destination, Map tiles);

/**************** Name of the function **********************
∗ drawPlayer() 			                                    *
∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗ Description ****************************
∗ It draws a player on the screen                           *
∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗ Input *************************************
∗ The player, the screen's surface                          *
∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗ Output ********************************
∗ Nothing                                                   *
************************************************************/
void drawPlayer(Player player);

/**************** Name of the function **********************
∗ getCoinPlayer() 			                                *
∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗ Description ****************************
∗ It picks up a coin or not (depends where the player is)   *
∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗ Input *************************************
∗ The player, the plate                                     *
∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗ Output ********************************
∗ A bool                                                   *
************************************************************/
bool getCoinPlayer(Player &player, Map tiles);

#endif
