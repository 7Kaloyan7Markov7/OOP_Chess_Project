#pragma once
#include "Figure_declaration.h"

class Pawn : public Figure
{
private:
	bool hasMoved;
	bool hasRushed;

	void collectBlackPawnMoves(MyVector<String>& moves, const Board& board, size_t currentRow, size_t currentCol) const;
	void collectWhitePawnMoves(MyVector<String>& moves, const Board& board, size_t currentRow, size_t currentCol) const;

public:
	Pawn(const ColorType& color, wchar_t icon, const FigureType& type);

	void setHasMoved(bool hasMoved) override;
	void setHasRushed(bool hasRushed);

	bool getHasMoved() const override;
	bool getHasRushed() const;

	MyVector<String> collectAllMoves(const Board& board, size_t currentRow, size_t currentCol) const override;
};
