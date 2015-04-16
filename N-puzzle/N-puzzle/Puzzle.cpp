#include "Puzzle.h"
#include <stdlib.h>

Puzzle::Puzzle(int size)
{
	puzzleSize = size;

	puzzlePieces = new PuzzlePiece*[size];
	for (int i = 0; i < size; i++)
	{
		puzzlePieces[i] = new PuzzlePiece[size];
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

// public funtions.
void Puzzle::MovePiece(direction moveDir)
{
	switch (moveDir)
	{
	case North:
		// check if move is possible
		// swap pieces
		break;
	case South:
		break;
	case West:
		break;
	case East:
		break;
	default:
		break;
	}
}

// private functions. 
void Puzzle::swapPieces(PuzzlePiece a, PuzzlePiece b)
{
	
}