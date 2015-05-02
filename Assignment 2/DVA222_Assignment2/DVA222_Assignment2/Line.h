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



	Point GetPosition();

	virtual void Draw() override;

	virtual void Update() override;

};

