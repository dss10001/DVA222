#pragma once
#include "Line.h"
class HorizontalLine : public Line
{

public:
	HorizontalLine();
	HorizontalLine(Point p1, double length);
	~HorizontalLine();

	virtual void CollisionEffect(Ball* circle) override;
	virtual void CircleCollission(Ball* circle);
};

