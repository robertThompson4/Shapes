#include "Rectangle.h"




Rectangle::Rectangle()
{
	
}

Rectangle::Rectangle(ifstream& fin, Picture& pictureOut)
{

	string initialText;
	string compare;
	char checkShadow1;
	//
	coords.center_X_Coord = 500;
	coords.center_Y_Coord = 500;
	coords.width = 1000;
	coords.height = 1000;
	coords.Red = 255;
	coords.Blue = 0;
	coords.Green = 0;
	coords.shadowCheck = false;
	//
	getline(fin, initialText);
	getline(fin, initialText);
	compare=initialText.substr(0, 24);

	if ("Center Coordinates(X Y):" == compare) 
	{
		initialText.replace(0, 25, "");
		istringstream sin(initialText);
		sin >> coords.center_X_Coord;
		sin >> coords.center_Y_Coord;	
	}
	getline(fin, initialText);
	compare = initialText.substr(0, 42);
	if (compare == "Rectangle Width and Height (width height):")
	{
		initialText.replace(0, 42, "");
		istringstream sin(initialText);
		sin >> coords.width;
		sin >> coords.height;
	}
	getline(fin, initialText);
	compare = initialText.substr(0, 31);
	if (compare == "Rectangle RGB (Red Green Blue):")
	{
		int r = 255;
		int g = 0;
		int b = 0;
		initialText.replace(0, 32, "");
		istringstream sin(initialText);
		sin >>r;
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

bool Rectangle::accessCoord()
{
	return coords.shadowCheck;
}

void Rectangle::Draw(Picture& pictureOut)
{
	coords.halfOfHeight = coords.height / 2;
	coords.halfOfWidth = coords.width / 2;
	RGBTriple desireColor(coords.Red, coords.Green, coords.Blue);
	pictureOut.AddLine(((coords.center_X_Coord - coords.halfOfWidth)),
		((coords.center_Y_Coord + coords.halfOfHeight)),
		((coords.center_X_Coord + coords.halfOfWidth)),
		((coords.center_Y_Coord + coords.halfOfHeight)),
		desireColor);
	pictureOut.AddLine(((coords.center_X_Coord + coords.halfOfWidth)),
		((coords.center_Y_Coord + coords.halfOfHeight)),
		((coords.center_X_Coord + coords.halfOfWidth)),
		((coords.center_Y_Coord - coords.halfOfHeight)),
		desireColor);
	pictureOut.AddLine(((coords.center_X_Coord - coords.halfOfWidth)),
		((coords.center_Y_Coord - coords.halfOfHeight)),
		((coords.center_X_Coord + coords.halfOfWidth)),
		((coords.center_Y_Coord - coords.halfOfHeight)),
		desireColor);
	pictureOut.AddLine(((coords.center_X_Coord - coords.halfOfWidth)),
		((coords.center_Y_Coord - coords.halfOfHeight)),
		((coords.center_X_Coord - coords.halfOfWidth)),
		((coords.center_Y_Coord + coords.halfOfHeight)),
		desireColor);
}


void Rectangle::DrawShadow(Picture& pictureOut)
{
	bool testShadowColor;
	coords.halfOfHeight = coords.height / 2;
	coords.halfOfWidth = coords.width / 2;
	RGBTriple whiteShadow(255, 255, 255);
	RGBTriple blackShadow(0, 0, 0);
	if (pictureOut.BackgroundColor == blackShadow)
	{
		pictureOut.AddLine(((coords.center_X_Coord-coords.halfOfWidth)+1), 
			((coords.center_Y_Coord+coords.halfOfHeight)+1),
			((coords.center_X_Coord+coords.halfOfWidth)+1), 
			((coords.center_Y_Coord + coords.halfOfHeight) + 1), 
			whiteShadow);
		pictureOut.AddLine(((coords.center_X_Coord + coords.halfOfWidth) + 1),
			((coords.center_Y_Coord + coords.halfOfHeight) + 1),
			((coords.center_X_Coord + coords.halfOfWidth) + 1),
			((coords.center_Y_Coord - coords.halfOfHeight) + 1),
			whiteShadow);
		pictureOut.AddLine(((coords.center_X_Coord - coords.halfOfWidth) + 1),
			((coords.center_Y_Coord - coords.halfOfHeight) + 1),
			((coords.center_X_Coord + coords.halfOfWidth) + 1),
			((coords.center_Y_Coord - coords.halfOfHeight) + 1),
			whiteShadow);
		pictureOut.AddLine(((coords.center_X_Coord - coords.halfOfWidth) + 1),
			((coords.center_Y_Coord - coords.halfOfHeight) + 1),
			((coords.center_X_Coord - coords.halfOfWidth) + 1),
			((coords.center_Y_Coord + coords.halfOfHeight) + 1),
			whiteShadow);
	}
	else
	{
		pictureOut.AddLine(((coords.center_X_Coord - coords.halfOfWidth) + 1),
			((coords.center_Y_Coord + coords.halfOfHeight) + 1),
			((coords.center_X_Coord + coords.halfOfWidth) + 1),
			((coords.center_Y_Coord + coords.halfOfHeight) + 1),
			blackShadow);
		pictureOut.AddLine(((coords.center_X_Coord + coords.halfOfWidth) + 1),
			((coords.center_Y_Coord + coords.halfOfHeight) + 1),
			((coords.center_X_Coord + coords.halfOfWidth) + 1),
			((coords.center_Y_Coord - coords.halfOfHeight) + 1),
			blackShadow);
		pictureOut.AddLine(((coords.center_X_Coord - coords.halfOfWidth) + 1),
			((coords.center_Y_Coord - coords.halfOfHeight) + 1),
			((coords.center_X_Coord + coords.halfOfWidth) + 1),
			((coords.center_Y_Coord - coords.halfOfHeight) + 1),
			blackShadow);
		pictureOut.AddLine(((coords.center_X_Coord - coords.halfOfWidth) + 1),
			((coords.center_Y_Coord - coords.halfOfHeight) + 1),
			((coords.center_X_Coord - coords.halfOfWidth) + 1),
			((coords.center_Y_Coord + coords.halfOfHeight) + 1),
			blackShadow);
	}
	
}

Rectangle::~Rectangle()
{
}
