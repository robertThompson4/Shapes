#pragma once
#include"Shape.h"
#include<sstream>
#include<string>
class Star:public Shape
{
public:
	Star();
	Star(ifstream& fin, Picture& pictureOut);
	void Draw(Picture& pictureOut);
	void DrawShadow(Picture& pictureOut);
	bool accessCoord();
	virtual ~Star();
private:
	Coordinate coords;
};

