//Robert Thompson

#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<list>
#include"Picture.h"
#include"Shape.h"
#include"Rectangle.h"
#include"Coordinate.h"
#include"RightTriangle.h"
#include"Diamond.h"
#include"Star.h"
#include"Point.h"
#include"Polygon.h"
#include"Circle.h"
#include"Line.h"

using std::ifstream;
using std::ofstream;
using std::string;
using std::iterator;



void defineShape(string input, ifstream& fin, list<Shape*>& shapes, Picture& background)	
{
	
	Shape* holder = nullptr;
	if (input == "Rectangle")
	{
		holder = new Rectangle(fin, background);
		shapes.push_back(holder);
	}
	else if (input == "Circle")
	{
		holder = new Circle(fin, background);
		shapes.push_back(holder);
	}
	else if (input == "Line")
	{
		holder = new Line(fin, background);
		shapes.push_back(holder);
	}
	else if (input == "Point")
	{
		holder = new Point(fin, background);
		shapes.push_back(holder);
	}
	else if (input == "Diamond")
	{
		holder = new Diamond(fin, background);
		shapes.push_back(holder);
	}
	else if (input == "RightTriangle")
	{
		holder = new RightTriangle(fin, background);
		shapes.push_back(holder);
	}
	else if (input == "Polygon")
	{
		holder = new Polygon(fin, background);
		shapes.push_back(holder);
	}
	else if (input == "Star")
	{
		holder = new Star(fin, background);
		shapes.push_back(holder);
	}
	
}

void main(int argc, char* argv[])
{
	if (argc == 2)
	{
		string fileName = argv[1];
		string shapeInputString;
		ifstream fin(fileName);
		list<Shape*> shapes;
		
		getline(fin, shapeInputString);

		int heightBack = 1000;
		int widthBack = 1000;
		int r = 255;
		int g = 50;
		int b = 0;
		if (shapeInputString == "Background")
		{
			string compare;
			string initialText;
			getline(fin, initialText);
			compare = initialText.substr(0, 25);
			if (compare == "Background(Width Height):")
			{
				initialText.replace(0, 25, "");
				istringstream sin(initialText);
				sin >> widthBack;
				sin >> heightBack;
			}
			getline(fin, initialText);
			compare = initialText.substr(0, 31);
			if (compare == "Background RGB(Red Green Blue):")
			{
				initialText.replace(0, 32, "");
				istringstream sin(initialText);
				sin >> r;
				sin >> g;
				sin >> b;
			}
		}
		RGBTriple backColor(r, g, b);
		Picture background(widthBack, heightBack, backColor);
		background.BackgroundColor = backColor;
		//
		while (!fin.eof()&&!fin.fail())
		{
			if (fin)
			{
				fin >> shapeInputString;
				if (shapeInputString == "")
					fin >> shapeInputString;
				defineShape(shapeInputString, fin, shapes, background);
			}
		}
		//
		for (Shape* shapeInc:shapes)
		{
			if(shapeInc->accessCoord()==true)
			{
				shapeInc->DrawShadow(background);
			}
			shapeInc->Draw(background);
		}
		fileName = fileName.substr(0, fileName.length() - 3) + "bmp";
		background.WriteToFile(fileName.c_str());
		
		for (Shape* shapeInc : shapes)
		{
			delete shapeInc;
		}
	}
	else
	{
		std::cout << "Display Error" << endl;

	}
}