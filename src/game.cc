/********************************************************************************************
 * Project: Treasure Hunt
 * File: game.cc
 * ------------------------------------------------------------------------------------------
 * Authors: Pierre Lethuillier, Eliott Vincent
 * License: This work is licensed under the Creative Commons
 *          Attribution-NonCommercial-ShareAlike 4.0 International License.
 *********************************************************************************************/

#include "game.hh"

using namespace std;

int game(SDL_Window *screen)
{
    //we load the necessary assets
    TTF_Font *big, *small;
    SDL_Surface *player1_sprite, *player2_sprite, *coins;

    big = TTF_OpenFont("assets/font.ttf", 50);
    small = TTF_OpenFont("assets/font.ttf", 25);
    player1_sprite = LoadImageTransparent("assets/player1.png",0,255,255);
    player2_sprite = LoadImageTransparent("assets/player2.png",0,255,255);
    coins = LoadImageTransparent("assets/coins.bmp",0,255,255);

    //we create the logicals vars of the game
    bool done = false;
    int gamestate = 1;
    int current_turn = 0;

    //we create the plate
    Map tiles;
    initPlate(tiles);

    //we create the players
    Vector2 coords;
    coords.x = PLATE_SIZE/2;
    coords.y = PLATE_SIZE/2;
    Player players[2];
    players[0] = createPlayer(1, coords, player1_sprite);
    players[1] = createPlayer(2, coords, player2_sprite);

    //we create the baord
    Combo combo1 = createCombo(20, 140, &players[0]);
    Combo combo2 = createCombo(120, 140, &players[1]);
    Board board = buildBoard(60*PLATE_SIZE, 10, &combo1, &combo2);
    loadBoard(board, player1_sprite, player2_sprite, coins,  NULL);

    //the game's logic
    while(!done)
    {
        int startTicks = SDL_GetTicks();
        SDL_Event event;
        while(SDL_PollEvent(&event))
        {

            //if we close the window
            if(event.type == SDL_QUIT)
            {
                gamestate = 2;
                done = true;
                break;
            }
            //if we click
            if(event.type == SDL_MOUSEBUTTONDOWN)
            {
                manageClick(event, players, current_turn, tiles);
                break;
            }
        }

        //we update the player's data
        if(updatePlayer(players[current_turn], tiles))
        {
            current_turn+=1;
            if(current_turn>1)
                current_turn = 0;
            players[current_turn].position = getOtherPlayer(players, current_turn).position;
            players[current_turn].coords = getOtherPlayer(players, current_turn).position;
        }

        //we check if there is a winner or not
        int winner = doesAPlayerWon(players, tiles);
        if(winner != 0)
        {
            done = true;
            gamestate = gain(screen, &players[winner-1]);
        }

        //we clear the screen
        SDL_Rect  rect;
        rect.x = 0;
        rect.y = 0;
        rect.w = SCREEN_WIDTH;
        rect.h = SCREEN_HEIGHT;
        SDL_FillRect(screen, &rect, SDL_MapRGB(screen->format, 231, 208, 14));

        //we draw the plate with the coins
        drawPlate(tiles, coins, screen);

        //we draw the players
        drawPlayer(players[current_turn], screen);

        //we draw the board
        drawBoard(board, small, screen, player1_sprite, player2_sprite, current_turn+1);

        //we refresh the screen
        SDL_Flip(screen);

        if(!done)
            manageFrames(startTicks);
    }
    return gamestate;
}

void manageClick(SDL_Event &event, Player players[], int &current_turn, Map tiles)
{
    if(event.type == SDL_MOUSEBUTTONDOWN)
    {
        int x = event.button.x;
        int y = event.button.y;

        //we test if the click is inside the plate or not
        if(x>=0 && x<=PLATE_SIZE*60 && y>=0 && y<=PLATE_SIZE*60)
        {
            Vector2 coords;
            coords.x = (int)(x/60);
            coords.y = (int)(y/60);
            movePlayer(players[current_turn], coords, tiles);
        }
    }
}

Player getOtherPlayer(Player players[], int currentTurn)
{
    currentTurn = currentTurn -1;
    if(currentTurn<0)
        currentTurn = 1;
    return players[currentTurn];
}

int doesAPlayerWon(Player players[], Map tiles)
{
    int winner = 0;
    int index = 0;
    while(index < 2 && winner == 0)
    {
        int px =round((players[index].position.x) / 60);
        int py = round((players[index].position.y) / 60);

        //we test if the player can move
        bool found = false;
        int y = 0;
        while(y<PLATE_SIZE-1 && !found)
        {
            if(tiles[px][y].value != 0)
                found = true;
            y+=1;
        }
        int x = 0;
        while(!found && x < PLATE_SIZE-1)
        {
            if(tiles[x][py].value != 0)
                found = true;
            x+=1;
        }
        if(!found)
            winner = getOtherPlayer(players, index).id;
        if(players[index].points >= 500)
        {
            winner = players[index].id;
        }
        index+=1;
    }
    return winner;
}
