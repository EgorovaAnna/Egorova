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
	void draw(Image &map);
	void addCorner(Position pos[4], Position tp);
};
#endif