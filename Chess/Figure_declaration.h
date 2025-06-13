#pragma once
#include "String_declaration.h"
#include "Vector.h"
#include "Constnats_and_Enums.h"

class Board;

class Figure
{
protected:
	ColorType color;
	FigureType type;
	wchar_t icon;

public:
	Figure(const ColorType& color, wchar_t icon, const FigureType& type);
	virtual ~Figure();

	wchar_t getIcon() const;
	const ColorType& getColor() const;
	const FigureType& getFigureType() const;

	virtual MyVector<String> collectAllMoves(const Board& board, size_t currentRow, size_t currentCol) const = 0;
	virtual bool getHasMoved() const = 0;
	virtual void setHasMoved(bool hasMoved) = 0;
	
};
