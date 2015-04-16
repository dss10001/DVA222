#pragma once
#include<iostream>
#include<conio.h>
#include "Puzzle.h"
#include "MathHelper.h"
#include <stdlib.h>   

class Application
{
private:
	const int MINIMUMVALUE = 9, MAXIMUMVALUE = 100;


	bool isNumberCorrect(int number);
	bool playAgain();

	void update(bool *condition);
	void draw(int &length);

	bool createGame(Puzzle *puzzle, int& length);
public:
	Application();
	~Application();
	bool Run();
};

