#pragma once
#include "PuzzlePiece.h"

class Puzzle
{
private:
	int puzzleSize, length;
	PuzzlePiece *puzzlePieces;
public:
	Puzzle(int size, int length);
	~Puzzle();


};

