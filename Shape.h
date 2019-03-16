#pragma once
#include<string>
#include<fstream>
#include"Picture.h"
#include"RGBTriple.h"
#include"Coordinate.h"



class Shape
{
public:
	Shape();
	Shape(std::string s);
	virtual void Draw(Picture& pictureOut) = 0;
	virtual void DrawShadow(Picture& pictureOut) = 0;
	virtual bool accessCoord()=0;
	virtual ~Shape();
private:

};

