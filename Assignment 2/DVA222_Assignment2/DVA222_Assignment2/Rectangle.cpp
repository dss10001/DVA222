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
	r_right = position.X + (width / 2);
	r_left = position.X - (width / 2);
	r_top = position.Y - (height / 2);
	r_bottom = position.Y + (height / 2);

	if (circle->GetPosition().X < r_left + circle->GetRadius() / 2 ||
		circle->GetPosition().X > r_right - circle->GetRadius() / 2 ||
		circle->GetPosition().Y < r_top + circle->GetRadius() / 2 ||
		circle->GetPosition().Y > r_bottom - circle->GetRadius() / 2)
	{
		// do nothing
	}
	else
	{
		CollisionEffect(circle);
	}


	//if (circle->GetPosition().X - (circle->GetRadius() / 2) > r_right ||
	//	circle->GetPosition().X + (circle->GetRadius() / 2) < r_left ||
	//	circle->GetPosition().Y - (circle->GetRadius() / 2) > r_top ||
	//	circle->GetPosition().Y + (circle->GetRadius() / 2) < r_bottom)
	//{
	//	// do nothing
	//	int test = 0;
	//}
	//else
	//{
	//	CollisionEffect(circle);
	//}
}
void Rectangle::Draw()
{
	SetColor(Red, Green, Blue);
	DrawRectangle(position.X, position.Y, width, height);
}