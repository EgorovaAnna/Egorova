#include "Image.h"
using namespace std;

Image::Image(int *tsize)
{
	int i;
	sizeI[0] = tsize[0];
	sizeI[1] = tsize[1];
	image = new Point* [sizeI[0]];
	for(i = 0; i < sizeI[0]; i++)
		image[i] = new Point [sizeI[1]];
}
int Image::getX()
{
	return sizeI[0];
}
int Image::getY()
{
	return sizeI[1];
}
void Image::loadIm(std::ifstream &fin)
{
	int i, j, k, a[3];
	for(i = 0; i < sizeI[0]; i++)
	{
		for(j = sizeI[1] - 1; j >= 0; j--)
		{
			for(k = 0; k < 3; k++)
			{
				fin >> a[k];
			}
			image[i][j].init(a);
		}
	}
}
void Image::drawPoint(int x, int y, int color)
{
	if((x < getX())&&(y < getY()))
		image[x][y] = color;
}
void Image::drawLine(int x1, int y1, int x2, int y2)
{
	const int deltaX = abs(x2 - x1);
	const int deltaY = abs(y2 - y1);
	const int signX = x1 < x2 ? 1 : -1;
	const int signY = y1 < y2 ? 1 : -1;
	int error = deltaX - deltaY;
	//cout << "point8" << x2 << " " << y2  << endl;
	drawPoint(x2, y2, 0);
	
	while(x1 != x2 || y1 != y2)
	{
		drawPoint(x1, y1, 0);
		cout << x1 << " " << y1 << endl;
		int error2 = error*2;
		if (error2 > -deltaY)
		{
			error -= deltaY;
			x1 += signX;
		}
		if (error2 < deltaX)
		{
			error += deltaX;
			y1 += signY;
		}
	}
}
void Image::showFile(std::string fl)
{
	ofstream fout;
	int i, j, k;
	fout.open(fl.c_str());
	fout << "P3" << endl;
	fout << sizeI[0] << " " << sizeI[1] << endl;
	for(i = 0; i < sizeI[0]; i++)
		for(j = sizeI[1] - 1; j >= 0; j--)
			for(k = 0; k < 3; k++)
				fout << image[i][j][k] << endl;
	fout.close();
}








