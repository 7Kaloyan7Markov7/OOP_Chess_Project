#pragma once
#include "Figure_declaration.h"

class Knight : public Figure
{
public:
	Knight(const ColorType& color, wchar_t icon, const FigureType& type);

	bool getHasMoved() const override;

	void setHasMoved(bool hasMoved) override;

	MyVector<String> collectAllMoves(const Board& board, size_t currentRow, size_t currentCol) const override;
};
