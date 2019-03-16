#pragma once
#include "Shape.h"
#include<sstream>
#include<string>
#include<math.h>
#define _USE_MATH_DEFINES

class Circle :
	public Shape
{
public:
	Circle();
	Circle(ifstream& fin, Picture& pictureOut);
	void Draw(Picture& pictureOut);
	void DrawShadow(Picture& pictureOut);
	bool accessCoord();
	virtual ~Circle();
private:
	Coordinate coords;
	
};

