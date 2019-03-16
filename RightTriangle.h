#pragma once
#include "Shape.h"
#include<fstream>
#include<sstream>
#include"Coordinate.h"
#include"Picture.h"
#include"RGBTriple.h"


class RightTriangle :
	public Shape
{
	public:
	
		RightTriangle();
		RightTriangle(ifstream& fin, Picture& pictureOut);
		virtual ~RightTriangle();
		void Draw(Picture& pictureOut);
		void DrawShadow(Picture& pictureOut);
		bool accessCoord();
private:
	Coordinate coords;
};

