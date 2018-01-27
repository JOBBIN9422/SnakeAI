#pragma once 
#include <iostream>
#include <vector>
#include <FL/Fl.H>
#include <FL/Fl_Widget.H>
#include <FL/Fl_Box.H>
#include "segment.h"

class Food : public Fl_Box
{
	private:
		int x, y;	//food coordinates in the game window
	
	public:
		Food(int x, int y);
		
		//jump to a random position within bounds specified by max x/y
		void move(int maxX, int maxY, std::vector<Segment*> body);
		int getX();
		int getY();

		bool validPositon(int x, int y, std::vector<Segment*> body);
};
