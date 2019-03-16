#include "Diamond.h"



Diamond::Diamond()
{
}

Diamond::Diamond(ifstream& fin, Picture& pictureOut)
{
	string initialText;
	string compare;
	char checkShadow1;
	//
	coords.center_X_Coord = 0;
	coords.center_Y_Coord = 0;
	coords.width = 20;
	coords.height = 20;
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
	compare = initialText.substr(0, 40);
	if (compare == "Diamond Width and Height (width height):")
	{
		initialText.replace(0, 40, "");
		istringstream sin(initialText);
		sin >> coords.width;
		sin >> coords.height;
	}
	getline(fin, initialText);
	compare = initialText.substr(0, 29);
	if (compare == "Diamond RGB (Red Green Blue):")
	{
		initialText.replace(0, 29, "");
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

bool Diamond::accessCoord()
{
	return coords.shadowCheck;
}


void Diamond::Draw(Picture& pictureOut)
{
	coords.halfOfHeight = coords.height / 2;
	coords.halfOfWidth = coords.width / 2;
	RGBTriple desiredRGB(coords.Red, coords.Green, coords.Blue);
	pictureOut.AddLine((coords.center_X_Coord),
		((coords.center_Y_Coord - coords.halfOfHeight)),
		((coords.center_X_Coord + coords.halfOfWidth)),
		(coords.center_Y_Coord), desiredRGB);
	pictureOut.AddLine(((coords.center_X_Coord + coords.halfOfWidth)),
		(coords.center_Y_Coord),
		((coords.center_X_Coord)),
		((coords.center_Y_Coord + coords.halfOfHeight)), desiredRGB);
	pictureOut.AddLine(((coords.center_X_Coord)),
		((coords.center_Y_Coord + coords.halfOfHeight)),
		((coords.center_X_Coord - coords.halfOfWidth)),
		((coords.center_Y_Coord)), desiredRGB);
	pictureOut.AddLine(((coords.center_X_Coord - coords.halfOfWidth)),
		((coords.center_Y_Coord)),
		(coords.center_X_Coord ),
		((coords.center_Y_Coord - coords.halfOfHeight)), desiredRGB);

}
void Diamond::DrawShadow(Picture& pictureOut)
{
	RGBTriple whiteShadow(255, 255, 255);
	RGBTriple blackShadow(0, 0, 0);
	coords.halfOfHeight = coords.height / 2;
	coords.halfOfWidth = coords.width / 2;
	if (pictureOut.BackgroundColor == blackShadow)
	{
		pictureOut.AddLine((coords.center_X_Coord+1),
			((coords.center_Y_Coord-coords.halfOfHeight)),
			((coords.center_X_Coord+coords.halfOfWidth)+1),
			(coords.center_Y_Coord), whiteShadow);
		pictureOut.AddLine(((coords.center_X_Coord + coords.halfOfWidth) + 1),
			(coords.center_Y_Coord),
			((coords.center_X_Coord) + 1),
			((coords.center_Y_Coord+coords.halfOfHeight )), whiteShadow);
		pictureOut.AddLine(((coords.center_X_Coord) + 1),
			((coords.center_Y_Coord + coords.halfOfHeight)),
			((coords.center_X_Coord-coords.halfOfWidth) + 1),
			((coords.center_Y_Coord)), whiteShadow);
		pictureOut.AddLine(((coords.center_X_Coord - coords.halfOfWidth) + 1),
			((coords.center_Y_Coord)),
			(coords.center_X_Coord + 1),
			((coords.center_Y_Coord - coords.halfOfHeight)), whiteShadow);

	}
	else
	{
		pictureOut.AddLine((coords.center_X_Coord + 1),
			((coords.center_Y_Coord - coords.halfOfHeight)),
			((coords.center_X_Coord + coords.halfOfWidth) + 1),
			(coords.center_Y_Coord), blackShadow);
		pictureOut.AddLine(((coords.center_X_Coord + coords.halfOfWidth) + 1),
			(coords.center_Y_Coord),
			((coords.center_X_Coord) + 1),
			((coords.center_Y_Coord + coords.halfOfHeight)), blackShadow);
		pictureOut.AddLine(((coords.center_X_Coord) + 1),
			((coords.center_Y_Coord + coords.halfOfHeight)),
			((coords.center_X_Coord - coords.halfOfWidth) + 1),
			((coords.center_Y_Coord)), blackShadow);
		pictureOut.AddLine(((coords.center_X_Coord - coords.halfOfWidth) + 1),
			((coords.center_Y_Coord)),
			(coords.center_X_Coord + 1),
			((coords.center_Y_Coord - coords.halfOfHeight)), blackShadow);
	}

}


Diamond::~Diamond()
{
}
