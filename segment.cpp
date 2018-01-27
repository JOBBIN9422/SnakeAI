#include "segment.h"
using namespace std;

Segment::Segment(int x, int y) : Fl_Box(x, y, 20, 20)
{
	this->box(FL_FLAT_BOX);
	this->color(FL_GREEN);
	this->x = x;
	this->y = y;
}

void Segment::move(int newX, int newY)
{
	this->hide();
	this->x = newX;				//update segment coordinates
	this->y = newY;
	//cout << "x = " << newX << " y = " << newY << endl;
	this->position(newX, newY);	//move the segment to its new position
	this->show();
}

int Segment::getX()
{
	return this->x;
}

int Segment::getY()
{
	return this->y;
}	
