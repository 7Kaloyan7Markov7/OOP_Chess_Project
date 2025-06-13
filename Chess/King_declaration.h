#pragma once
#include "Figure_declaration.h"
#include "Board_declaration.h"
#include "Parser_declaration.h"

class King : public Figure
{
private:
	bool hasMoved;

	void findEnemyKing(const Board& board, size_t& enemyKingRow, size_t& enemyKingCol) const;

public:
	King(const ColorType& color, wchar_t icon, const FigureType& type);

	bool getHasMoved() const override;
	
	void setHasMoved(bool hasMoved) override;

	MyVector<String> collectAllMoves(const Board& board, size_t currentRow, size_t currentCol) const override;
};