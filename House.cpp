#include "House.h"

House::House()
{
	num_corners = 0;
	h = 0;
}
House::House(Position tp, int posInt[2])
{
	int *coint = new int[2];
	if(posInt[0] >= 0 && posInt[1] >= 0)
	{
		coint[0] = posInt[0];
		coint[1] = posInt[1];
	}
	else
	{
		coint[0] = 0;
		coint[1] = 0;
	}
	num_corners = 1;
	corners.push_back(tp);
	corInt.push_back(coint);
	h = 100;
}
int House::getPosInt(int bin)
{
	if(num_corners == 0)
		return 0;
	if(bin == 0)
		return corInt[0][0];
	if(bin == 1)
		return corInt[0][1];
	return 0;
}
Position House::getPos()
{
	if(num_corners != 0)
		return corners[0];
	return Position();
}
void House::printAll()
{
	int i;
	for(i = 0; i < num_corners; i++)
	{
		cout << corners[i][0] << " " << corners[i][1] << " " << corInt[i][0] << " " << corInt[i][1] << " " << '\n';
	}
}
void House::draw(Image &map, int nh)
{
	int i;
	if (num_corners != 1)
	{
		for(i = 0; i < num_corners - 1; i++)
		{
			map.drawLine(corInt[i][0], corInt[i][1], corInt[i + 1][0], corInt[i + 1][1], nh);
		}
		map.drawLine(corInt[num_corners - 1][0], corInt[num_corners - 1][1], corInt[0][0], corInt[0][1], nh);
	}
}
void House::drawOnPhoto(Image &photo, int nh)
{
	photo.drawLine(corInt[0][0], corInt[0][1], corInt[0][0] - h, corInt[0][1], nh);
	photo.drawLine(corInt[0][0] - h, corInt[0][1], corInt[0][0] - h, corInt[0][1] + h, nh);
	photo.drawLine(corInt[0][0] - h, corInt[0][1] + h, corInt[0][0], corInt[0][1] + h, nh);
	photo.drawLine(corInt[0][0], corInt[0][1] + h, corInt[0][0], corInt[0][1], nh);
	paint(photo, nh);
}
void House::addCorner(Position pos[2], Position tp, int size[2])
{
	num_corners++;
	corners.push_back(tp);
	float x0, x1, y0, y1;
	int *cor = new int[2];
	y0 = pos[0][1];
	x0 = pos[0][0];
	y1 = pos[1][1];
	x1 = pos[1][0];
	cor[0] = floor((tp[0] - x0)*size[0]/(x1 - x0));
	cor[1] = floor((tp[1] - y0)*size[1]/(y1 - y0));
	corInt.push_back(cor);
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
	for(j = max(corInt[0][1] - h, 0); j < min(corInt[0][1] + h, map.getY()); j++)
	{
		for(i = max(corInt[0][0] - h, 0); i < min(corInt[0][0] + h, map.getX()); i++)
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
				map.drawPoint(k, j, 255, nh);
		count = 0;
		x1 = 0;
		x2 = 0;
	}
}






