#include "Map.h"

int main()
{
	Map mmap;
	mmap.loadMap("map1_1.pnm");
	mmap.loadOsm("map(1).osm");
	mmap.show();
	return 0;
}
