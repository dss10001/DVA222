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
	Puzzle *puzzle = NULL;
	int length = 0;
	createGame(puzzle, length);
	while (!endCondition)
	{
		update(endCondition);
		draw(length);
	}
	delete puzzle, endCondition;
	return false;
}

bool Application::createGame(Puzzle *puzzle, int& length)
{
	char c[3];
	int value;
	MathHelper mathHelper;
	while (true)
	{
		printf("Enter a squared number (9,16,25). Minimum value is:%u and maximum valus is:%u.\n",MINIMUMVALUE,MAXIMUMVALUE);
		fgets(c, 3, stdin);
		value = atoi(c);
		if (mathHelper.isSquared(value, length) && isNumberCorrect(value))
		{
			puzzle = new Puzzle(value);
			printf("YES");
		}
		
	}
}

void Application::update(bool *condition)
{

}

void Application::draw(int &length)
{
	system("cls");
	for (int y = 0; y < length; y++)
	{
		for (int x = 0; x < length; x++)
		{

		}
	}
}

bool Application::playAgain()
{
	return false;
}