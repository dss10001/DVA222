#pragma once
#include "PuzzlePiece.h"

class Puzzle
{
private:
	int puzzleSize;
	PuzzlePiece **puzzlePieces;
public:
	Puzzle(int size);
	~Puzzle();
};

