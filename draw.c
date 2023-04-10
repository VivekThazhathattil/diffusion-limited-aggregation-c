#include <stdio.h>
#include <sys/ioctl.h>
#include <stdlib.h>
#include <unistd.h>

#include "draw.h"

#define gotoxy(x,y) printf("\033[%d;%dH", (y), (x))

winsize_t get_win_size(void){
  winsize_t ws;
  struct winsize win;     
  ioctl(0, TIOCGWINSZ, &win);
  ws.rows = win.ws_row;
  ws.cols = win.ws_col;
  return ws;
}

void draw_frozen_particle(char* c, state_t* s){
  for(int i = 0; i < s->rows; ++i){
    for(int j = 0; j < s->cols; ++j){
      if(s->mat[i][j]){
        char* color = get_specific_color(s->mat[i][j] - 1);
        gotoxy(j, i);
        printf("%s%s", color, c);
      }
    }
  }
}
