#ifndef FOOD_H
#define FOOD_H

#include <Windows.h>
#include <cstdlib>
#define HEIGHT 50	
#define WIDTH 50
class Food
{
public:
	void gen_food();
	COORD get_pos(); 
private:
	COORD position;
};

#endif 

