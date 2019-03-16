#pragma once
#include "Shape.h"
#include<fstream>
#include<sstream>
#include"Coordinate.h"
#include"Picture.h"
#include"RGBTriple.h"



class Rectangle :
	public Shape
{
public:
	Rectangle();
	Rectangle(ifstream& fin,Picture& pictureOut);
	void Draw(Picture& pictureOut);
	void DrawShadow(Picture& pictureOut);
	bool accessCoord();
	virtual ~Rectangle();
private:
	Coordinate coords;
};

