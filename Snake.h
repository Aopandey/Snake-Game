#ifndef SNAKE_H
#define SNAKE_H
#define HEIGHT 50	
#define WIDTH 50
#include <vector>

#include <windows.h>
using namespace std;
class Snake {
public:
	Snake(COORD position, long int speed);
	void move_snake();	// to move the snake in a perticular direction 
	COORD get_pos();	// to get current position of the snake 
	void diff_direction(char dir);	// to change direction of the snake
	bool ate(COORD food_pos);	// to check if the coordinates of the snake matches with the food 
	void grow();
	bool collided();
	vector<COORD> get_body();

private:
	COORD position;	// for cords of the snake
	long int length;	// for length of the snake
	long int speed;	// for the speed of the snake
	char direction; // for directional moment of the snake
	vector<COORD> body;	// for the body of the snake
	

};

#endif