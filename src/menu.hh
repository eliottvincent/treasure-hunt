#ifndef MENU_H
#define MENU_H

#include <SDL2/SDL.h>

#include "../lib/sdl.hh"

#include "state.hh"
#include "treasureHunt.hh"
#include "button.hh"

class Menu: public State {
  protected:
    Menu() {}

  private:
    static Menu m_menu;

    SDL_Surface *background;

  public:
    void init();
    void cleanup();

    void pause();
    void resume();

    void handleEvents(Game *game);
    void update(Game *game);
    void draw(Game *game);

    static Menu *instance() { return &m_menu; };

    // Old Methods
    int menuEvents(Button *play, Button *quit);
    void drawMenu(SDL_Texture *background, Button *play, Button *quit);
};

#endif
