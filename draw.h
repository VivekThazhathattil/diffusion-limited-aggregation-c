#ifndef DRAW_H
#define DRAW_H

#include "colors.h"
#include "utils.h"
#include "state.h"

typedef struct WINSIZE_S{
    int rows, cols;
} winsize_t;

winsize_t get_win_size(void);
void draw_frozen_particle(char*, state_t*);

#endif /* DRAW_H */
