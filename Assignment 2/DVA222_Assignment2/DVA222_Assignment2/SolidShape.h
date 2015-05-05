#pragma once
#include "Shape.h"
#include "ICollision.h"
class SolidShape : public Shape, ICollision
{
public:
	virtual void CircleCollision(Ball* circle){};
	virtual void CollisionEffect(Ball* circle){};

	SolidShape();
	~SolidShape();
};

