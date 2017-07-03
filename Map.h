#include "House.h"
#include <vector>
#include <fstream>
using namespace std;

class Map
{
	Image *map;
	Position pos[2];
	int size[2];
	vector<House*> houses;
public:
	Map(Position tpos[2], int tsize[2]);
	Map();
	void addHouse(House *h);
	void loadMap(string fl);
	void loadFile(string fl);
	void loadOsm(string fl);
	double stringToDouble(string buf);
	void searchNode(string fl, long int node, Position &tp);
	long int stringToNode(string buf);
	void show();
	~Map();
};
