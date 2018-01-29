#pragma once 
#include "segment.h"
#include "pathfinder.h"
#include "food.h"
#include <vector>
#include <FL/Fl_Double_Window.H>
#include <queue>

class Pathfinder;

class Snake : public Fl_Double_Window
{
	friend class Pathfinder;	//give pathfinder direct access to snake data
	private:
		Pathfinder* pathfinder;
		
		std::vector<Segment*> body;     //snake segments (change this to a queue?)
		std::vector<std::string> buffer; //input buffer 
		
		int startX, startY;			//starting position
        int screenW, screenH;       //screen resolution in pixels
		int maxBufferSize;			//max number of inputs to store in buffer
		
		bool dead;					//Triggered on collision with self/walls
		
		std::string direction;		//The snake's current heading (change to enum?)
        std::string searchAlgorithm;//Which algorithm do we use?

		Food* food;					//food piece for the game board

	public:
		Snake(int numSegments, int x, int y, int screenW, int screenH, std::string searchAlgorithm); //constructor

        Pathfinder* getPathfinder();
        
		int handle(int event);				  //FLTK event handler
		int getSize();					
		
		bool checkDead();					  //return game state

		void move();						  //Step the snake in the current direction
		void addSegment();
		void bufferInput();
		void checkCollision(); /*check if the snake has:
								 hit itself
								 hit a boundary
								 hit the food*/
};
