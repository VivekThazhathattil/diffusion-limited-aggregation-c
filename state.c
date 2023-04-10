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
  s->mat[row_index][col_index] = chosen_color;
}

void delete_state(state_t* s){
  for(int i = 0; i < s->rows; ++i)
    free(s->mat[i]);
  free(s->mat);
  free(s);
}
