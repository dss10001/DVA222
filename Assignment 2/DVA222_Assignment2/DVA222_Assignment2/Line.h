#pragma once
#include "Shape.h"
#include "Graphix.h"

class Line : public Shape
{
protected:
	Point secondPosition;
public:
	Line();
	~Line();

	Vector GetOutDirection(Vector *incomingDirection);

	Point GetPosition() const { return position; };
	Point GetSecondPosition() const { return secondPosition; };

	virtual void Draw() override;

	virtual void Update() override;

};

