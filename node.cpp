#include <climits>
#include <iostream>
#include <cmath>
#include "node.h"
using namespace std;

Node::Node(int x, int y) : Fl_Box(20 * x, 20 * y, 20, 20), x(x), y(y),
moveCost(0), totalCost(0), isObstacle(false), parent(nullptr)
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
void Node::reset()
{
    this->color(FL_BLACK);
    this->parent = nullptr;
    this->moveCost = INT_MAX;
    this->totalCost = INT_MAX;
    this->isObstacle = false;
    //~ this->redraw();
}

//calculate the cost to move from current node to goal (Manhattan distance)
int Node::heuristic(int xGoal, int yGoal)
{
	int manhattanDist = (abs(this->x - xGoal) + abs(this->y - yGoal));
	return manhattanDist;
    //~ int h1 = abs(this->x - xGoal) + abs(this->y - yGoal);

	//~ int dx = abs(this->x - xGoal);
	//~ int dy = abs(this->y - yGoal);
    //~ int h2 = sqrt(pow(dx, 2) + pow(dy, 2));
	//~ return sqrt(pow(dx, 2) + pow(dy, 2));
    //~ return (h1 + h2) / 2;
}

int Node::updateTotalCost(int xGoal, int yGoal)
{
	this->totalCost = this->moveCost + this->heuristic(xGoal, yGoal);
}

