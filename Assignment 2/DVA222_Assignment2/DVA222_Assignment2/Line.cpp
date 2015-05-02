#include "Line.h"


Line::Line()
{
	position = Point(0, 0);
	secondPosition = Point(0, 0);
}


Line::Line(Point p1, Point p2)
{
	position = p1;
	secondPosition = p2;
}

Line::~Line()
{
}

void Line::Draw()
{
	DrawLine(position.X, position.Y, secondPosition.X, secondPosition.Y);
}

void Line::Update()
{
	//No need to check update on something that do not move.
}
