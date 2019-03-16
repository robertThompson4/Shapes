#pragma once
#include"RGBTriple.h"
#include<vector>

struct basicCoord
{
	int X_Coord=0;
	int Y_Coord=0;
};

class Coordinate: public RGBTriple
{
public:
	Coordinate();
	virtual ~Coordinate();

	int starting_X_Coord;
	int starting_Y_Coord;
	int height;
	int width;
	int ending_X_Coord;
	int ending_Y_Coord;
	int center_X_Coord;
	int center_Y_Coord;
	int radius;
	int halfOfWidth;
	int halfOfHeight;
	basicCoord sample;
	std::vector<basicCoord> poly;
	bool shadowCheck;

};

