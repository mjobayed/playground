#include <SDL2/SDL.h>
#include <SDL2/SDL_video.h>
#include <cstdio>

int main() {
  SDL_Init(SDL_INIT_VIDEO);

  SDL_Window *window =
      SDL_CreateWindow("Hello, World!", SDL_WINDOWPOS_CENTERED,
                       SDL_WINDOWPOS_CENTERED, 800, 800, SDL_WINDOW_SHOWN);
  SDL_Renderer *renderer =
      SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

  printf("Running\n");

  // Can use hex code with 0x prefix.
  SDL_SetRenderDrawColor(renderer, 0x1e, 0x1e, 0x2e, 255);

  // need to clear the render for the color to show up.
  SDL_RenderClear(renderer);

  SDL_RenderPresent(renderer);
  SDL_Delay(2000);

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}
