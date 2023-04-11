/* Diffusion Limited Aggregation */

#include <unistd.h>
#include <stdio.h>
#include <time.h>

#include "colors.h"
#include "utils.h"
#include "state.h"
#include "particle.h"
#include "draw.h"

int main(int argc, char **argv){
  srand(time(NULL));
  const int num_particles = 5000;
  char* blk_sym = "■";
  int wind = get_rvalue("-w", argc, argv, NUM_WINDS);
  int random_wind = get_rvalue("-r", argc, argv, 2);
  int frame_update_delay = 16;
  winsize_t win = get_win_size();
  state_t* state = init_state(win.rows, win.cols);

  system("clear");

  for(int i = 0; i < num_particles; ++i){
    particle_t* particle = init_particle(win, wind, random_wind);
    /*
    position_t curr_pos = (position_t){.x = -1, .y = -1};
    position_t old_pos = (position_t){.x = -1, .y = -1};
    */
    while(1){
      //usleep(frame_update_delay);
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
        /*
        curr_pos = (position_t){.x = -1, .y = -1};
        old_pos = (position_t){.x = -1, .y = -1};
        */
        break;
      }
      else{
        /*
        if(curr_pos.x > 0)
          update_state(curr_pos.y - 1, curr_pos.x - 1, state, NUM_COLORS);
        if(old_pos.x > 0)
          update_state(old_pos.y - 1, old_pos.x - 1, state, 0);
        draw_frozen_particle(blk_sym, state);
        */
        adjust_rain_velocity(particle, state, wind, random_wind);
        move_particle(particle, state);
        /*
        old_pos = curr_pos;
        curr_pos = particle->pos;
        */
      }
    }
  }
  printf("\n");
  delete_state(state);
  return 0;
}
