#include "Polygon.h"



Polygon::Polygon()
{
}

Polygon::Polygon(ifstream& fin, Picture& pictureOut)
{
	string initialText;
	string compare;
	basicCoord sample;
	sample.X_Coord = 0;
	sample.Y_Coord = 0;
	vector<basicCoord> holder(100, sample);

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
	compare = initialText.substr(0, 24);
	if ("Coordinates(X Y X Y...):" == compare)
	{
		initialText.replace(0, 25, "");
		int i = 0;
		istringstream sin(initialText);
		bool checkVec = true;
		while (checkVec != false)
		{
			
			sin >> holder[i].X_Coord;
			sin >> holder[i].Y_Coord;
			if (holder[i].X_Coord == 0 && holder[i].Y_Coord == 0)
				checkVec = false;
			i++;
		}
	}
	coords.poly = holder;
	getline(fin, initialText);
	compare = initialText.substr(0, 29);
	if (compare == "Polygon RGB (Red Green Blue):")
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

bool Polygon::accessCoord()
{
	return coords.shadowCheck;
}

void Polygon::Draw(Picture& pictureOut)
{
	RGBTriple desiredColor(coords.Red, coords.Green, coords.Blue);
	bool checkVec2 = false;
	int increm = 0;
		while (checkVec2 == false)
		{
			if (coords.poly[increm + 1].X_Coord == 0 && coords.poly[increm + 1].Y_Coord == 0)
			{
				checkVec2 = true;
			}
			else
			{
				pictureOut.AddLine((coords.poly[increm].X_Coord), (coords.poly[increm].Y_Coord), (coords.poly[increm + 1].X_Coord), (coords.poly[increm + 1].Y_Coord), desiredColor);
			}
			increm++;
		}
		pictureOut.AddLine((coords.poly[increm-1].X_Coord), (coords.poly[increm-1].Y_Coord), (coords.poly[0].X_Coord), (coords.poly[0].Y_Coord), desiredColor);
}
void Polygon::DrawShadow(Picture& pictureOut)
{
	RGBTriple whiteShadow(255, 255, 255);
	RGBTriple blackShadow(0, 0, 0);
	bool checkVec2 = false;
	int increm = 0;
	if (pictureOut.BackgroundColor == blackShadow)
	{
		while (checkVec2 == false)
		{
			if (coords.poly[increm + 1].X_Coord == 0 && coords.poly[increm + 1].Y_Coord == 0)
			{
				checkVec2 = true;
			}
			else
			{
				pictureOut.AddLine((coords.poly[increm].X_Coord + 1), (coords.poly[increm].Y_Coord + 1), (coords.poly[increm + 1].X_Coord + 1), (coords.poly[increm + 1].Y_Coord + 1), whiteShadow);
			}
			increm++;
		}
		pictureOut.AddLine((coords.poly[increm-1].X_Coord + 1), (coords.poly[increm-1].Y_Coord + 1), (coords.poly[0].X_Coord + 1), (coords.poly[0].Y_Coord + 1), whiteShadow);
	}
	else
	{
		while (checkVec2 == false)
		{
			if (coords.poly[increm + 1].X_Coord == 0 && coords.poly[increm + 1].Y_Coord == 0)
			{
				checkVec2 = true;
			}
			else
			{
				pictureOut.AddLine((coords.poly[increm].X_Coord + 1), (coords.poly[increm].Y_Coord + 1), (coords.poly[increm + 1].X_Coord + 1), (coords.poly[increm + 1].Y_Coord + 1), blackShadow);
			}
			increm++;
		}
		pictureOut.AddLine((coords.poly[increm-1].X_Coord+ 1), (coords.poly[increm-1].Y_Coord + 1), (coords.poly[0].X_Coord + 1), (coords.poly[0].Y_Coord + 1), blackShadow);
	}
}


Polygon::~Polygon()
{
}
