#include "Application.h"


Application::Application()
{

}


Application::~Application()
{
}



bool Application::isNumberCorrect(int number)
{
	return (number >= MINIMUMVALUE && number <= MAXIMUMVALUE);
}

bool Application::Run()
{
	printf("");
	bool *endCondition = false;
	Puzzle *puzzle;
	createGame(puzzle);
	while (!endCondition)
	{
		update(endCondition);
		draw();
	}
	return false;
}

bool Application::createGame(Puzzle *puzzle)
{
	int c, length;
	MathHelper mathHelper;
	while (true)
	{
		printf("Enter a squared number (4,9,16,25)\n");
		c = getchar();
		putchar(c);
		if (isNumberCorrect(c) && mathHelper.isSquared(c, length))
		{
			puzzle = new Puzzle(c);
			printf("YES");
		}
		c = 0;
	}
}

void Application::update(bool *condition)
{

}

void Application::draw()
{
	
}

bool Application::playAgain()
{

}