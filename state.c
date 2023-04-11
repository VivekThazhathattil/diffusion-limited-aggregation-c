#include "state.h"

state_t* init_state(int rows, int cols){
  state_t* state = (state_t*) malloc(sizeof(state_t));
  state->rows = rows;
  state->cols = cols;
  state->mat = (int**) malloc(state->rows * sizeof(int*));
  for(int i = 0; i < state->rows; ++i)
    state->mat[i] = (int*) calloc(state->cols, sizeof(int));
  return state;
}

void update_state(int row_index, int col_index, state_t* s, int chosen_color){
  if(chosen_color == 0 && s->mat[row_index][col_index] == NUM_COLORS)
    s->mat[row_index][col_index] = 0;
  else
    s->mat[row_index][col_index] = chosen_color;
}

void delete_state(state_t* s){
  if(s == NULL)
    return;
  for(int i = 0; i < s->rows; ++i){
    if(s->mat[i] != NULL)
      free(s->mat[i]);
  }
  if(s->mat != NULL) 
    free(s->mat);
  free(s);
}
