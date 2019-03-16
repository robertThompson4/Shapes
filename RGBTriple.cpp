#include"RGBTriple.h"


bool RGBTriple::operator==(const RGBTriple &rValue)
{
	bool answer = false;
	if (this->Red == rValue.Red && this->Green == rValue.Green && this->Blue == rValue.Blue)
	{
		answer = true;
	}
	else
	{
		answer = false;
	}
	return answer;
}

RGBTriple::RGBTriple() {}
RGBTriple::RGBTriple(unsigned char red, unsigned char green, unsigned char blue)
{
	Blue = blue;
	Green = green;
	Red = red;
}
