#pragma once
#include "PuzzlePiece.h"

enum direction { North, South, West, East };

class Puzzle
{
private:
	int puzzleSize;
	PuzzlePiece **puzzlePieces;

	void swapPieces(PuzzlePiece a, PuzzlePiece b);

public:
	void MovePiece(direction moveDir);

	Puzzle(int size);
	~Puzzle();
};

