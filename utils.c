#include <stdlib.h>
#include "utils.h"

int random_num_within_range(int lo, int hi){
  if(lo == hi) 
    return lo;
  else if(hi < lo)
    return rand()%(lo - hi) + hi;
  return rand()%(hi - lo) + lo;
}

int random_num(int hi){
  if(hi == 0)
    return 0;
  return rand()%hi;
}

char* get_specific_color(int num){
  char* colors[NUM_COLORS] = {RED, GRN, YEL, BLU, MAG, CYN, WHT};
  return colors[num%7];
}

char* get_random_color(void){
  char* colors[NUM_COLORS] = {RED, GRN, YEL, BLU, MAG, CYN, WHT};
  return colors[rand()%NUM_COLORS];
}

int get_rvalue(char* lvalue, int num_args, char** arg_vars, int num_values){
  int rvalue = 0;
  int lvalue_length = 0;
  while(lvalue[lvalue_length] != '\0')
    ++lvalue_length;
  for(int i = 0; i < num_args; ++i){
    int j = 0;
    while(arg_vars[i][j] != '\0' && lvalue[j] != '\0'){
      if(arg_vars[i][j] != lvalue[j])
        break;
      ++j;
    }
    if(j == lvalue_length && i < num_args - 1)
      rvalue = arg_vars[i+1][0] - '0';
  }
  return rvalue % num_values;
}
