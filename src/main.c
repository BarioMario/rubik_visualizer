#include <stdio.h>
#include <time.h>
#include "math.h"
#include "../includes/graphics.h"
#include "../includes/math_pr.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_video.h>

int main() {
  printf("Funcionando\n");

  Point3 v;
  v.x = 100;
  v.y = 200;
  v.z = 200;

  Camera q;
  q.x = WIDTH/2;
  q.y = HEIGHT/2;
  q.z = 0;

  Point2 algo = calc_point(v, q, 0);

  SDL_Init(SDL_INIT_VIDEO);
  SDL_Event event;
  SDL_Window *window = SDL_CreateWindow(
    "Cubo de Rubik",
    SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, // Posicion relativa de la ventana frente a la pantalla en la que se ve
    WIDTH, HEIGHT,
    SDL_WINDOW_SHOWN
  );

  SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  
  int running = 1;

  while (running) {
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        running = 0;
      }
    }
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Color negro para limpiar la pantalla
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 230, 230, 230, 255);

    SDL_RenderPresent(renderer);
  }

  return 0;
}
