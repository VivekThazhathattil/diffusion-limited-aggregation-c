/* Diffusion Limited Aggregation */

#include <unistd.h>
#include <stdio.h>
#include <time.h>

#include "colors.h"
#include "utils.h"
#include "state.h"
#include "particle.h"
#include "draw.h"

int main(void){
  srand(time(NULL));
  const int num_particles = 10000;
  char* blk_sym = "■";
  winsize_t win = get_win_size();
  state_t* state = init_state(win.rows, win.cols);

  system("clear");

  for(int i = 0; i < num_particles; ++i){
    particle_t* particle = init_particle(win);
    while(1){
      if(is_particle_at_freeze_point(particle, state) || 
         is_particle_at_floor(particle, state)){
        int chosen_color = 0;
        if(is_particle_at_floor(particle, state))
          chosen_color = random_num(NUM_COLORS);
        else
          chosen_color = is_particle_at_freeze_point(particle, state) - 1;
        freeze_particle(particle);
        update_state(particle->pos.y - 1, 
          particle->pos.x - 1, state, chosen_color);
        draw_frozen_particle(blk_sym, state);
        kill_particle(particle);
        break;
      }
      else{
        adjust_rain_velocity(particle, state);
        move_particle(particle);
      }
    }
  }
  printf("\n");
  delete_state(state);
  return 0;
}
