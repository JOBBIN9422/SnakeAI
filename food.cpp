#include "food.h"
using namespace std;

Food::Food(int x, int y) : Fl_Box(x, y, 20, 20)
{
	this->box(FL_OFLAT_BOX);
	this->color(FL_RED);
	this->x = x;
	this->y = y;
	this->show();
}

void Food::move(int maxX, int maxY, vector<Segment*> body)
{
	this->hide();
	//jump to a random position within bounds (max x/y)
	int newX, newY;
	do
	{
		//randomize coordinates as long as they are invalid (blocked by snake body)
		newX = (rand() % maxX/20)*20;
		newY = (rand() % maxY/20)*20;
	} while (!validPositon(newX, newY, body));
	
	this->position(newX, newY);	//move the segment to its new position
	this->x = newX;				//update segment coordinates
	this->y = newY;
	
	this->show();
}

bool Food::validPositon(int x, int y, vector<Segment*> body)
{
	for (int i = 0; i < body.size(); i++)
	{
		if (body.at(i)->getX() == x && body.at(i)->getY() == y)
			return false;
	}
	return true;
	
}

int Food::getX()
{
	return this->x;
}

int Food::getY()
{
	return this->y;
}	

