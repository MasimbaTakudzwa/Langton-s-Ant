#include <stdlib.h>
#include "langton.h"
#include <locale.h>

// Using switch statements:
//90 degree turns left turns the ant from Up -> Left -> Down -> Right -> Up
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

//Using switch statements:
//90 degree turns right turns the ant from Up -> Right -> Down -> Left -> Up
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

	//Using switch statements:
	//If the ant is facing Left we need to decrement by 1 and if it is facing right we need to increment by 1
	//If the ant is facing Down we need to decrement by 1 and if it is facing Up we need to increment by 1
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
	
	// If the square is white turn right and change the square color to black
	if (*colour == 0) {
		turn_right(ant);
		*colour = 1;
		
	}// If the square is black turn left and change the square to white and turn left
	else if (*colour == 1) {
		turn_left(ant);
		*colour = 0;
		}
}


