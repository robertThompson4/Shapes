#pragma once
#include "Shape.h"
#include<sstream>
#include<string>

class Line :
	public Shape
{
public:
	Line();
	Line(ifstream& fin, Picture& pictureOut);
	void Draw(Picture& pictureOut);
	void DrawShadow(Picture& pictureOut);
	bool accessCoord();
	virtual ~Line();
private:
	Coordinate coords;
	
};

