#include "Line.h"



Line::Line()
{
}

Line::Line(ifstream& fin, Picture& pictureOut)
{
	string initialText;
	string compare;

	char checkShadow1;
	//
	coords.starting_X_Coord = 100;
	coords.starting_Y_Coord = 100;
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
	compare = initialText.substr(0, 20);
	if ("Starting Coord(X Y):" == compare)
	{
		initialText.replace(0, 21, "");
		istringstream sin(initialText);
		sin >> coords.starting_X_Coord;
		sin >> coords.starting_Y_Coord;
	}
	getline(fin, initialText);
	compare = initialText.substr(0, 18);
	if ("Ending Coord(X Y):" == compare)
	{
		initialText.replace(0, 18, "");
		istringstream sin(initialText);
		sin >> coords.ending_X_Coord;
		sin >> coords.ending_Y_Coord;
	}
	getline(fin, initialText);
	compare = initialText.substr(0, 26);
	if (compare == "Line RGB (Red Green Blue):")
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

bool Line::accessCoord()
{
	return coords.shadowCheck;
}


void Line::Draw(Picture& pictureOut)
{
	RGBTriple desiredColor(coords.Red, coords.Green, coords.Blue);
	pictureOut.AddLine(coords.starting_X_Coord, coords.starting_Y_Coord, coords.ending_X_Coord, coords.ending_Y_Coord, desiredColor);
}
void Line::DrawShadow(Picture& pictureOut)
{
	RGBTriple whiteShadow(255, 255, 255);
	RGBTriple blackShadow(0, 0, 0);
	if (pictureOut.BackgroundColor == blackShadow)
	{
		pictureOut.AddLine((coords.starting_X_Coord + 1), (coords.starting_Y_Coord + 1), (coords.ending_X_Coord + 1), (coords.ending_Y_Coord + 1), whiteShadow);
	}
	else
	{
		pictureOut.AddLine((coords.starting_X_Coord + 1), (coords.starting_Y_Coord + 1), (coords.ending_X_Coord + 1), (coords.ending_Y_Coord + 1), blackShadow);
	}
}

Line::~Line()
{
}
