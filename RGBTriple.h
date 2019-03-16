#pragma once;


struct RGBTriple
{
	unsigned char Blue;
	unsigned char Green;
	unsigned char Red;

	RGBTriple();
	RGBTriple(unsigned char red, unsigned char green, unsigned char blue);
	bool operator==(const RGBTriple &);
};

