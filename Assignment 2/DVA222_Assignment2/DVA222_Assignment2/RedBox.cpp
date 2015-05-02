#include "RedBox.h"


RedBox::RedBox(Point position, int width, int height)
:Rectangle(position, width, height)
{
	Red = 255; 
	Green = 0;
	Blue = 0;
}
RedBox::RedBox()
{
	Red = 255;
	Green = 0;
	Blue = 0;
}

RedBox::~RedBox()
{
}

void RedBox::CollisionEffect(Ball* circle)
{
	Vector tmp_speed = circle->GetSpeed();
	tmp_speed.X += 0.1;
	tmp_speed.Y += 0.1;
	circle->SetSpeed(tmp_speed);
}
