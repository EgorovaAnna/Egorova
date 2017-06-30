#include "House.h"

House::House()
{
	num_corners = 0;
	h = 0;
}
void House::swapPosition()
{
	Position tp;
	int a = 0, i;
	while(a!=1)
	{
		a = 1;
		for (i = 0; i < 3; i++)
		{
			//if (p)
		}
	}
}
void House::draw(Image &map)
{
	int i;
	for(i = 0; i < num_corners - 1; i++)
	{
		cout << "point7" << endl;
		map.drawLine(corInt[i][0], corInt[i][1], corInt[i + 1][0], corInt[i + 1][1]);
	}
	map.drawLine(corInt[num_corners - 1][0], corInt[num_corners - 1][1], corInt[0][0], corInt[0][1]);
}
void House::addCorner(Position pos[4], Position tp)
{
	num_corners++;
	corners.push_back(tp);
	float x0, x1, y0, y1;
	int *cor = new int[2];
	
	x0 = pos[0][0];
	y0 = pos[0][1];
	x1 = pos[1][0];
	y1 = pos[2][1];
	//cout << "point" << x1 << " " << y1  << endl;
	cor[0] = floor((tp[0] - x0)*950/(x1-x0));
	cor[1] = floor((tp[1] - y0)*616/(y1-y0));
	corInt.push_back(cor);
}