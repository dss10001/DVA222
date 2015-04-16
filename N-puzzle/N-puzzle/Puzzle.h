#pragma once
#include "PuzzlePiece.h"

enum direction { North, South, West, East };

class Puzzle
{
private:
	int puzzleSize;
	PuzzlePiece **puzzlePieces;
	int blancX;
	int blancY;

	void InitializePuzzle();
	void ShufflePuzzle();
	bool CheckIfCorrect();
	void swapPieces(PuzzlePiece *a, PuzzlePiece *b);

public:
	void ResetPuzzle();
	int GetPuzzlePieceValue(int index_x, int index_y) { return puzzlePieces[index_x][index_y].GetNumber(); };
	void MovePiece(direction moveDir);
	Puzzle(int size);
	~Puzzle();
};

