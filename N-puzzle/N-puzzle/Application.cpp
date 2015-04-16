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
	int length = 0;
	createGame(length);
	Puzzle *puzzle = new Puzzle(length);
	while (!endCondition)
	{
		update(endCondition);
		draw(length, puzzle);
	}

	delete puzzle, endCondition;
	return false;
}

bool Application::createGame(int& length)
{
	char c[100];
	int value;
	MathHelper mathHelper;
	while (true)
	{
		printf("Enter a squared number (9,16,25). Minimum value is:%u and maximum valus is:%u.\n",MINIMUMVALUE,MAXIMUMVALUE);
		fgets(c, 100, stdin);
		value = atoi(c);

		if (mathHelper.isSquared(value, length) && isNumberCorrect(value))
		{
			return true;
		}
		else
		{
			printf("Value is not correct, please try again. ");
		}
		std::cin.clear();
	}
}

void Application::update(bool *condition)
{

}

void Application::draw(int &length, Puzzle *puzzle)
{
	system("cls");
	for (int y = 0; y < length; y++)
	{
		for (int x = 0; x < length; x++)
		{
			printf("%02d ", puzzle->GetPuzzlePieceValue(y, x));
		}
		printf("\n");
	}
}

bool Application::playAgain()
{
	std::string tempString;
	char input;
	do
	{
		std::cout << "Want to play again? Press Y/N.\n" << std::endl;
		std::cin >> input;
		input = tolower(input);
		std::cin.clear();
	} while (!std::cin.fail() && input != 'y' && input != 'n');
	if (input == 'y')
		return true;
	else
		return false;

}