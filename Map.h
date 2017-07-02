#include "House.h"
#include <vector>
#include <fstream>
using namespace std;

class Map
{
	Image *map;
	Position pos[4];
	int size[2];
	vector<House*> houses;
public:
	Map(Position tpos[4], int tsize[2]);
	Map();
	void addHouse(House *h);
	void loadMap(string fl);
	void loadFile(string fl);
	void loadOsm(string fl);
	float stringToFloat(string buf);
	void searchNode(string fl, int node, Position &tp);
	int stringToNode(string buf);
	void show();
	~Map();
};
