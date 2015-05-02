#pragma once
#include "Rectangle.h"
class BlueBox : Rectangle
{
public:
	BlueBox(Point position, int width, int height);
	BlueBox();
	~BlueBox();

protected:
	virtual void CollisionEffects(Ball* circle);
};

