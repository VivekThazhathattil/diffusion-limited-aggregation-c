#ifndef STATE_H
#define STATE_H

#include <stdlib.h>
#include "colors.h"

typedef struct STATE_S{
  int rows, cols;
  int** mat; /* mat will store the color id (1-7)*/
} state_t;

state_t* init_state(int, int);
void update_state(int, int, state_t*, int);
void delete_state(state_t*);

#endif /* STATE_H */
