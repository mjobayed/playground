#include <SDL2/SDL.h>
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_video.h>
#include <cstdio>
#include <iostream>
#include <string>

int main() {
  SDL_Init(SDL_INIT_VIDEO);
  TTF_Init();

  SDL_Window *window =
      SDL_CreateWindow("Hello World", SDL_WINDOWPOS_CENTERED,
                       SDL_WINDOWPOS_CENTERED, 800, 800, SDL_WINDOW_SHOWN);
  SDL_Renderer *renderer =
      SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
  TTF_Font *font = TTF_OpenFont("./JetBrainsMono.ttf", 32);
  SDL_Color textColor = {255, 255, 255, 255};

  Uint64 lastTick = SDL_GetTicks();
  int frames = 0;
  int totalFrames = frames;

  bool running = true;
  while (running) {
    Uint64 curTick = SDL_GetTicks();

    SDL_Event e;
    while (SDL_PollEvent(&e)) {
      if (e.type == SDL_QUIT) {
        running = false;
      }
      if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_q) {
        running = false;
      }
    }

    // This is very important. TTF_RenderText_Solid expects a char type
    // so we convert to string then we will convert to char
    std::string frames_str = std::to_string(totalFrames);

    // Here we convert frames_str to char type with .c_str()
    SDL_Surface *textSurface =
        TTF_RenderText_Solid(font, frames_str.c_str(), textColor);
    SDL_Texture *textTexture =
        SDL_CreateTextureFromSurface(renderer, textSurface);

    int textWidth = textSurface->w;
    int textHeight = textSurface->h;
    SDL_FreeSurface(textSurface);
    SDL_Rect textRect = {0, 0, textWidth, textHeight};

    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, textTexture, NULL, &textRect);
    SDL_RenderPresent(renderer);
    frames++;

    if (curTick - lastTick >= 1000) {
      lastTick = curTick;
      totalFrames = frames;
      frames = 0;
    }
    SDL_DestroyTexture(textTexture);
  }

  TTF_CloseFont(font);
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  TTF_Quit();
  SDL_Quit();
}
