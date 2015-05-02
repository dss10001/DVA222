// DVA222_Assignment2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
#include <math.h>
#include <time.h> 
#include "Graphix.h"

#include "Ball.h"
#include "HorizontalLine.h"
#include "VerticalLine.h"
#include "Rectangle.h"
#include "RedBox.h"
#include "BlueBox.h"

int linesCount = 6;
int ballCount = 1;
int rectangleCount = 4;

Ball **balls = new Ball*[ballCount];
Line **lines = new Line*[linesCount];
Rectangle **boxes = new Rectangle*[rectangleCount];

		 
int _tmain(int argc, char** argv)
{
	//NOTE:
	//----------------------------------------------------------------------
	//Create your objects in the global namespace
	//Initialize your object here, like what we do for the balls
	//----------------------------------------------------------------------
	srand(time(0));
	for(int i = 0; i < ballCount; i++)
	{
		balls[i] = new Ball(400, 300, 10);
		balls[i]->SetSpeed(Vector(10 * rand() / RAND_MAX -5 , 10 * rand() / RAND_MAX -5));
	}
	lines[0] = new VerticalLine(Point(50,80), 400);
	lines[1] = new VerticalLine(Point(250, 75), 200);
	lines[2] = new VerticalLine(Point(500, 275), 200);
	lines[3] = new VerticalLine(Point(750, 150), 400);
	lines[4] = new HorizontalLine(Point(50, 25), 700);
	lines[5] = new HorizontalLine(Point(50, 590), 700);

	boxes[0] = new BlueBox(Point(100, 400), 80, 50);
	boxes[1] = new BlueBox(Point(500, 100), 80, 50);
	boxes[2] = new RedBox(Point(100, 100), 80, 50);
	boxes[3] = new RedBox(Point(500, 500), 80, 50);
	
	//NOTE:
	//----------------------------------------------------------------------
	//Below this line control of your main is passed to graphix library
	//Don't touch this line, Don't write anything after it
	//Simply just don't do anything after this point ==> . 
	//----------------------------------------------------------------------
    InitGraphix(argc, argv);
    return 0;
}


void CollissionCheck()
{
	for (int i = 0; i < ballCount; i++)
	{
		for (int r = 0; r < rectangleCount; r++)
		{
			boxes[r]->CircleCollision(balls[i]);
		}
		for (int l = 0; l < linesCount; l++)
		{

		}
	}
}

//NOTE:
//------------------------------------------------------------------------------
//This is the function which is called by the graphix library to draw the objects
//Write all your drawing code here and not in main. 
//If you want to ReDraw stuff, call the ReDraw function at the end.
////------------------------------------------------------------------------------
void Draw()
{
	CollissionCheck();

	SetColor(255, 255, 255);

	for (int i = 0; i < ballCount; i++)
	{
		balls[i]->Update();
		balls[i]->Draw();
	}
	for (int i = 0; i < linesCount; i++)
	{
		lines[i]->Update();
		lines[i]->Draw();
	}
	for (int i = 0; i < rectangleCount; i++)
	{
		boxes[i]->Draw();
	}

	Redraw();
}
