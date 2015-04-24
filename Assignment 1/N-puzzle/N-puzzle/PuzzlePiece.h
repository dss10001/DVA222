#pragma once

class PuzzlePiece
{
private:
	int number;
public:
	void SetNumber(int value) { number = value; };
	int GetNumber() { return number; };
	PuzzlePiece(int number);
	PuzzlePiece();
	~PuzzlePiece();
};

