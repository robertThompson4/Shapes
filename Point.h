#pragma once
#include "Shape.h"
#include<sstream>
#include<string>
class Point :
	public Shape
{
public:
	Point();
	Point(ifstream& fin, Picture& pictureOut);
	void Draw(Picture& pictureOut);
	void DrawShadow(Picture& pictureOut);
	bool accessCoord();
	virtual ~Point();
private:
	Coordinate coords;
};

