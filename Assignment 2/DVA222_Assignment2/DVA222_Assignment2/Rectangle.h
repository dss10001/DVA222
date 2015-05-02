#pragma once
#include "Shape.h"
class Rectangle: Shape
{
public:
	int width, height;

	virtual void CircleCollision(Point position, int radius);

	Rectangle();
	~Rectangle();
};

