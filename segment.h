#pragma once 
#include <iostream>
#include <FL/Fl.H>
#include <FL/Fl_Widget.H>
#include <FL/Fl_Box.H>

class Segment : public Fl_Box
{
	private:
		int x, y;	//box location in the game window
	
	public:
		Segment(int x, int y);		   //constructor
		void move(int newX, int newY); //jump to a new position
		int getX();
		int getY();
};
