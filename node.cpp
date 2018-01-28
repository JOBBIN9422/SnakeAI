#include <climits>
#include <iostream>
#include <cmath>
#include "node.h"
using namespace std;

Node::Node(int x, int y) : Fl_Box(20 * x, 20 * y, 20, 20), x(x), y(y),
moveCost(INT_MAX), totalCost(INT_MAX), isObstacle(false), parent(nullptr)
{
	this->color(FL_BLACK);
	this->box(FL_BORDER_FRAME);
	//~ cout << "node created at " << this->Fl_Widget::x() << " " << this->Fl_Widget::y() << endl;
}

int Node::getX() { return this->x; }
int Node::getY() { return this->y; }
int Node::getMoveCost() { return this->moveCost; }
int Node::getTotalCost() { return this->totalCost; }

bool Node::checkObstacle() { return this->isObstacle; }

Node* Node::getParent() { return this->parent; }

void Node::setObstacle(bool obstacle) { this->isObstacle = obstacle; }
void Node::setMoveCost(int moveCost) { this->moveCost = moveCost; } 
void Node::setTotalCost(int totalCost) { this->totalCost = totalCost; } 
void Node::setParent(Node* parent) { this->parent = parent; } 


//calculate the cost to move from current node to goal (Manhattan distance)
int Node::heuristic(int xGoal, int yGoal)
{
	return abs(this->x - xGoal) + abs(this->y - yGoal);

	//~ int dx = abs(this->x - xGoal);
	//~ int dy = abs(this->y - yGoal);

	//~ return sqrt(pow(dx, 2) + pow(dy, 2));
}

int Node::updateTotalCost(int xGoal, int yGoal)
{
	this->totalCost = moveCost + heuristic(xGoal, yGoal);
}
