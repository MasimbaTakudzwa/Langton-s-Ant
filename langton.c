#include <stdlib.h>
#include "langton.h"
#include <locale.h>

// Set the ants direction so that it turns left
void turn_left(struct ant *ant) {
	switch (ant->direction)
	{
	case LEFT:
		ant->direction = DOWN;
		break;
	case RIGHT:
		ant->direction = UP;
		break;
	case UP:
		ant->direction = LEFT;
		break;
	case DOWN:
		ant->direction = RIGHT;
		break;
	}
}

// Set the ants direction so that it turns right
void turn_right(struct ant *ant) {
	
	switch (ant->direction)
	{
	case LEFT:
		ant->direction = UP;
		break;
	case RIGHT:
		ant->direction = DOWN;
		break;
	case UP:
		ant->direction = RIGHT;
		break;
	case DOWN:
		ant->direction = LEFT;
		break;
	}
}

// Actually move the ant forward based on it's current direction
// Should only be called after turn_left or turn_right
void move_forward(struct ant *ant) {

	switch (ant->direction)
	{
	case LEFT:
		ant->x -= 1;
		break;
	case RIGHT:
		ant->x += 1;
		break;
	case UP:
		ant->y += 1;
		break;
	case DOWN:
		ant->y -= 1;
		break;
	}
}

// Do not modify
const char* direction_to_s(enum direction d) {
   return UP   == d ? "^" :
          DOWN == d ? "v" :
          LEFT == d ? "<" :
          /* else */  ">" ;
}

// Call turn_left, or turn_right depending on the color of the current square,
// or in other words: apply the rule:
// * When at a white square, turn 90° clockwise, flip the color of the square to black and then move forward one unit.
// * When at a black square, turn 90° counter-clockwise, flip the color of the square to white and then move forward one unit.
void apply_rule(enum colour *colour, struct ant *ant) {
	if (*colour == 0) {
		turn_right(ant);
		*colour = 1;
		
	}
	else if (*colour == 1) {
		turn_left(ant);
		*colour = 0;
		}
}


