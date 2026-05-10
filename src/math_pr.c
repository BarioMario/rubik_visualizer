#include <stdio.h>
#include <math.h>
#include "../includes/math_pr.h"
#include "../includes/graphics.h"

Point2 calc_point(Point3 p, Camera c, int FOV) {
  /// Vamos a llamar FOV a la distancia que hay desde la camara hasta la pantalla,
  /// si el objeto se encontrase entre la camara y la pantalla el objeto se veria
  /// mas grande, si se encontrase detras de la pantalla se veria mas pequeno.
  FOV = 100; // Vamos a darle un valor de 100 inicial para hacer pruebas, puesto que la 
             // camara esta actualmente en 100, para que la pantalla este en 0
  int profundidad = p.z - c.z;
  if (profundidad == 0) {
    profundidad = 1;
    printf("Error, profundidad = 0\n");
  }
  float escalado = ((float)FOV)/((float)profundidad);
  printf("Escalado: %f\n", escalado);

  Point2 transform;
  transform.x = (int)((float)p.x * escalado);
  transform.y = (int)((float)p.y * escalado);

  printf("x: %i ; y: %i\n", transform.x, transform.y);

  return transform;
}

void fun() {
  printf("HOLA MUNDO\n");
}
