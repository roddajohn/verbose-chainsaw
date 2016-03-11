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

  transform = new_matrix(4, 4);

  int i = 0;
  for (i = 0; i < 10; i++) {
    transform = make_translate(10, 10, 0);

    matrix_mult(transform, edges);

    draw_lines(edges, s, c);

    print_matrix(edges);
    printf("\n\n");
  }

  free_matrix( transform );
  free_matrix( edges );

  save_extension(s, "matrix.png");
}  
