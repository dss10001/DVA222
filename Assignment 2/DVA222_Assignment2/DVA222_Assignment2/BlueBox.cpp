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

void BlueBox::CollisionEffect(Ball* circle)
{
	double tmp_speed = circle->GetSpeed();
	tmp_speed += -0.04;
	circle->SetSpeed(tmp_speed);
}
