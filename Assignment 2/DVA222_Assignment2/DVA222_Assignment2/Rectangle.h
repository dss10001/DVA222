#pragma once
#include "Shape.h"
class Rectangle: Shape
{
public:
	int width, height;

	virtual void CircleCollision(Point p, int r);

	Rectangle();
	~Rectangle();
};

