#include "Line.h"


Line::Line()
{
}


Line::~Line()
{
}

void Line::Draw()
{
	DrawLine(position.X, position.Y, secondPosition.X, secondPosition.Y);
}

void Line::Update()
{
	//No need to check update on something that do not move.
}
