#pragma once
#include "Shape.h"
#include "Ball.h"
#include "Graphix.h"
class Rectangle: Shape
{
public:
	int width, height;
	
	void CircleCollision(Ball* circle, Point p, int r);
	virtual void CollisionEffect(Ball* circle){}
	virtual void Draw();

	Rectangle(int width, int height);
	~Rectangle();

protected:
	// Rectangle color
	int Red, Green, Blue;
};

