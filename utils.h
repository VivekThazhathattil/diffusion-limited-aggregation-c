#ifndef UTILS_H
#define UTILS_H

#include "colors.h"

typedef struct POSITION_S{
  int x, y;
} position_t;

typedef struct VELOCITY_S{
  int x, y;
} velocity_t;

int random_num_within_range(int, int);
char* get_specific_color(int);
char* get_random_color(void);
int random_num(int);

#endif /* UTILS_H */
