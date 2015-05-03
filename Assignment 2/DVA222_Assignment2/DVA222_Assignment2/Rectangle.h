#pragma once
#include "Shape.h"
#include "Ball.h"
#include "Graphix.h"
#include "ICollision.h"
class Rectangle: Shape, ICollision
{
public:
	int width, height;
	
	void CircleCollision(Ball* circle);	
	virtual void Draw();
	virtual void Update();
	Rectangle(Point position, int width, int height);
	Rectangle();
	~Rectangle();

protected:
	// Rectangle color
	int Red, Green, Blue;
	virtual void CollisionEffect(Ball* circle) {}
	
};

