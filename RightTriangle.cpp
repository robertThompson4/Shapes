#include "RightTriangle.h"



RightTriangle::RightTriangle()
{

}

RightTriangle::RightTriangle(ifstream& fin, Picture& pictureOut)
{
	string initialText;
	string compare;
	
	char checkShadow1;
	//
	coords.center_X_Coord = 100;
	coords.center_Y_Coord = 100;
	coords.width = 50;
	coords.height = 50;
	int r = 255;
	int g = 0;
	int b = 0;
	coords.Red = r;
	coords.Green = g;
	coords.Blue = b;
	coords.shadowCheck = false;
	//

	getline(fin, initialText);
	getline(fin, initialText);
	compare = initialText.substr(0, 24);
	if ("Center Coordinates(X Y):" == compare)
	{
		initialText.replace(0, 25, "");
		istringstream sin(initialText);
		sin >> coords.center_X_Coord;
		sin >> coords.center_Y_Coord;
	}
	getline(fin, initialText);
	compare = initialText.substr(0, 41);
	if ("Triangle Width and Height (width height):" == compare)
	{
		initialText.replace(0, 41, "");
		istringstream sin(initialText);
		sin >> coords.width;
		sin >> coords.height;
	}
	getline(fin, initialText);
	compare = initialText.substr(0, 30);
	if (compare == "Triangle RGB (Red Green Blue):")
	{
		initialText.replace(0, 31, "");
		istringstream sin(initialText);
		sin >> r;
		coords.Red = r;
		sin >> g;
		coords.Green = g;
		sin >> b;
		coords.Blue = b;
	}
	getline(fin, initialText);
	compare = initialText.substr(0, 15);
	if (compare == "Shadow? (Y/N): ")
	{
		initialText.replace(0, 15, "");
		istringstream sin(initialText);
		sin >> checkShadow1;

		if (checkShadow1 == 'Y')
		{
			coords.shadowCheck = true;
		}
	}
	else
	{
		coords.shadowCheck = false;
	}
}

bool RightTriangle::accessCoord()
{
	return coords.shadowCheck;
}


void RightTriangle::Draw(Picture& pictureOut)
{
	coords.halfOfHeight = coords.height / 2;
	coords.halfOfWidth = coords.width / 2;
	RGBTriple desiredColor(coords.Red, coords.Green, coords.Blue);
	pictureOut.AddLine((coords.center_X_Coord), (coords.center_Y_Coord),
		((coords.center_X_Coord + coords.width)),
		(coords.center_Y_Coord), desiredColor);
	pictureOut.AddLine((coords.center_X_Coord), (coords.center_Y_Coord),
		((coords.center_X_Coord)),
		((coords.center_Y_Coord + coords.height)), desiredColor);
	pictureOut.AddLine(((coords.center_X_Coord)),
		((coords.center_Y_Coord + coords.height)),
		((coords.center_X_Coord + coords.width)),
		(coords.center_Y_Coord), desiredColor);
}
void RightTriangle::DrawShadow(Picture& pictureOut)
{
	RGBTriple whiteShadow(255, 255, 255);
	RGBTriple blackShadow(0, 0, 0);
	coords.halfOfHeight = coords.height / 2;
	coords.halfOfWidth = coords.width / 2;
	if (pictureOut.BackgroundColor == blackShadow)
	{
		pictureOut.AddLine((coords.center_X_Coord + 1), (coords.center_Y_Coord + 1),
			((coords.center_X_Coord + coords.width) + 1),
			(coords.center_Y_Coord+1), whiteShadow);
		pictureOut.AddLine((coords.center_X_Coord + 1), (coords.center_Y_Coord + 1),
			((coords.center_X_Coord) + 1),
			((coords.center_Y_Coord + coords.height)+1), whiteShadow);
		pictureOut.AddLine(((coords.center_X_Coord) + 1),
			((coords.center_Y_Coord + coords.height) + 1),
			((coords.center_X_Coord + coords.width) + 1),
			(coords.center_Y_Coord + 1), whiteShadow);
	}
	else
	{
		pictureOut.AddLine((coords.center_X_Coord + 1), (coords.center_Y_Coord + 1),
			((coords.center_X_Coord + coords.width) + 1),
			(coords.center_Y_Coord + 1), blackShadow);
		pictureOut.AddLine((coords.center_X_Coord + 1), (coords.center_Y_Coord + 1),
			((coords.center_X_Coord) + 1),
			((coords.center_Y_Coord + coords.height) + 1), blackShadow);
		pictureOut.AddLine(((coords.center_X_Coord) + 1),
			((coords.center_Y_Coord + coords.height) + 1),
			((coords.center_X_Coord + coords.width) + 1),
			(coords.center_Y_Coord + 1), blackShadow);
	}

}

RightTriangle::~RightTriangle()
{
}
