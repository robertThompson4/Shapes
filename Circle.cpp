#include "Circle.h"

const double PI = 3.1415926535897;

Circle::Circle()
{
}


Circle::Circle(ifstream& fin, Picture& pictureOut)
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
	compare = initialText.substr(0, 23);
	if ("Circle Radius (Radius):" == compare)
	{
		initialText.replace(0, 23, "");
		istringstream sin(initialText);
		sin >> coords.radius;
	}
	getline(fin, initialText);
	compare = initialText.substr(0, 28);
	if (compare == "Circle RGB (Red Green Blue):")
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

bool Circle::accessCoord()
{
	return coords.shadowCheck;
}

void Circle::Draw(Picture& pictureOut)
{
	RGBTriple desireOutput(coords.Red, coords.Green, coords.Blue);
	for (double i = 1; i <= 360; i++)
	{
		double x = coords.center_X_Coord + coords.radius * cos((i / 360)*(2 * PI));
		double y = coords.center_Y_Coord + coords.radius * sin((i / 360)*(2 * PI));
		pictureOut.SetPixelColor(x,y, desireOutput);
	}
}
void Circle::DrawShadow(Picture& pictureOut)
{
	RGBTriple whiteShadow(255, 255, 255);
	RGBTriple blackShadow(0, 0, 0);

	if (pictureOut.BackgroundColor == blackShadow)
	{
		for (double i = 1; i <= 360; i++)
		{
			double x = coords.center_X_Coord + coords.radius * cos((i / 360)*(2 * PI));
			double y = coords.center_Y_Coord + coords.radius * sin((i / 360)*(2 * PI));
			pictureOut.SetPixelColor((x + 1), y, whiteShadow);
		}
	}
	else
	{
		for (double i = 1; i <= 360; i++)
		{
			double x = coords.center_X_Coord + coords.radius * cos((i / 360)*(2 * PI));
			double y = coords.center_Y_Coord + coords.radius * sin((i / 360)*(2 * PI));
			pictureOut.SetPixelColor((x + 1), y, blackShadow);
		}
	}
}


Circle::~Circle()
{
}
