#include "Star.h"

Star::Star()
{
}


Star::Star(ifstream& fin, Picture& pictureOut)
{
	string initialText;
	string compare;

	char checkShadow1;
	//
	coords.center_X_Coord = 100;
	coords.center_Y_Coord = 100;
	coords.width = 50;
	coords.height = 50;
	coords.radius = 50;
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
	compare = initialText.substr(0, 21);
	if ("Star Radius (Radius):" == compare)
	{
		initialText.replace(0, 21, "");
		istringstream sin(initialText);
		sin >> coords.radius;
	}
	getline(fin, initialText);
	compare = initialText.substr(0, 26);
	if (compare == "Star RGB (Red Green Blue):")
	{
		initialText.replace(0, 27, "");
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


Star::~Star()
{
	
}

bool Star::accessCoord()
{
	return coords.shadowCheck;
}

void Star::Draw(Picture& pictureOut)
{
	RGBTriple desiredColor(coords.Red, coords.Green, coords.Blue);
	pictureOut.AddLine((coords.center_X_Coord), ((coords.center_Y_Coord - coords.radius)), (coords.center_X_Coord), (coords.center_Y_Coord), desiredColor);
	pictureOut.AddLine((coords.center_X_Coord), ((coords.center_Y_Coord + coords.radius)), (coords.center_X_Coord), (coords.center_Y_Coord), desiredColor);
	pictureOut.AddLine(((coords.center_X_Coord - coords.radius)), (coords.center_Y_Coord), (coords.center_X_Coord), (coords.center_Y_Coord), desiredColor);
	pictureOut.AddLine(((coords.center_X_Coord + coords.radius)), (coords.center_Y_Coord), (coords.center_X_Coord), (coords.center_Y_Coord), desiredColor);
	//
	//
	pictureOut.AddLine(((coords.center_X_Coord + coords.radius)), ((coords.center_Y_Coord + coords.radius)), (coords.center_X_Coord), (coords.center_Y_Coord), desiredColor);
	pictureOut.AddLine(((coords.center_X_Coord + coords.radius)), ((coords.center_Y_Coord - coords.radius)), (coords.center_X_Coord), (coords.center_Y_Coord), desiredColor);
	pictureOut.AddLine(((coords.center_X_Coord - coords.radius)), ((coords.center_Y_Coord + coords.radius)), (coords.center_X_Coord), (coords.center_Y_Coord), desiredColor);
	pictureOut.AddLine(((coords.center_X_Coord - coords.radius)), ((coords.center_Y_Coord - coords.radius)), (coords.center_X_Coord), (coords.center_Y_Coord), desiredColor);

}
void Star::DrawShadow(Picture& pictureOut)
{
	RGBTriple whiteShadow(255, 255, 255);
	RGBTriple blackShadow(0, 0, 0);
	
	if (pictureOut.BackgroundColor == blackShadow)
	{
		pictureOut.AddLine((coords.center_X_Coord + 1), ((coords.center_Y_Coord - coords.radius) + 1), (coords.center_X_Coord + 1), (coords.center_Y_Coord + 1), whiteShadow);
		pictureOut.AddLine((coords.center_X_Coord + 1), ((coords.center_Y_Coord + coords.radius) + 1), (coords.center_X_Coord + 1), (coords.center_Y_Coord + 1), whiteShadow);
		pictureOut.AddLine(((coords.center_X_Coord - coords.radius) + 1), (coords.center_Y_Coord + 1), (coords.center_X_Coord + 1), (coords.center_Y_Coord + 1), whiteShadow);
		pictureOut.AddLine(((coords.center_X_Coord + coords.radius) + 1), (coords.center_Y_Coord + 1), (coords.center_X_Coord + 1), (coords.center_Y_Coord + 1), whiteShadow);
		//
		//
		pictureOut.AddLine(((coords.center_X_Coord + coords.radius) + 1), ((coords.center_Y_Coord + coords.radius)), (coords.center_X_Coord + 1), (coords.center_Y_Coord), whiteShadow);
		pictureOut.AddLine(((coords.center_X_Coord + coords.radius) + 1), ((coords.center_Y_Coord - coords.radius)), (coords.center_X_Coord + 1), (coords.center_Y_Coord), whiteShadow);
		pictureOut.AddLine(((coords.center_X_Coord - coords.radius) + 1), ((coords.center_Y_Coord + coords.radius)), (coords.center_X_Coord + 1), (coords.center_Y_Coord), whiteShadow);
		pictureOut.AddLine(((coords.center_X_Coord - coords.radius) + 1), ((coords.center_Y_Coord - coords.radius)), (coords.center_X_Coord + 1), (coords.center_Y_Coord), whiteShadow);
	
	}
	else
	{
		pictureOut.AddLine((coords.center_X_Coord + 1), ((coords.center_Y_Coord - coords.radius) + 1), (coords.center_X_Coord + 1), (coords.center_Y_Coord + 1), blackShadow);
		pictureOut.AddLine((coords.center_X_Coord + 1), ((coords.center_Y_Coord + coords.radius) + 1), (coords.center_X_Coord + 1), (coords.center_Y_Coord + 1), blackShadow);
		pictureOut.AddLine(((coords.center_X_Coord - coords.radius) + 1), (coords.center_Y_Coord + 1), (coords.center_X_Coord + 1), (coords.center_Y_Coord + 1), blackShadow);
		pictureOut.AddLine(((coords.center_X_Coord + coords.radius) + 1), (coords.center_Y_Coord + 1), (coords.center_X_Coord + 1), (coords.center_Y_Coord + 1), blackShadow);
		//
		//
		pictureOut.AddLine(((coords.center_X_Coord + coords.radius) + 1), ((coords.center_Y_Coord + coords.radius)), (coords.center_X_Coord + 1), (coords.center_Y_Coord), blackShadow);
		pictureOut.AddLine(((coords.center_X_Coord + coords.radius) + 1), ((coords.center_Y_Coord - coords.radius)), (coords.center_X_Coord + 1), (coords.center_Y_Coord), blackShadow);
		pictureOut.AddLine(((coords.center_X_Coord - coords.radius) + 1), ((coords.center_Y_Coord + coords.radius)), (coords.center_X_Coord + 1), (coords.center_Y_Coord), blackShadow);
		pictureOut.AddLine(((coords.center_X_Coord - coords.radius) + 1), ((coords.center_Y_Coord - coords.radius)), (coords.center_X_Coord + 1), (coords.center_Y_Coord), blackShadow);
	}
}

