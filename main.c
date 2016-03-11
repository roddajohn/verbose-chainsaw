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

  add_edge(edges, 0, 0, 0, 100, 0, 0);
  add_edge(edges, 100, 0, 0, 100, 100, 0);
  add_edge(edges, 100, 100, 0, 0, 100, 0);
  add_edge(edges, 0, 100, 0, 0, 0, 0);

  draw_lines(edges, s, c);

  transform = new_matrix(4, 4);

  struct matrix *new_transform;

  int offset = 50;

  for (offset = 50; offset <= 500; offset += 10) {
    
    int i = 0;
    
    for (i = 0; i < 36; i++) {
      
      new_transform = make_rotZ(10);
      
      matrix_mult(new_transform, edges);
      
      draw_lines(edges, s, c);  
    }

    transform = make_translate(10, 10, 0);
    matrix_mult(transform, edges);
    c.red -= 5;
    c.blue += 7;
    c.green += 7;
    draw_lines(edges, s, c);
  }


  free_matrix( transform );
  free_matrix( edges );
  free_matrix(new_transform);

  save_extension(s, "matrix.png");
}  
