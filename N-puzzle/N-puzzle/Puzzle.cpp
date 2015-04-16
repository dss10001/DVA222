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
	for (size_t i = 0; i < puzzleSize; i++)
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
			swapPieces(&puzzlePieces[blancX][blancY], &puzzlePieces[blancX][blancY - 1]);
		break;
	case South:
		if (blancY < puzzleSize)
			swapPieces(&puzzlePieces[blancX][blancY], &puzzlePieces[blancX][blancY + 1]);
		break;
	case West:
		if (blancX > 0)
			swapPieces(&puzzlePieces[blancX][blancY], &puzzlePieces[blancX - 1][blancY]);
		break;
	case East:
		if (blancX < puzzleSize)
			swapPieces(&puzzlePieces[blancX][blancY], &puzzlePieces[blancX + 1][blancY]);
		break;
	}
}

// private functions. 
void Puzzle::InitializePuzzle()
{
	int piece_number = 0;
	for (int i = 0; i < puzzleSize; i++)
	{
		for (int j = 0; j < puzzleSize; j++)
		{
			puzzlePieces[i][j].SetNumber(piece_number);
			piece_number++;
		}
	}
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
	int correct_number = 0;
	for (int i = 0; i < puzzleSize; i++)
	{
		for (int j = 0; j < puzzleSize; j++)
		{
			if (puzzlePieces[i][j].GetNumber() != correct_number)
			{
				return 0;
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
