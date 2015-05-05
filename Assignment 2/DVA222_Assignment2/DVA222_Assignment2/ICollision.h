#ifndef ICOLLISION_H
#include "Ball.h"
#define ICOLLISION_H

class ICollision
{
public:
	virtual void CollisionEffect(Ball* circle){}
	virtual void CircleCollision(Ball* circle){}
};
#endif