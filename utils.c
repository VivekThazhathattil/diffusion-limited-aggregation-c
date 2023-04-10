#include <stdlib.h>
#include "utils.h"

int random_num_within_range(int lo, int hi){
  if(lo == hi) 
    return lo;
  else if(hi < lo)
    return rand()%(lo - hi) + hi;
  return rand()%(hi - lo) + lo;
}

char* get_specific_color(int num){
  char* colors[NUM_COLORS] = {RED, GRN, YEL, BLU, MAG, CYN, WHT};
  return colors[num%7];
}

char* get_random_color(void){
  char* colors[NUM_COLORS] = {RED, GRN, YEL, BLU, MAG, CYN, WHT};
  return colors[rand()%NUM_COLORS];
}
