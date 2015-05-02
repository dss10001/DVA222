#pragma once
#include "Rectangle.h"
class BlueBox : public Rectangle
{
public:
	BlueBox(Point position, int width, int height);
	BlueBox();
	~BlueBox();

protected:
	virtual void CollisionEffects(Ball* circle);
};

