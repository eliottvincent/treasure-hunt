/********************************************************************************************
 * Project: Treasure Hunt
 * File: player.cc
 * ------------------------------------------------------------------------------------------
 * Authors: Pierre Lethuillier, Eliott Vincent
 * License: This work is licensed under the Creative Commons
 *          Attribution-NonCommercial-ShareAlike 4.0 International License.
 *********************************************************************************************/

#include "player.hh"

using namespace std;

Player createPlayer(int id, Vector2 coords, SDL_Texture *sprite)
{
    Player p;
    p.id = id;
    p.coords = coords;
    p.position.x = coords.x*60;
    p.position.y = coords.y*60;
    p.points = 0;
    p.combo = 0;
    p.lastCoin = 0;
    p.sprite = sprite;
    p.frame = 0;
    p.target.x = -1;
    p.target.y = -1;
    p.turn = 0;
    return p;
}

void destroyPlayer(Player &player)
{
    SDL_FreeSurface(player.sprite);
}

bool updatePlayer(Player &player, Map tiles)
{
    bool changeTurn = false;

    //we update the position of the player (visual)
    player.position.x += 0.03F*player.velocity.x;
    player.position.y += 0.03F*player.velocity.y;
    //On diminue la velocité
    player.velocity.x -= 0.03F*player.velocity.x;
    player.velocity.y -= 0.03F*player.velocity.y;

    //if the velocity is less than 6, then we set it to 0
    if(abs(player.velocity.x) <= 6)
        player.velocity.x = 0;
    if(abs(player.velocity.y) <= 6)
        player.velocity.y = 0;

    //if the player moves, then we increase the frame compt
    if(abs(player.velocity.x) > 0 || abs(player.velocity.y) > 0)
        player.frame += 0.25;

    if(player.frame > 3)
        player.frame = 0;


    //we update the position of the player (tiles)
    player.coords.x = round((player.position.x) / 60);
    player.coords.y = round((player.position.y) / 60);


    //we stop the player
    if(player.velocity.x > 0 && player.position.x > player.target.x * 60)
        stopPlayer(player);
    else if(player.velocity.x < 0 && player.position.x < player.target.x * 60)
        stopPlayer(player);

    if(player.velocity.y > 0 && player.position.y > player.target.y * 60)
        stopPlayer(player);
    else if(player.velocity.y < 0 && player.position.y < player.target.y * 60)
        stopPlayer(player);

    //if the player is on a tile, the he picks up the coin (or not)
    if(player.velocity.x == 0 && player.velocity.y == 0)
    {
        player.position.x = player.coords.x * 60;
        player.position.y = player.coords.y * 60;
        changeTurn = getCoinPlayer(player, tiles);
    }
    return changeTurn;
}

void stopPlayer(Player &player)
{
        //we stop the player
        player.target.x = -1;
        player.target.y = -1;
        player.velocity.x = 0;
        player.velocity.y = 0;
        player.frame = 0;
}

void movePlayer(Player &player, Vector2 destination, Map tiles)
{

    if(player.velocity.x == 0 && player.velocity.y == 0)
    {
        //we test if the destination isn't a diagonal tile
       if(destination.x !=  player.coords.x && destination.y != player.coords.y)
            return;
        //we test if the tile contains a coin
        if(tiles[(int)destination.x][(int)destination.y].value == 0)
            return;
        player.target = destination;
        int w = player.coords.x - destination.x;
        int h = player.coords.y - destination.y;
        if(abs(w)>abs(h))
            player.velocity.x = -w*60*1.5;
        else
            player.velocity.y = -h*60*1.55;
        player.turn +=1;
    }
}

bool getCoinPlayer(Player &player, Map tiles)
{
    Coin c = tiles[(int)player.coords.x][(int)player.coords.y];

    //we test if the coin is empty
    if(c.value == 0)
        return false;

    //we test if the coin the player has just picked up is the same as the last he picked up (combo)
    if(player.lastCoin == c.value)
        player.combo += 1;
    else
        player.combo = 0;
    if(player.combo > 4)
        player.combo = 4;

    //we calc the combo
    if(player.combo > 0)
    {
        player.points+= 10*pow(2, (player.combo-1));
    }

    player.points += c.value;
    player.lastCoin = c.value;

    //then, the tile become an empty tile
    c.value = 0;
    tiles[(int)player.coords.x][(int)player.coords.y] = c;
    return true;
}

void drawPlayer(Player player)
{
    int x = (int)player.position.x;
    int y = (int)player.position.y;

    SDL_Rect rect;
    rect.x = 1;
    rect.y = 1;
    rect.w = 60;
    rect.h = 60;
    apply_texture(player.sprite, x, y, &rect);
}
