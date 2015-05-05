#include "Ball.h"
#include "Graphix.h"
#include "Helper.h"


//Constructor
Ball::Ball(int x, int y, int r)
{
	position.X = x;
	position.Y = y;
	radius = r;
	speed = 3;
}

//Destructor
Ball::~Ball(void)
{

}

//Overrided Draw function
void Ball::Draw()
{
	SetColor(0,255,0);
	DrawCircle(position.X,position.Y, radius);
}

//Overrided Update function, it is responsible for updating the object's location for each frame of the animation
void Ball::Update()
{
	position.X += direction.X * speed;
	position.Y += direction.Y * speed;
}


//Some simple Get Set functions
double Ball::GetRadius()
{
	return radius;
}

void Ball::SetSpeed(double newSpeed)
{
	speed = Helper::clamp(0.1, 100, newSpeed);;
}

double Ball::GetSpeed()
{
	return speed;
}

Vector Ball::GetDirection()
{
	return direction;
}

void Ball::SetDirection(Vector newDirection)
{
	direction = Helper::NormalizeVector(newDirection);
}