#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"

int main() {

  screen s;
  color c;
  c.red = MAX_COLOR;
  c.green = 0;
  c.blue = 0;

  clear_screen(s);
  
  struct matrix *edges;
  struct matrix *transform;

  edges = new_matrix(4, 4);

  add_edge(edges, 100, 100, 0, 300, 100, 0);
  add_edge(edges, 300, 100, 0, 300, 300, 0);
  add_edge(edges, 300, 300, 0, 100, 300, 0);
  add_edge(edges, 100, 300, 0, 100, 100, 0);

  draw_lines(edges, s, c);

  //  edges = new_matrix(4, 4);
  transform = new_matrix(4, 4);

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
