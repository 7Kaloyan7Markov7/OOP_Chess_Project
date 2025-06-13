#pragma once
#include "Rook_declaration.h"
#include "Bishop_declaration.h"
#include "Knight_declaration.h"
#include "Queen_declaration.h"
#include "King_declaration.h"
#include "Pawn_declaration.h"

class Board
{
private:
	Figure* board[8][8];

	void fillPawns();
	void fillRooks(); 
	void fillKnights();
	void fillBishops();
	void fillQueens();
	void fillKings();
	void fillEmptySpaces();

	void moveCoordinates(size_t prevRow, size_t prevCol, size_t newRow, size_t newCol);

public:

	const Figure* getFigure(size_t currentRow, size_t currentCol) const;

	Board();
	~Board();


	void move(const String& from, const String& to);
	void printBoard() const;
};
