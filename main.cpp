#include "snake.h"
using namespace std;

double timeInterval = 0.05;

void gameUpdate(void* game)
{	//Repeated callback, updates the game state (moves snake, checks for collisions)
	//at a regular interval
	Snake* snake = static_cast<Snake*>(game);
	if(!snake->checkDead())
	{
		snake->move();
		snake->checkCollision();
		Fl::repeat_timeout(timeInterval, gameUpdate, snake);
	}
	else cout << "Snake: game over! (size = " << snake->getSize() << ")" << endl;
}

int main(int argc, char* argv[])
{
	int numSegments = 1;
	if (argc > 1)
	{
		timeInterval = stod(argv[1]);
		numSegments = stoi(argv[2]);
	}
	
	Snake* game = new Snake(numSegments, 300, 300);
	Fl::add_timeout(timeInterval, gameUpdate, game);
	return Fl::run();
}
