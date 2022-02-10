#include <ncurses.h>
#include <locale.h>
#include <stdlib.h>
#include "visualiser.h"

#define cell_at(y,x) cells[(y)*max_x + (x)] 
#define cell_under_ant cell_at(ant->y, ant->x)
cell *cells;

void start_visualisation(struct ant* ant) {
  setlocale(LC_ALL, "");

   initscr();
   curs_set(FALSE);
   max_x = getmaxx(stdscr);
   max_y = getmaxy(stdscr);
   
   cells = calloc(max_y*max_x, sizeof(cell));
   ant->x = max_x/2;
   ant->y = max_y/2;
   ant->direction = RIGHT;
}

void visualise_and_advance(struct ant* ant) {
      /* Draw cells and ant */
      for (int y=0; y<max_y; y++)
      {
         for (int x=0; x<max_x; x++)
         {
            mvprintw(y,x,
               ant_is_at(y,x)
                 ? direction_to_s(ant->direction)
                 : cell_at(y,x)
                    ? "█"
                    : " "
            );
         }
      }
      refresh();
      
      /* Advance to next step */
      apply_rule(&cell_under_ant, ant);

      // Since I could not get the cell_at() boundary behaviour working I tried to implement it another way using a greedy algorithm
      //Assuming the boundary values are 0 and max values of x and y respectively. If the ant moves past those values it should appear on the other side
      switch(ant->direction){
         case LEFT:
            if (ant->x <= 0){
               ant->x = max_x;
            } 
            break;
         case RIGHT:
            if (ant->x >= max_x){
               ant->x = 0;
            }
            break;
         case DOWN:
            if (ant->y <=0){
               ant->y = max_y;
            };
            break;
         case UP:
            if(ant->y >= max_y){
               ant->y = 0;
            };
            break;
      }
      move_forward(ant);
}

// Check if the user has input "q" to quit
bool not_quit() {
   return 'q' != getch();
}

void end_visualisation() {
   free(cells);
   endwin();
}

