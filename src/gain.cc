#include "gain.hh"

int gain(Player *winner)
{
    SDL_Texture *button_sprite;
    TTF_Font *big, *small;

    //we load the necessary assets
    big = TTF_OpenFont("assets/font.ttf", 50);
    small = TTF_OpenFont("assets/font.ttf", 20);
    button_sprite = load_image_transparent("assets/button.png", 0, 255, 255);

    bool done = false;
    int gamestate = 2;

    Button replay = createButton(button_sprite,"Rejouer", 640/2-100,WINDOW_HEIGHT-130,small);
    Button quit = createButton(button_sprite,"Quitter", 640/2-100,WINDOW_HEIGHT-70,small);

    while(!done)
    {
        int startTicks = SDL_GetTicks();

        gamestate = gainEvents(&replay, &quit);
        if(gamestate != 2)
        {
            done=true;
        }

        //we clear the screen
        SDL_Rect  rect;
        rect.x = 0;
        rect.y = 0;
        rect.w = WINDOW_WIDTH;
        rect.h = WINDOW_HEIGHT;
        SDL_FillRect(screen, &rect, SDL_MapRGB(screen->format, 231, 208, 14));

        //we draw the buttons
        drawButton(&replay);
        drawButton(&quit);

        //we draw the text
        RGBA white;
        white.r = 255; white.g = 255; white.b = 255; white.a = 255;
        std::string msg = "Le joueur " + convertToString(winner->id) + " a gagne !";
        Vector2 size = getTextSize(msg, big);
        drawText(msg, WINDOW_WIDTH/2 - size.x /2-25, 100, big, 20, white);

        SDL_RenderPresent(renderer);
        manageFrames(startTicks);
    }
    return gamestate;
}

int gainEvents(Button *replay, Button *quit)
{
    int gamestate = 2;
    SDL_Event event;
    while(SDL_PollEvent(&event))
    {
        if(event.type == SDL_QUIT || buttonEvent(&event, quit))
        {
            gamestate = 2;
            break;
        }
        if(buttonEvent(&event, replay))
        {
            gamestate = 1;
            break;
        }
    }
    return gamestate;
}
