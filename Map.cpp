
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
	int a = 0;
	string buf;
	fin >> buf;
	while (!(isdigit(buf[0])&&isdigit(buf[1])))
		fin >> buf;
	size[0] = 100*(int)(buf[0] - '0') + 10*(int)(buf[1] - '0') + (int)(buf[2] - '0');
	fin >> size[1];
	map = new Image(size);
	map -> loadIm(fin);
	fin.close();
}
void Map::loadFile(string fl)
{
	ifstream fin(fl.c_str());
	double x0, x1, y0, y1, x, y;
	int i, j, k;
	Position tp;
	string buf;
	fin >> size[0] >> size[1];
	fin >> x0 >> y0 >> x1 >> y1;
	pos[0].add(x0, y0);
	pos[1].add(x1, y1);
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
	double x0, x1, y0, y1, count;
	int i, j, stop = 0;
	long int node; 
	Position tp;
	string buf;
	while (buf != "<bounds")
		fin >> buf;
	fin >> buf;
	//x0 = stringToDouble(buf);
	fin >> buf;
	//y0 = stringToDouble(buf);
	fin >> buf;
	//x1 = stringToDouble(buf);
	fin >> buf;
	//y1 = stringToDouble(buf);
	y1 = 55.814005;
	x0 = 37.4954;
	y0 = 55.81117;
	x1 = 37.50315;
	pos[0].add(x0, y0);
	pos[1].add(x1, y1);
	//cout << x0 << " " << y0 << " " << x1 << " " << y1 << endl;
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
					if(tp.isInMap(pos[0], pos[1]) == 1)
					{
						houses.back() -> addCorner(pos, tp);
						//if (houses.size() == 10)
						//	cout << houses.size() << " " << node << endl;
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
double Map::stringToDouble(string buf)
{
	int i = 0, j = 1;
	double fl = 0;
	while (isdigit(buf[i]) != true)
		i++;
	while (isdigit(buf[i]) || buf[i] == '.')
	{
		if (buf[i] != '.')
		{
			fl = fl + (double)(buf[i] - '0')*100*(pow(10, -j));
			j++;
		}
		i++;
	}
	return fl;
}
long int Map::stringToNode(string buf)
{
	int i = 0, j = 0, count = 0;
	long int node = 0;
	while (isdigit(buf[i]) != true)
		i++;
	if (buf.size() > 1)
	{
		while (isdigit(buf[i]))
		{
			if (count == 0)
				j = i;
			i++;
			count++;
		}
		while (isdigit(buf[j]))
		{
			node = node + (int)(buf[j] - '0')*(pow(10, count - 1));
			j++;
			count--;
		}
	}
	if (j == 0)
		node = -1;
	return node;
}
void Map::searchNode(string fl, long int node, Position &tp)
{
	ifstream fin2(fl.c_str());
	string buf;
	double x, y;
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
			y = stringToDouble(buf);
			fin2 >> buf;
			x = stringToDouble(buf);
			tp.add(x, y);
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
		//if(l == 10)
		//{
			houses[l] -> draw(*map, l + 1);
			//houses[l] -> printAll();
		//}
		//houses[l] -> paint(*map, l + 1);
	}
	map -> showFile("mapShow.pnm");
	
}
Map::~Map()
{
	houses.clear();
}


