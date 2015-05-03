#pragma once
#include "Shape.h"

class Ball : public Shape
{
public:
	Ball(int x, int y, int r);
	~Ball(void);

	virtual void Draw();
	virtual void Update();
	void SetSpeed(double newSpeed);
	void SetDirection(Vector newDirection);
	double GetSpeed();
	double GetRadius();
	Vector GetDirection();
	
protected: 
	double radius;
	double speed;
	Vector direction;           //speed is a vector. This means that we have 2 values for the ball's movement along x and y axis separately.
                                //This makes it easy to make changes in the direction with relation to any of the x or y axis. For example
                                //bouncing back from a vertical border means just reversing the speed in x direction but not y (Why?).
};

