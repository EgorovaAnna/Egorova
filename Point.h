#ifndef Point_h
#define Point_h

#include <iostream>
using namespace std;

class Point
{
	int point[3];
public:
	Point();
	void operator=(int a);
	int operator[](int a);
	void init(int a[3]);
};
#endif