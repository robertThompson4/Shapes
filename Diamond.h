#pragma once
#include "Shape.h"
#include<fstream>
#include<sstream>
#include"Coordinate.h"
#include"Picture.h"
#include"RGBTriple.h"


class Diamond :
	public Shape
{
public:
	Diamond();
	Diamond(ifstream& fin, Picture& pictureOut);
	void Draw(Picture& pictureOut);
	void DrawShadow(Picture& pictureOut);
	bool accessCoord();
	virtual ~Diamond();
private:
	Coordinate coords;
};

