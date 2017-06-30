#ifndef House_h
#define House_h

#include <vector>
#include "Position.h"
#include "Image.h"
using namespace std;

class House
{
	int num_corners;
	int h;
	vector<Position> corners;
	vector<int*> corInt;
public:
	House();
	void swapPosition();
	void draw(Image &map, int nh);
	void addCorner(Position pos[4], Position tp);
	int getLeft();
	int getRight();
	int getUpper();
	int getLower();
	void paint(Image &map, int nh);
};
#endif