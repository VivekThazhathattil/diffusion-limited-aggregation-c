#include "particle.h"

void move_particle(particle_t* p, state_t* s){
  p->pos.x += p->vel.x;
  p->pos.x %= s->cols;
  if(p->pos.x < 0)
    p->pos.x = s->cols + p->pos.x;
  p->pos.y += p->vel.y;
}

void freeze_particle(particle_t* p){
  p->vel.x = 0;
  p->vel.y = 0;
}

particle_t* init_particle(winsize_t win, int wind){
  particle_t* p = (particle_t*) malloc(sizeof(particle_t));
  adjust_rain_velocity(p, NULL, wind);
  /* initially our particle is at the top of the screen */
  p->pos.y = 1; 
  p->pos.x = random_num_within_range(1, win.cols);
  return p;
}

int within_bounds(int x, int y, state_t* s){
  return x >= 0 && y >= 0 && x < s->cols && y < s->rows;
}

int is_particle_at_freeze_point(particle_t* p, state_t* s){
  int flag = 0;
  int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
  for(int i = 0; i < 4; ++i){
    int new_x = p->pos.x + dx[i], new_y = p->pos.y + dy[i];
    if(within_bounds(new_x - 1, new_y - 1, s)){
      if(s->mat[new_y-1][new_x-1]){
        flag = s->mat[new_y-1][new_x-1];
        break;
      }
    }
  }
  if(flag)
    return flag + 1;
  return flag;
}

int is_particle_at_floor(particle_t* p, state_t* s){
  return p->pos.y == s->rows - 1;
}

void kill_particle(particle_t* p){
  free(p);
}

void adjust_rain_velocity(particle_t* p, state_t* s, int wind){
  p->vel.y = 1;
  switch(wind){
    case NO_WIND:
      p->vel.x = NO_WIND_STRENGTH;
      break;
    case BREEZE:
      p->vel.x = random_num(BREEZE_STRENGTH) - BREEZE_STRENGTH/2;
      break;
    case STRONG_WIND:
      p->vel.x = random_num(STRONG_WIND_STRENGTH) - STRONG_WIND_STRENGTH/2;
      break;
    default:
      p->vel.x = NO_WIND_STRENGTH;
  }
  /* Aperiodic boundary conditions */
  /*
  if(s == NULL){
    p->vel.x = 5;
  }
  else{
    if(p->pos.x == 0)
      p->vel.x = random_num(2);
    else if(p->pos.x == s->cols-1)
      p->vel.x = -random_num(2);
    else
      p->vel.x = random_num(3) - 1;
  }
  */
}
