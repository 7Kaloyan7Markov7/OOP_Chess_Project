#include "Bishop_declaration.h"
#include "Parser_declaration.h"
#include "Board_declaration.h"

Bishop::Bishop(const ColorType& color, wchar_t icon, const FigureType& type) :Figure(color, icon, type)
{
	//std::cout << "Bishop was instanced\n";
}

bool Bishop::getHasMoved() const
{
    return false;
}

void Bishop::setHasMoved(bool hasMoved)
{
    
}

MyVector<String> Bishop::collectAllMoves(const Board& board, size_t currentRow, size_t currentCol) const
{
    MyVector<String> moves;
    
    for (int i = 1; i < 8; ++i)
    {
        if ((int)currentCol + i >= 8 || (int)currentRow + i >= 8) break;

        const Figure* tempFigure = board.getFigure(currentRow + i, currentCol + i);
        if (!tempFigure)
        {
            moves.pushBack(Parser::indexToChess(currentRow + i, currentCol + i));
            continue;
        }

        if (tempFigure->getColor() == this->color)
        {
            break;
        }

        moves.pushBack(Parser::indexToChess(currentRow + i, currentCol + i));
        break;
    }

    for (int i = 1; i < 8; ++i)
    {
        if ((int)currentCol - i < 0 || (int)currentRow - i < 0)  break;

        const Figure* tempFigure = board.getFigure(currentRow - i, currentCol - i);
        if (!tempFigure)
        {
            moves.pushBack(Parser::indexToChess(currentRow -i, currentCol - i));
            continue;
        }

        if (tempFigure->getColor() == this->color)
        {
            break;
        }

        moves.pushBack(Parser::indexToChess(currentRow - i, currentCol - i));
        break;
    }

    for (int i = 1; i < 8; ++i)
    {
        if ((int)currentRow + i >= 8 || (int)currentCol - i < 0)  break;

        const Figure* tempFigure = board.getFigure(currentRow + i, currentCol - i);
        if (!tempFigure)
        {
            moves.pushBack(Parser::indexToChess(currentRow + i, currentCol - i));
            continue;
        }

        if (tempFigure->getColor() == this->color)
        {
            break;
        }

        moves.pushBack(Parser::indexToChess(currentRow + i, currentCol - i));
        break;
    }

    for (int i = 1; i < 8; ++i)
    {
        if ((int)currentRow - i < 0 || (int)currentCol + i >= 8)  break;

        const Figure* tempFigure = board.getFigure(currentRow - i, currentCol + i);
        if (!tempFigure)
        {
            moves.pushBack(Parser::indexToChess(currentRow - i, currentCol + i));
            continue;
        }

        if (tempFigure->getColor() == this->color)
        {
            break;
        }

        moves.pushBack(Parser::indexToChess(currentRow - i, currentCol + i));
        break;
    }

    return moves;
}