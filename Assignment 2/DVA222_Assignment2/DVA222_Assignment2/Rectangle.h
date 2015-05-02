#pragma once
#include "Shape.h"
#include "Ball.h"
#include "Graphix.h"
class Rectangle: Shape
{
public:
	int width, height;
	
	void CircleCollision(Ball* circle);	
	virtual void Draw();

	Rectangle(Point position, int width, int height);
	Rectangle();
	~Rectangle();

protected:
	// Rectangle color
	int Red, Green, Blue;
	virtual void CollisionEffect(Ball* circle){}
};

