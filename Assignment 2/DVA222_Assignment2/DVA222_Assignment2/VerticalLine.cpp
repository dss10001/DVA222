#include "VerticalLine.h"


VerticalLine::VerticalLine()
{
	red = 255;
	green = 255;
	blue = 0;
}


VerticalLine::VerticalLine(Point p1, double length) : Line(p1, Point(p1.X, p1.Y + length))
{
	red = 255;
	green = 255;
	blue = 0;
}

VerticalLine::~VerticalLine()
{
}

void VerticalLine::CollisionEffect(Ball* circle)
{
	circle->SetDirection(Vector(circle->GetDirection().X*-1, circle->GetDirection().Y));
}
