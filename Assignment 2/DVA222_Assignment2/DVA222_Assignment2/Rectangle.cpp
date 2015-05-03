#include "Rectangle.h"


Rectangle::Rectangle()
{
	this->width = 0;
	this->height = 0;
	position.X = 0;
	position.Y = 0;
	Red = 0;
	Green = 0;
	Blue = 0;
}
Rectangle::Rectangle(Point position, int width, int height)
{
	this->width = width;
	this->height = height;
	this->position.X = position.X;
	this->position.Y = position.Y;
	Red = 0;
	Green = 0;
	Blue = 0;
}

Rectangle::~Rectangle()
{
}


void Rectangle::CircleCollision(Ball* circle)
{
	double r_right, r_left, r_top, r_bottom;
	r_right = position.X + width;
	r_left = position.X;
	r_top = position.Y;
	r_bottom = position.Y + height;

	if (circle->GetPosition().X + (circle->GetRadius() / 2) > r_left &&
		circle->GetPosition().X - (circle->GetRadius() / 2) < r_right &&
		circle->GetPosition().Y + (circle->GetRadius() / 2) > r_top &&
		circle->GetPosition().Y - (circle->GetRadius() / 2) < r_bottom)
	{
		CollisionEffect(circle);
	}
}
void Rectangle::Draw()
{
	SetColor(Red, Green, Blue);
	DrawRectangle(position.X, position.Y, width, height);
}
void Rectangle::Update()
{

}