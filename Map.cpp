
#include "Map.h"

Map::Map()
{
	
}
void Map::addHouse(House *h)
{
	houses.push_back(h);
}
void Map::loadMap(string fl)
{
	ifstream fin(fl.c_str());
	string buf;
	fin >> buf;
	while (buf != "950")
		fin >> buf;
	size[0] = 950;
	fin >> size[1];
	map = new Image(size);
	map -> loadIm(fin);
	fin.close();
}
void Map::loadFile(string fl)
{
	ifstream fin(fl.c_str());
	float x0, x1, y0, y1, x, y;
	int i, j, k;
	Position tp;
	string buf;
	fin >> size[0] >> size[1];
	fin >> x0 >> y0 >> x1 >> y1;
	pos[0].add(x0, y0);
	pos[1].add(x1, y0);
	pos[2].add(x0, y1);
	pos[3].add(x1, y1);
	//while(fin != eof)
	//{
	//	fin >> buf;
		addHouse(new House());
	//	while (buf != 0)
		for(i = 0; i < 4; i++)
		{
			fin >> x >> y;
			if((x >= x0)&&(x <= x1)&&(y >= y0)&&(y <= y1))
			{
				tp.add(x, y);
				houses.back() -> addCorner(pos, tp);
			}
		}
	//}
	fin.close();
}
void Map::loadOsm(string fl)
{
	ifstream fin(fl.c_str());
	float x0, x1, y0, y1;
	int i, j, node, stop = 0;
	Position tp;
	string buf;
	while (buf != "<bounds")
		fin >> buf;
	fin >> buf;
	x0 = stringToFloat(buf);
	fin >> buf;
	y0 = stringToFloat(buf);
	fin >> buf;
	x1 = stringToFloat(buf);
	fin >> buf;
	y1 = stringToFloat(buf);
	pos[0].add(x0, y0);
	pos[1].add(x1, y0);
	pos[2].add(x0, y1);
	pos[3].add(x1, y1);
	while(buf != "<way")
		fin >> buf;
	while(buf != "<relation")
	{
		if (buf == "<way")
		{
			addHouse(new House());
			while (buf!= "</way>")
			{
				fin >> buf;
				if ((buf == "<nd")&&(stop == 0))
				{ 
					fin >> buf;
					node = stringToNode(buf);
					searchNode(fl, node, tp);
					if(tp.isInMap(pos[0], pos[3]) == 1)
					{
						houses.back() -> addCorner(pos, tp);
					}
					else
					{
						stop = 1;
						houses.pop_back();
					}
				}
			}
			stop = 0;
			fin >> buf;
		}
	}
	fin.close();
}
float Map::stringToFloat(string buf)
{
	int i = 0, j = 1;
	float fl = 0;
	while (isdigit(buf[i]) != true)
		i++;
	while (isdigit(buf[i]) || buf[i] == '.')
	{
		if (buf[i] != '.')
		{
			fl = fl + (float)(buf[i] - '0')*100*(pow(10, -j));
			j++;
		}
		i++;
	}
	return fl;
}
int Map::stringToNode(string buf)
{
	int i = 0, j = 0, count = 0;
	int node = 0;
	while (isdigit(buf[i]) != true)
		i++;
	if (buf.size() > 1)
	{
		while (isdigit(buf[i]))
		{
			node = node + (int)(buf[i] - '0')*100000000*(pow(10, -j));
			j++;
			i++;
			count++;
		}
	}
	if (count == 0)
		node = -1;
	return node;
}
void Map::searchNode(string fl, int node, Position &tp)
{
	ifstream fin2(fl.c_str());
	string buf;
	float x, y;
	int i, stop = 0;
	fin2 >> buf;
	while(stop == 0)
	{
		while(buf != "<node")
			fin2 >> buf;
		fin2 >> buf;
		if(stringToNode(buf) == node)
		{
			fin2 >> buf;
			for (i = 0; i < 6; i++)
				fin2 >> buf;
			x = stringToFloat(buf);
			fin2 >> buf;
			y = stringToFloat(buf);
			tp. add(x, y);
			stop = 1;
		}
	}
	fin2.close();
}
void Map::show()
{
	int l;
	for(l = 0; l < houses.size(); l++)
	{
		houses[l] -> draw(*map, l + 1);
		//houses[l] -> paint(*map, l + 1);
	}
	map -> showFile("mapShow.pnm");
	
}
Map::~Map()
{
	houses.clear();
}


