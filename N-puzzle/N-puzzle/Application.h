#pragma once
#include<iostream>
#include<conio.h>
#include "Puzzle.h"
#include "MathHelper.h"

class Application
{
private:
	const int MINIMUMVALUE = 9, MAXIMUMVALUE = 100;


	bool isNumberCorrect(int number);
	void draw();
public:
	Application();
	~Application();
	bool Run();
};

