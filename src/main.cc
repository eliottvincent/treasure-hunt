#include "game.hh"
#include "menu.hh"

int main(int argc, char *argv[])
{
  Game &game = Game::getInstance();
  game.init();

  std::cout << "main::&game                         " << &game << "\n";
  std::cout << "main::game-renderer                 " << game.renderer << "\n";
  std::cout << "main::Game::getInstance()           " << &Game::getInstance() << "\n";
  std::cout << "main::Game::getInstance()->renderer " << Game::getInstance().renderer << "\n";

  game.changeState(Menu::instance());
  printf("Before while...\n");

  SDL_Event event;

  while (game.running())
  {
    while(SDL_PollEvent(&event))
    {
        if(event.type == SDL_QUIT)
        {
          game.cleanup();
        }
    }

    SDL_RenderClear(game.renderer);
    SDL_SetRenderDrawColor(game.renderer, 150, 0, 0, 255);
    SDL_RenderPresent(game.renderer);
  }

  // while (game.running())
  // {
  //   printf("Loop...\n");
  //
  //   game.handleEvents();
  //   game.update();
  //   game.draw();
  // }

  game.cleanup();

  return 0;
}
