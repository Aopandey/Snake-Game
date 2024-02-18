#include <iostream>
#include <conio.h>
#include <ctime>
#include "Snake.h"
#include "Food.h"
#define HEIGHT 50	// height of the board
#define WIDTH 50	// width of the board
 
using namespace std;

Snake snake({ WIDTH / 2, HEIGHT / 2 }, 1);	// to set positon of the snake
Food food;
int score;	// initialize score 

void board() {
	COORD snake_pos = snake.get_pos();	// to get positon of snake head
	COORD food_pos = food.get_pos();
	vector<COORD> snake_body = snake.get_body();	// to get position of snake body
	cout << "SCORE: " << score << "\n\n";
	for(int a = 0; a < HEIGHT; a++) {	// for number of rows of the board 
		cout << "		%";	// the wall of the board
		for (int b = 0; b < WIDTH - 2; b++) {	// for width 
			if (a == 0 || a == HEIGHT - 1) cout << '%';
			else if (a == snake_pos.Y && b+1 == snake_pos.X) cout << 'o';	// to print the food
			else if (a == food_pos.Y && b+1 == food_pos.X) cout << '*'; 
			else {
				bool isbodypart = false;
				for (int k = 0; k < snake_body.size()-1; k++) {
					if (a == snake_body[k].Y && b + 1 == snake_body[k].X) {
						cout << 'o';
						isbodypart = true;
						break;
					}
				}
				if (!isbodypart) cout << ' ';
			}
		}	
		cout << "%\n";	// the wall of the board
}
		
}

int main() {
	score = 0;	// to set score to 0
	srand(time(NULL));
	food.gen_food();
	bool game_over = false;	// to make sure game is not over at the very start
	while (!game_over) {
		board();
		if (_kbhit()) {
			switch (_getch()) {	// registers wsad keys to move the snake
			case 'w': snake.diff_direction('u'); break;
			case 's': snake.diff_direction('d'); break;
			case 'a': snake.diff_direction('l'); break;
			case 'd': snake.diff_direction('r'); break;
			}
		}
		
		if (snake.ate(food.get_pos())) {
			food.gen_food();
			snake.grow();
			score++;	// increment score
		}
		if (snake.collided()) game_over = true;
		snake.move_snake();
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, 0 });	// to overwrite the board and remove the flickering of the screen
	}
	
}