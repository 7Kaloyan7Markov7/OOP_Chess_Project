#include "Knight_declaration.h"
#include "Board_declaration.h"
#include "Parser_declaration.h"

Knight::Knight(const ColorType& color, wchar_t icon, const FigureType& type) : Figure(color, icon, type)
{
	//std::cout << "Knight was instanced\n";
}

bool Knight::getHasMoved() const
{
    return false;
}

void Knight::setHasMoved(bool hasMoved)
{

}

MyVector<String> Knight::collectAllMoves(const Board& board, size_t currentRow, size_t currentCol) const
{
    MyVector<String> moves;

    const int offSetRow[8] = {2,2,1,-1,-2,-2,-1,1};
    const int offSetCol[8] = {-1,1,2,2,1,-1,-2,-2};

    for (int i = 0; i < 8; ++i)
    {
        int newRow = (int)currentRow + offSetRow[i];
        int newCol = (int)currentCol + offSetCol[i];

        if (newRow < 0 || newRow >= 8 || newCol < 0 || newCol >= 8)
            continue;

        const Figure* tempFigure = board.getFigure(newRow, newCol);
        if (tempFigure && (tempFigure->getColor() == this->color))
            continue;

        moves.pushBack(Parser::indexToChess(newRow, newCol));
    }

    return moves;
}