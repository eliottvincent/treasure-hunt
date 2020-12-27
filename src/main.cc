#include "game.hh"
#include "menu.hh"

int main(int argc, char *argv[])
{
  Game &game = Game::getInstance();

  game.init();
  game.changeState(Menu::instance());

  SDL_Event event;

  while (game.running())
  {
    while(SDL_PollEvent(&event))
    {
      if(event.type == SDL_QUIT)
      {
        game.quit();
      }
    }

    game.handleEvents();
    game.update();
    game.draw();
  }

  // fprintf(stderr, "%s\n", (SDL_GetError()));
  // exit(1);

  game.cleanup();

  return 0;
}
