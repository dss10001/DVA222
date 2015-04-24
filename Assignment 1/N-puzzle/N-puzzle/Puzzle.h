#pragma once
#include "PuzzlePiece.h"
#include <iostream>

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
	void swapPieces(PuzzlePiece *a, PuzzlePiece *b);

public:
	bool CheckIfCorrect();
	void ResetPuzzle();
	void Draw();
	int GetPuzzlePieceValue(int index_x, int index_y) { return puzzlePieces[index_x][index_y].GetNumber(); };
	void MovePiece(direction moveDir);
	Puzzle(int size);
	~Puzzle();
};

