#pragma once
#include "Line.h"
class VerticalLine : public Line
{
public:
	VerticalLine();
	VerticalLine(Point p1, double length);
	~VerticalLine();
};

