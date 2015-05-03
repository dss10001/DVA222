#include "HorizontalLine.h"
#include "Helper.h"

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

void HorizontalLine::CircleCollission(Ball* circle)
{
	if (Helper::IsInRange(position.X, secondPosition.X, circle->GetPosition().X))
	{
		/*if (Helper::IsInRange((position.Y - circle->GetRadius() / 2), (position.Y + circle->GetRadius() / 2), circle->GetPosition().Y))
		{
		}*/
	}

}

void HorizontalLine::CollisionEffect(Ball* circle)
{
	circle->SetDirection(Vector(circle->GetDirection().X, circle->GetDirection().Y*-1));
}

