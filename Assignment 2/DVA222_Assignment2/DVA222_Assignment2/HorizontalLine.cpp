#include "HorizontalLine.h"


HorizontalLine::HorizontalLine() 
{
	red = 0;
	green = 255;
	blue = 0;
}


HorizontalLine::HorizontalLine(Point p1, double length) : Line(p1, Point(p1.X + length, p1.Y))
{
	red = 0;
	green = 255;
	blue = 0;
}

HorizontalLine::~HorizontalLine()
{
}
