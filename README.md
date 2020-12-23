clang -std=c++11 -pedantic src/main.cc -lSDL2 -lSDL2_ttf -lSDL2_image

gcc src/main.cc -o play -I include -L lib -l stdc++ -l SDL2 -l SDL2_ttf -l SDL2_image
