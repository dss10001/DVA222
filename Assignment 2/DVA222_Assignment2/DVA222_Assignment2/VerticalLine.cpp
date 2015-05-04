#include "VerticalLine.h"
#include "Helper.h"

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

void VerticalLine::CircleCollission(Ball* circle)
{
	if (Helper::IsInRange(position.Y, secondPosition.Y, circle->GetPosition().Y))
	{
		if (Helper::IsInRange((position.X - circle->GetRadius() / 2), (position.X + circle->GetRadius() / 2), circle->GetPosition().X))
		{
			CollisionEffect(circle);
		}
	}
}

void VerticalLine::CollisionEffect(Ball* circle)
{
	Vector tmp = circle->GetDirection();
	tmp.X = tmp.X * -1;
	circle->SetDirection(tmp);
}
