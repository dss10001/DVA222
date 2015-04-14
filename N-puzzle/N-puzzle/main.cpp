#include<iostream>
#include<conio.h>
#include "Puzzle.h"
#include "MathHelper.h"

bool isSquared(int number, int &length)
{
	if (number < 0)
		return false;
	int root(round(sqrt(number)));
	length = root;
	return number == root * root;
}
bool isNumberCorrect(int number)
{
	return (number >= 9 && number <= 100);
}

int main()
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
			puzzle = new Puzzle(c, length);
			printf("YES");
		}
		c = 0;
	}
	return 0;
}