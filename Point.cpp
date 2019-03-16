#include "Point.h"



Point::Point()
{
}

Point::Point(ifstream& fin, Picture& pictureOut)
{
	string initialText;
	string compare;

	char checkShadow1;
	//
	coords.center_X_Coord = 100;
	coords.center_Y_Coord = 100;
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
	compare = initialText.substr(0, 17);
	if ("Coordinates(X Y):" == compare)
	{
		initialText.replace(0, 17, "");
		istringstream sin(initialText);
		sin >> coords.center_X_Coord;
		sin >> coords.center_Y_Coord;
	}
	
	getline(fin, initialText);
	compare = initialText.substr(0, 27);
	if (compare == "Point RGB (Red Green Blue):")
	{
		initialText.replace(0, 28, "");
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





bool Point::accessCoord()
{
	return coords.shadowCheck;
}

void Point::Draw(Picture& pictureOut)
{
	RGBTriple desiredColor(coords.Red, coords.Green, coords.Blue);
	pictureOut.SetPixelColor(coords.center_X_Coord, coords.center_Y_Coord, desiredColor);
}

void Point::DrawShadow(Picture& pictureOut)
{
	RGBTriple whiteShadow(255, 255, 255);
	RGBTriple blackShadow(0, 0, 0);
	if (pictureOut.BackgroundColor == blackShadow)
	{
		pictureOut.SetPixelColor(coords.center_X_Coord + 1, coords.center_Y_Coord + 1, whiteShadow);
	}
	else
	{
		pictureOut.SetPixelColor(coords.center_X_Coord + 1, coords.center_Y_Coord + 1, blackShadow);
	}
}

Point::~Point()
{
}
