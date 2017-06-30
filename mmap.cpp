#include "Map.h"

int main()
{
	Map mmap;
	mmap.loadMap("mai.pnm");
	cout << "point1" << endl;
	mmap.loadFile("map.txt");
	cout << "point4" << endl;
	mmap.show();
	return 0;
}