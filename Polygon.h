#pragma once
#include "Shape.h"
#include<sstream>
#include<string>

class Polygon :
	public Shape
{
public:
	Polygon();
	Polygon(ifstream& fin, Picture& pictureOut);
	void Draw(Picture& pictureOut);
	void DrawShadow(Picture& pictureOut);
	bool accessCoord();
	virtual ~Polygon();
private:
	Coordinate coords;
};

