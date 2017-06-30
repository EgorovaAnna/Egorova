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
Position::Position()
{
	lattitude = 0;
	longitude = 0;
}