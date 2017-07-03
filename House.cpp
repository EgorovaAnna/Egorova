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
void House::draw(Image &map, int nh)
{
	int i;
	for(i = 0; i < num_corners - 1; i++)
	{
		map.drawLine(corInt[i][0], corInt[i][1], corInt[i + 1][0], corInt[i + 1][1], nh);
	}
	map.drawLine(corInt[num_corners - 1][0], corInt[num_corners - 1][1], corInt[0][0], corInt[0][1], nh);
}
void House::addCorner(Position pos[4], Position tp)
{
	if((num_corners == 0)||!(corners[0] == tp))
	{
		num_corners++;
		corners.push_back(tp);
		float x0, x1, y0, y1;
		int *cor = new int[2];
		y0 = pos[0][1];
		x0 = pos[0][0];
		y1 = pos[3][1];
		x1 = pos[3][0];
		cor[0] = floor((tp[0] - x0)*732/(x1 - x0));
		cor[1] = floor((tp[1] - y0)*488/(y1 - y0));
		corInt.push_back(cor);
	}
}
int House::getLeft()
{
	int i, j = 0;
	for(i = 0; i < num_corners; i++)
		if(corInt[i][0] < corInt[j][0])
			j = i;
	return corInt[j][0];
}
int House::getRight()
{
	int i, j = 0;
	for(i = 0; i < num_corners; i++)
		if(corInt[i][0] > corInt[j][0])
			j = i;
	return corInt[j][0];
}
int House::getUpper()
{
	int i, j = 0;
	for(i = 0; i < num_corners; i++)
		if(corInt[i][1] > corInt[j][1])
			j = i;
	return corInt[j][1];
}
int House::getLower()
{
	int i, j = 0;
	for(i = 0; i < num_corners; i++)
		if(corInt[i][1] < corInt[j][1])
			j = i;
	return corInt[j][1];
}
void House::paint(Image &map, int nh)
{
	int i, j, k, count = 0, x1, x2;
	for(j = getLower(); j < getUpper(); j++)
	{
		for(i = 1 + getLeft(); i < getRight(); i++)
		{
			if(map.getTag(i, j) == nh)
			{
				if (count == 0)
				{
					x1 = i;
					count++;
				}
				else if ((i != x1 + 1)&&(x2 == 0))
				{
					x2 = i;
					count++;
				}
				if (i == x1 + 1)
				{
					x1++;
				}
			}
		}
		if (count == 2)
			for(k = x1 + 1; k < x2; k++)
				map.drawPoint(k, j, 0, nh);
		count = 0;
		x1 = 0;
		x2 = 0;
	}
}






