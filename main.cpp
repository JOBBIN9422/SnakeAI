#include "snake.h"
#include <sstream>
#include <FL/Fl_Button.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Int_Input.H>
using namespace std;

double timeInterval = 0.05;

//GLOBALS
Fl_Double_Window* menuWindow;

Fl_Input* timeStepInput;
Fl_Input* algorithmInput;

Fl_Int_Input* screenWInput;
Fl_Int_Input* screenHInput;

Fl_Choice* algorithmChoice;

//FORWARD DECLARES
void startButtonCallback(Fl_Widget* w, void* v);

int main(int argc, char* argv[])
{
	int numSegments = 1;
	if (argc > 1)
	{
		timeInterval = stod(argv[1]);
		numSegments = stoi(argv[2]);
	}

    Snake* game;

    menuWindow = new Fl_Double_Window(320, 140, "Menu");
    Fl_Button* startButton = new Fl_Button(140, 120, 40, 20, "Start");
    startButton->callback(startButtonCallback, game);
    
    timeStepInput = new Fl_Input(180, 20, 120, 20, "Time Step (Seconds)");
    
    algorithmChoice = new Fl_Choice(180, 80, 120, 20, "Search Algorithm");
    algorithmChoice->add("AStar");
    algorithmChoice->add("GreedyBFS");
    algorithmChoice->add("BFS");
    algorithmChoice->value(0);
    
    screenWInput = new Fl_Int_Input(180, 40, 120, 20, "Screen Width (px)");
    screenHInput = new Fl_Int_Input(180, 60, 120, 20, "Screen Height (px)");
    
    menuWindow->show();
    
	return Fl::run();
}

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
	else
    {
        cout << "Snake: game over! (size = " << snake->getSize() << ")" << endl;
        snake->getPathfinder()->printStats();
    }
    
}

void startButtonCallback(Fl_Widget* w, void* v)
{
    Snake* game = (Snake*)v;
    menuWindow->hide();

    //default values
    int screenW = 800;
    int screenH = 600;
    string algorithm = "AStar";
    
    if (strlen(timeStepInput->value()) != 0)
        timeInterval = stod(timeStepInput->value());

    if (strlen(screenWInput->value()) != 0)
        screenW = stoi(screenWInput->value());

    if (strlen(screenHInput->value()) != 0)
        screenH = stoi(screenHInput->value());

    if (strlen(algorithmChoice->text()) != 0)
        algorithm = algorithmChoice->text();
    
    game = new Snake(1, 0, 0, screenW, screenH, algorithm);
    Fl::add_timeout(timeInterval, gameUpdate, game);
}

