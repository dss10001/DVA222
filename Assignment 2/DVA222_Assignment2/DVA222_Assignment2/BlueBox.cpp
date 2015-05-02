#include "BlueBox.h"


BlueBox::BlueBox(Point position, int width, int height)
:Rectangle(position, width, height)
{
	Red = 0;
	Green = 0;
	Blue = 255;
}
BlueBox::BlueBox()
{
	Red = 0;
	Green = 0;
	Blue = 255;
}

BlueBox::~BlueBox()
{
}

void BlueBox::CollisionEffects(Ball* circle)
{
	Vector tmp_speed = circle->GetSpeed();
	tmp_speed.X -= 0.1;
	tmp_speed.Y -= 0.1;
	circle->SetSpeed(tmp_speed);
}
