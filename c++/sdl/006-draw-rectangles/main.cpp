#include <SDL2/SDL.h>

int main() {
  SDL_Init(SDL_INIT_VIDEO);
  SDL_Window *window =
      SDL_CreateWindow("Draw Rectangles", SDL_WINDOWPOS_CENTERED,
                       SDL_WINDOWPOS_CENTERED, 800, 800, SDL_WINDOW_SHOWN);
  SDL_Renderer *renderer =
      SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);

  bool running = true;
  while (running) {
    SDL_Event e;
    while (SDL_PollEvent(&e)) {
      if (e.type == SDL_QUIT) {
        running = false;
      }

      if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_q) {
        running = false;
      }
    }

    SDL_SetRenderDrawColor(renderer, 0x1e, 0x1e, 0x2e, 255);
    SDL_RenderClear(renderer);

    SDL_Rect rect1;
    rect1.x = 50;
    rect1.y = 50;
    rect1.w = 50;
    rect1.h = 50;
    SDL_SetRenderDrawColor(renderer, 0xf3, 0x8b, 0xa8, 255);
    SDL_RenderFillRect(renderer, &rect1);

    SDL_Rect rect2;
    rect2.x = 150;
    rect2.y = 50;
    rect2.w = 50;
    rect2.h = 50;
    SDL_SetRenderDrawColor(renderer, 0xeb, 0xa0, 0xac, 255);
    SDL_RenderFillRect(renderer, &rect2);

    SDL_Rect rect3;
    rect3.x = 250;
    rect3.y = 50;
    rect3.w = 50;
    rect3.h = 50;
    SDL_SetRenderDrawColor(renderer, 0xfa, 0xb3, 0x87, 255);
    SDL_RenderFillRect(renderer, &rect3);

    SDL_RenderPresent(renderer);
  }

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}
