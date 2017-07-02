#include "Map.h"

int main()
{
	Map mmap;
	mmap.loadMap("mai.pnm");
	//mmap.loadFile("map.txt");
	mmap.loadOsm("map(1).osm");
	mmap.show();
	return 0;
}