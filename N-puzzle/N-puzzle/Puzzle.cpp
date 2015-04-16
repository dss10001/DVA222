#include "Puzzle.h"
#include <stdlib.h>
#include <time.h>

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
	ShufflePuzzle();
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

// private functions. 
void Puzzle::InitializePuzzle()
{
	int piece_number = 1;
	for (int i = 0; i < puzzleSize; i++)
	{
		for (int j = 0; j < puzzleSize; j++)
		{
			puzzlePieces[i][j].SetNumber(piece_number);
			piece_number++;
		}
	}
	blancX = blancY = puzzleSize - 1;
	puzzlePieces[puzzleSize - 1][puzzleSize - 1].SetNumber(0);
}
void Puzzle::ShufflePuzzle()
{
	// random amount of moves. 
	int randomValue = rand() % 100 + 50;
	int dir = 0;
	for (int i = 0; i < randomValue; i++)
	{
		// get random direction.
		dir = rand() % 4;
		MovePiece((direction)dir);
	}
}
bool Puzzle::CheckIfCorrect()
{
	int correct_number = 1;
	for (int i = 0; i < puzzleSize; i++)
	{
		for (int j = 0; j < puzzleSize; j++)
		{
			if (puzzlePieces[i][j].GetNumber() != correct_number)
			{
				if (i != puzzleSize - 1 && j != puzzleSize - 1)
				{
					return 0;
				}
			}
		}
	}
	return 1;
}
void Puzzle::swapPieces(PuzzlePiece *a, PuzzlePiece *b)
{
	PuzzlePiece tmp = *b;
	*b = *a;
	*a = tmp;
}
