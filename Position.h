#ifndef Position_h
#define Position_h

#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <fstream>


class Position
{
	float lattitude;
	float longitude;
public:
	void add(float tlat, float tlon);
	float operator[](int bin);
	Position();
};

#endif



