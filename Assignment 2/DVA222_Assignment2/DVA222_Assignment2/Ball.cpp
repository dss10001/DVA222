#include "Ball.h"
#include "Graphix.h"

//Constructor
Ball::Ball(int x, int y, int r)
{
	position.X = x;
	position.Y = y;
	radius = r;

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
	position.X += speed.X;
	position.Y += speed.Y;
}



//Some simple Get Set functions
double Ball::GetRadius()
{
	return radius;
}

void Ball::SetSpeed(Vector newSpeed)
{
	speed = newSpeed;
}

Vector Ball::GetSpeed()
{
	return speed;
}