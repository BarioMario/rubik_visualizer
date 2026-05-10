#include "../includes/graphics.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_video.h>

void render_triangle(SDL_Renderer *renderer, Triangle tri) {
  Point2 p1 = tri.left;
  Point2 p2 = tri.mid; 
  Point2 p3 = tri.right;
  float slope = 0;
  float slope2 = 0;
  slope = ((float)(p2.y - p1.y))/((float)(p2.x-p1.x));
  slope2 = ((float)(p3.y - p1.y))/((float)(p3.x-p1.x));
  for (int distancia = 0; distancia < p2.x-p1.x; distancia++) {
    SDL_RenderDrawLine(renderer, 
      p1.x+distancia, p1.y+(int)(slope*(float)distancia),
      p1.x+distancia, p1.y+(int)(slope2*(float)distancia));
  }
  int coordy = slope2*((float) p2.x-p1.x) + p1.y;
  slope = ((float)(p3.y - p2.y))/((float)(p3.x-p2.x));
  slope2 = ((float)(p3.y - p1.y))/((float)(p3.x-p1.x));
  for (int distancia = 0; distancia < p3.x-p2.x; distancia++) {
    SDL_RenderDrawLine(renderer, 
      p2.x+distancia, coordy+(int)(slope2*(float)distancia),
      p2.x+distancia, p2.y + (int)(slope*(float)distancia));
  }

  SDL_RenderDrawLine(renderer, p1.x, p1.y, p2.x, p2.y);
  SDL_RenderDrawLine(renderer, p3.x, p3.y, p2.x, p2.y);
  SDL_RenderDrawLine(renderer, p1.x, p1.y, p3.x, p3.y);
}

Triangle make_triangle(Point2 p1, Point2 p2, Point2 p3){
  Triangle tri;
  tri.left = p1;
  tri.mid = p2;
  tri.right = p3;

  order_two(&tri.left, &tri.mid);
  order_two(&tri.mid, &tri.right);
  order_two(&tri.left, &tri.mid);

  return tri;
}
void order_two(Point2 *p1, Point2 *p2) {
  Point2 temp;
  if (p1->x<p2->x) {
  } else {
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
  }
}
