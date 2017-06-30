#include "Map.h"

int main()
{
	Map mmap;
	mmap.loadMap("mai.pnm");
	mmap.loadFile("map.txt");
	mmap.show();
	return 0;
}