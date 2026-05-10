#ifndef GRAPHICS
#define GRAPHICS

#define WIDTH 1200
#define HEIGHT 800

#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_video.h>

typedef struct Camera {
  int x;
  int y;
  int z;
} Camera;

typedef struct Point3 {
  int x;
  int y;
  int z;
} Point3;

typedef struct Point2 {
  int x;
  int y;
} Point2;

typedef struct Triangle {
  Point2 left;
  Point2 mid;
  Point2 right;
} Triangle;

void render_triangle(SDL_Renderer *renderer, Triangle tri);

Triangle make_triangle(Point2 p1, Point2 p2, Point2 p3);

void order_two(Point2 *p1, Point2 *p2);
#endif // !GRAPHICS
