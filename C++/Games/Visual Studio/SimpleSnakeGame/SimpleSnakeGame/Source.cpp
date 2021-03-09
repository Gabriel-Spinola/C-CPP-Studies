#include <iostream>
#include <Windows.h>
#include <conio.h> // input lib

using namespace std;

// 20x20 blocks map
const int WIDTH = 25;
const int HEIGHT = 25;

bool gameOver;	

// tail max width and height		
int tailX[100], tailY[100];
int nTail;

int x, y, fruitX, fruitY;
int score;
 
enum eDirection {
	STOP = 0,
	LEFT,
	RIGHT,
	UP,
	DOWN
};

eDirection dir;

void Setup() {
	gameOver = false;

	dir = STOP;

	// middle of the map
	x = WIDTH / 2;
	y = HEIGHT / 2;

	// Spawns in a random position
	fruitX = rand() % WIDTH;
	fruitY = rand() % HEIGHT;

	score = 0;
}

/* Sample Map 10x10
*	##########
*	#        #  
*	#        #
*	#        #
*	#        #
*	#        #
*	#        #
*	#        #
*	#        #
*	##########
*/

void Draw() {
// Clear the screen

/// <summary>
///  Compatibility test.
///  Maybe this cause some bug.
/// </summary>
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
	#ifdef _WIN64
		system("cls");
	#endif

	system("cls");
#elif __linux__
	system("clear");
#endif

	// system("cls");

	// draw first row. (+2 for missing characters).
	for (int i = 0; i < WIDTH + 2; i++)
		cout << '#';
	cout << endl;

	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			// draw left borders.
			if (j == 0) 
				cout << '#';

			if (i == y && j == x) {
				// draw snakes
				cout << 'O';
			}
			else if (i == fruitY && j == fruitX) {
				// draw Fruits
				cout << "F";
			}
			else {
				bool print = false;

				// draw tail
				for(int k = 0; k < nTail; k++) {
					if(tailX[k] == j && tailY[k] == i) {
						cout << 'o';

						print = true;
					}
				}

				// print blank spaces on empty spaces
				if(!print) 
					cout << ' ';
			}

			// draw right borders.
			if (j == WIDTH - 1)
				cout << '#';
		}

		cout << endl;
	}
	
	// draw final row. (+2 for missing characters).
	for (int i = 0; i < WIDTH + 2; i++)
		cout << '#';
	cout << endl;
	
	cout << "Score: " << score << endl;
}

void Input() {
	/// <returns>if some key is pressed return 1 else return 0</returns>
	if (_kbhit()) {
		// get character
		switch (_getch()) {
			case 'a':
				dir = LEFT;
			break;

			case 'd':
				dir = RIGHT;
			break;

			case 'w':
				dir = UP;
			break;

			case 's':
				dir = DOWN;
			break;

			case 'x':
				gameOver = true;
			break;
		}
	}
}

void Logic() {
	int prevX = tailX[0];
	int prevY = tailY[0];
	int prev2X, prev2Y;

	// tail follow the head
	tailX[0] = x;
	tailY[0] = y;

	for(int i = 1; i < nTail; i++) {
		prev2X = tailX[i];
		prev2Y = tailY[i];

		tailX[i] = prevX;
		tailY[i] = prevY;

		prevX = prev2X;
		prevY = prev2Y;
	}

	switch(dir) {
		case LEFT:
			x--;
		break;

		case RIGHT:
			x++;
		break;

		case UP:
			y--;
		break;

		case DOWN:
			y++;
		break;
	}

	// Wall collision detect.
	if(x >= WIDTH) x = 0; else if(x < 0) x = WIDTH - 1;
	if(y >= HEIGHT) y = 0; else if(y < 0) y = HEIGHT - 1;

	// Tail collision detect.
	for(int i = 0; i < nTail; i++) 
		if(tailX[i] == x && tailY[i] == y)
			gameOver = true;

	// fruit collision detect.
	if(x == fruitX && y == fruitY) {
		// increase the tail
		nTail++;

		// increase the score
		score += 10;

		// Spawns in a random position.
		fruitX = rand() % WIDTH;
		fruitY = rand() % HEIGHT;
	}
} 

int main() {
	Setup();

	while(!gameOver) {
		Draw();
		Input();
		Logic();

		Sleep(10);
	}

	return 0;
}