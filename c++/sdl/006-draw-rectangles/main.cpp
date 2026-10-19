#include <SDL2/SDL.h>

void renderRectangle(SDL_Renderer *Renderer, int x, int y, int w, int h,
                     Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
  SDL_Rect rect;
  rect.x = x;
  rect.y = y;
  rect.w = w;
  rect.h = h;
  SDL_SetRenderDrawColor(Renderer, r, g, b, a);
  SDL_RenderFillRect(Renderer, &rect);
}

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

    renderRectangle(renderer, 50, 50, 50, 50, 0xf3, 0x8b, 0xa8, 255);
    renderRectangle(renderer, 150, 50, 50, 50, 0xa6, 0xe3, 0xa1, 255);
    renderRectangle(renderer, 250, 50, 50, 50, 0x94, 0xe2, 0xd5, 255);
    renderRectangle(renderer, 350, 50, 50, 50, 0x89, 0xb4, 0xfa, 255);

    SDL_RenderPresent(renderer);
  }

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}
