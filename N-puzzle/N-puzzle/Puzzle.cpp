#include "Puzzle.h"
#include <stdlib.h>

Puzzle::Puzzle(int size)
{
	puzzleSize = size;

	puzzlePieces = (PuzzlePiece**)malloc(sizeof(PuzzlePiece**)*size);
	for (size_t i = 0; i < size; i++)
	{
		puzzlePieces[i] = (PuzzlePiece*)malloc(sizeof(PuzzlePiece)*size);
	}
}


Puzzle::~Puzzle()
{
	for (size_t i = 0; i < puzzleSize; i++)
	{
		delete[] puzzlePieces[i];
	}
	delete[] puzzlePieces;
}
