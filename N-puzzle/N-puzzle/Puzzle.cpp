#include "Puzzle.h"


Puzzle::Puzzle(int size, int length)
{
	puzzleSize = size;
	Puzzle::length = length;
	puzzlePieces = new PuzzlePiece[length];
	for (size_t i = 1; i < size; i++)
	{
		//puzzlePieces[i] = new PuzzlePiece(i);

	}
}


Puzzle::~Puzzle()
{
	delete[] puzzlePieces;
}
