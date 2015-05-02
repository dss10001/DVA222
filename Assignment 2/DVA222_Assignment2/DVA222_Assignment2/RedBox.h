#pragma once
#include "Rectangle.h"
class RedBox : Rectangle
{
	virtual void CollisionEffect(Ball* circle);

public:
	RedBox();
	~RedBox();
};

