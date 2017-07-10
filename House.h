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
	House(Position tp, int posInt[2]);
	void swapPosition();
	void draw(Image &map, int nh);
	void drawOnPhoto(Image &photo, int nh);
	void addCorner(Position pos[2], Position tp, int size[2]);
	int getPosInt(int bin);
	Position getPos();
	int getLeft();
	int getRight();
	int getUpper();
	int getLower();
	void printAll();
	void paint(Image &map, int nh);
};
#endif