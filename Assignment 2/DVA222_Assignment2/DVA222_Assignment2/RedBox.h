#pragma once
#include "Rectangle.h"
class RedBox : public Rectangle
{
public:
	RedBox(Point position, int width, int height);
	RedBox();
	~RedBox();

protected:
	virtual void CollisionEffect(Ball* circle);
};

