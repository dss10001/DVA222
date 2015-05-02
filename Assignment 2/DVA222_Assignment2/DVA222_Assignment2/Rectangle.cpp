#include "Rectangle.h"


Rectangle::Rectangle()
{
	this->width = 0;
	this->height = 0;
	Red = 0;
	Green = 0;
	Blue = 0;
}
Rectangle::Rectangle(int width, int height)
{
	this->width = width;
	this->height = height;
	Red = 0;
	Green = 0;
	Blue = 0;
}

Rectangle::~Rectangle()
{
}


void Rectangle::CircleCollision(Ball* circle, Point p, int r)
{
	double r_right, r_left, r_top, r_bottom;
	r_right = position.X + (width / 2);
	r_left = position.X - (width / 2);
	r_top = position.Y - (height / 2);
	r_bottom = position.Y + (height / 2);

	if (circle->GetPosition().X + (r / 2) < r_right ||
		circle->GetPosition().X - (r / 2) > r_left ||
		circle->GetPosition().Y + (r / 2) < r_top ||
		circle->GetPosition().Y - (r / 2) > r_bottom)
	{
		CollisionEffect(circle);
	}
}
void Rectangle::Draw()
{
	SetColor(Red, Green, Blue);
	DrawRectangle(position.X, position.Y, width, height);
}