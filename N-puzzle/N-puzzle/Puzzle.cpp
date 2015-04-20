#include "Puzzle.h"
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

Puzzle::Puzzle(int size)
{
	puzzleSize = size;
	srand(time(NULL));

	puzzlePieces = new PuzzlePiece*[size];
	for (int i = 0; i < size; i++)
	{
		puzzlePieces[i] = new PuzzlePiece[size];
	}

	InitializePuzzle();
	//ShufflePuzzle();
	Draw();
}

Puzzle::~Puzzle()
{
	for (int i = 0; i < puzzleSize; i++)
	{
		delete[] puzzlePieces[i];
	}
	delete[] puzzlePieces;
}

// public funtions.
void Puzzle::MovePiece(direction moveDir)
{
	switch (moveDir)
	{
	case North:
		if (blancY > 0)
		{
			swapPieces(&puzzlePieces[blancX][blancY], &puzzlePieces[blancX][blancY - 1]);
			blancY = blancY - 1;
		}
		break;
	case South:
		if (blancY < puzzleSize-1)
		{
			swapPieces(&puzzlePieces[blancX][blancY], &puzzlePieces[blancX][blancY + 1]);
			blancY = blancY + 1;
		}
		break;
	case West:
		if (blancX > 0)
		{
			swapPieces(&puzzlePieces[blancX][blancY], &puzzlePieces[blancX - 1][blancY]);
			blancX = blancX - 1;
		}
		break;
	case East:
		if (blancX < puzzleSize-1)
		{
			swapPieces(&puzzlePieces[blancX][blancY], &puzzlePieces[blancX + 1][blancY]);
			blancX = blancX + 1;
		}
		break;
	}
}
void Puzzle::ResetPuzzle()
{
	InitializePuzzle();
	ShufflePuzzle();
}
bool Puzzle::CheckIfCorrect()
{
	int correct_number = 1;
	for (int y = 0; y < puzzleSize; y++)
	{
		for (int x = 0; x < puzzleSize; x++)
		{
			if (puzzlePieces[x][y].GetNumber() != correct_number)
			{
				if ((x == puzzleSize - 1 && y == puzzleSize - 1) && puzzlePieces[x][y].GetNumber() == 0)
				{
					// do nothing
				}
				else
				{
					return 0;
				}
			}
			correct_number++;
		}
	}
	return 1;
}

// private functions. 
void Puzzle::InitializePuzzle()
{
	int piece_number = 1;
	for (int y = 0; y < puzzleSize; y++)
	{
		for (int x = 0; x < puzzleSize; x++)
		{
			puzzlePieces[x][y].SetNumber(piece_number);
			piece_number++;
		}
	}
	blancX = blancY = puzzleSize - 1;
	puzzlePieces[puzzleSize - 1][puzzleSize - 1].SetNumber(0);
}
void Puzzle::ShufflePuzzle()
{
	// random amount of moves. 
	int randomValue = rand() % (10 + 10) * (puzzleSize * puzzleSize);
	int dir = 0;
	for (int i = 0; i < randomValue; i++)
	{
		// get random direction.
		dir = rand() % 4;
		MovePiece((direction)dir);
		Draw();
	}
}
void Puzzle::swapPieces(PuzzlePiece *a, PuzzlePiece *b)
{
	PuzzlePiece tmp = *b;
	*b = *a;
	*a = tmp;
}
void Puzzle::Draw()
{
	system("cls");
	for (int y = 0; y < puzzleSize; y++)
	{
		for (int x = 0; x < puzzleSize; x++)
		{
			if (puzzlePieces[x][y].GetNumber() != 0)
			{
				printf("%02d ", puzzlePieces[x][y].GetNumber());
			}
			else
			{
				printf("   ");
			}
		} 
		printf("\n");
	}
}