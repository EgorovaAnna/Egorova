#include "Position.h"


void Position::add(float tlat, float tlon)
{
	lattitude = tlat;
	longitude = tlon;
}
float Position::operator[](int bin)
{
	if (bin == 0) 
		return lattitude;
	if (bin == 1)
		return longitude;
	else
		return -1;
}
int Position::isInMap(Position posmin, Position posmax)
{
	if((lattitude >= posmin[0])&&(lattitude <= posmax[0])&&(longitude <= posmax[1])&&(longitude >= posmin[1]))
		return 1;
	else
		return -1;
}
Position::Position()
{
	lattitude = 0;
	longitude = 0;
}