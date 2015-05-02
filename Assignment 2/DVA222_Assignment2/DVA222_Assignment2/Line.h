#pragma once
#include "Shape.h"
#include "Graphix.h"

class Line : public Shape
{
protected:
	int red, green, blue;
	Point secondPosition;
public:
	Line();
	~Line();
	Line(Point p1, Point p2);

	Vector GetOutDirection(Vector *incomingDirection);

	Point GetPosition() const { return position; };
	Point GetSecondPosition() const { return secondPosition; };

	virtual void Draw() override;

	virtual void Update() override;

};

