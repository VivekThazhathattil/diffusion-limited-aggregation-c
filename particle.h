#ifndef PARTICLE_H
#define PARTICLE_H

#include <stdlib.h>

#include "draw.h"
#include "state.h"
#include "utils.h"

#define NO_WIND 0
#define BREEZE 1
#define STRONG_WIND 2

#define NO_WIND_STRENGTH 0
#define BREEZE_STRENGTH 3
#define STRONG_WIND_STRENGTH 20

#define NUM_WINDS 3

typedef struct PARTICLE_S{
  position_t pos;   
  velocity_t vel;
} particle_t;

void move_particle(particle_t*, state_t*);
void freeze_particle(particle_t*);
particle_t* init_particle(winsize_t, int, int);
int is_particle_at_freeze_point(particle_t*, state_t*);
int is_particle_at_floor(particle_t*, state_t*);
void kill_particle(particle_t*);
void adjust_rain_velocity(particle_t*, state_t*, int, int);
int within_bounds(int, int, state_t*);

#endif /* PARTICLE_H */
