#include "Application.h"


Application::Application()
{

}


Application::~Application()
{
}

bool Application::isSquared(int number, int &length)
{
	if (number < 0)
		return false;
	int root(round(sqrt(number)));
	length = root;
	return number == root * root;
}

bool Application::isNumberCorrect(int number)
{
	return (number >= MINIMUMVALUE && number <= MAXIMUMVALUE);
}

bool Application::Run()
{
	printf("");

	int c, length;
	Puzzle *puzzle;

	while (true)
	{
		printf("Enter a squared number (4,9,16,25)\n");
		c = getchar();
		putchar(c);
		if (isNumberCorrect(c) && isSquared(c, length))
		{
			puzzle = new Puzzle(c);
			printf("YES");
		}
		c = 0;
	}
	while (true)
	{

	}
	return false;
}

void Application::Draw()
{
	
}