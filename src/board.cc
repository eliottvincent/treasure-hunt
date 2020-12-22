/********************************************************************************************
 * Project: Treasure Hunt
 * File: board.cc
 * ------------------------------------------------------------------------------------------
 * Authors: Pierre Lethuillier, Eliott Vincent
 * License: This work is licensed under the Creative Commons
 *          Attribution-NonCommercial-ShareAlike 4.0 International License.
 *********************************************************************************************/

#include "board.hh"

using namespace std;

Board buildBoard(int x, int y, Combo *combo1, Combo *combo2)
{
    Board i;
    i.x = x;
    i.y = y;

    //we set up the coordinates of the both combos
    combo2->x = x+combo2->x;
    combo2->y = y+combo2->y;
    combo1->x = x+combo1->x;
    combo1->y = y+combo1->y;

    i.combo1 = combo1;
    i.combo2 = combo2;
    i.frame = 0;
    return i;
}

void loadBoard(Board &board, SDL_Texture *player1, SDL_Texture *player2, SDL_Texture *coins, SDL_Texture *background)
{
    //we load all the surfaces that are necessary to the board
    board.background = background;
    board.player_1 = player1;
    board.player_2 = player2;
    board.coins = coins;
}

void drawBoard(Board board,TTF_Font *font, SDL_Texture *player1, SDL_Texture *player2, int currentlyPlaying)
{
    //we draw the two combos
    drawCombo(*board.combo1, font);
    drawCombo(*board.combo2, font);

    //we draw the pictures of the two players on the right side of the board
    SDL_Rect clip;
    clip.x=0;
    clip.y=4*60;
    clip.h=60;
    clip.w=60;

    SDL_Rect player_2Position;
    player_2Position.x = 560;
    player_2Position.y = 100;

    SDL_BlitSurface(player2, NULL, &player_2Position);

    SDL_Rect player_1Position;
    player_1Position.x = 440;
    player_1Position.y = 100;

    SDL_BlitSurface(player1, NULL, &player_1Position);

    SDL_Flip(screen);

    RGBA color;
    color.r = 150;
    color.g = 150;
    color.b = 150;
    color.a = 255;

    //we draw the score of the first player
    string m = convertToString(board.combo1->player->points);
    Vector2 v = getTextSize(m, font);
    drawText(m, board.combo1->x+24-v.x/2, board.combo1->y+110,font, 32, color);

    //we draw the score of the second player
    m = convertToString(board.combo2->player->points);
    v = getTextSize(m, font);
    drawText(m, board.combo2->x+24-v.x/2, board.combo2->y+110,font, 32, color);

    //we draw the last picked coins
    int index = getIndexInSpriteSheet(board.combo1->player->lastCoin);
    if(index>-1)
    {
        clip.x = index;
        clip.y = 0, clip.w = 60;
        clip.h = 60;
        apply_surface(board.combo1->x+24-28, board.combo1->y-134, board.coins, &clip);
    }
    index = getIndexInSpriteSheet(board.combo2->player->lastCoin);
    if(index>-1)
    {
        clip.x = index;
        clip.y = 0, clip.w = 60;
        clip.h = 60;
        apply_surface(board.combo2->x+24-28, board.combo2->y-134, board.coins, &clip);
    }
}
