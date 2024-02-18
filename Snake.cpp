#include "Snake.h"

Snake::Snake(COORD position, long int speed) {
    this->position = position;
    this->speed = speed;
    length = 1;
    direction = 'n';
    body.push_back(position);
}

void Snake::move_snake() {
    switch (direction) {
    case 'u': position.Y -= speed; break;
    case 'd': position.Y += speed; break;
    case 'l': position.X -= speed; break;
    case 'r': position.X += speed; break;
    }
    if (position.X > WIDTH - 2) position.X = 0; // for infinite horizontal walls 
    if (position.X < 1) position.X = WIDTH - 2;
    body.push_back(position);
    if (body.size() > length) body.erase(body.begin());    // to erase and then print the body of the snake  
}

COORD Snake::get_pos() { return position; }

void Snake::diff_direction(char dir) { direction = dir; }

bool Snake::ate(COORD food_pos) { // retuurns true if coordinates matched
    if (food_pos.X == position.X && food_pos.Y == position.Y) return true;
    else return false; 
}

void Snake::grow() { length++; }
vector<COORD> Snake::get_body() { return body;}
 
bool Snake::collided() {    // to check if snake has collided with wall or not
    if (position.X < 1 || position.X > WIDTH-2 || position.Y < 1 || position.Y > HEIGHT-2) return true;
    return false;
}


    