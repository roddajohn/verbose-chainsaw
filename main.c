#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"

int main() {

  screen s;
  struct matrix *edges;
  struct matrix *transform;

  edges = new_matrix(4, 4);
  transform = new_matrix(4, 4);

  edges->m[0][0] = 4;
  edges->m[0][1] = 4;
  edges->m[0][3] = 1;

  edges->m[1][0] = 8;
  edges->m[1][1] = 4;
  edges->m[1][3] = 1;

  edges->m[2][0] = 8;
  edges->m[2][1] = 0;
  edges->m[2][3] = 1;

  edges->m[3][0] = 4;
  edges->m[3][1] = 0;
  edges->m[3][3] = 1;

  //transform = make_translate(4, 4, 0);
  transform = make_rotZ(90);



  print_matrix(transform);
  printf("\n\n");
  print_matrix(edges);

  printf("\n\n");
  matrix_mult(transform, edges);
  print_matrix(edges);
  
  free_matrix( transform );
  free_matrix( edges );
}  