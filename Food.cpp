#include "Food.h"

void Food::gen_food()
{
    position.X = (rand() % WIDTH - 3) + 1;   // random number generation
    position.Y = (rand() % HEIGHT - 3) + 1;
}

COORD Food::get_pos() { return position; }   // to return the positon of the current food