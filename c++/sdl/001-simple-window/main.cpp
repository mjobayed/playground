#include <SDL2/SDL.h>
#include <SDL2/SDL_video.h>
#include <cstdio>

int main() {
  SDL_Init(SDL_INIT_VIDEO);

  SDL_Window *window =
      SDL_CreateWindow("Hello, World!", SDL_WINDOWPOS_CENTERED,
                       SDL_WINDOWPOS_CENTERED, 800, 800, SDL_WINDOW_SHOWN);
  printf("Running\n");

  SDL_DestroyWindow(window);
  SDL_Quit();
}
