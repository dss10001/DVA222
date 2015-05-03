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
	double tmp_speed = circle->GetSpeed();
	tmp_speed += 0.5;
	circle->SetSpeed(tmp_speed);
}
