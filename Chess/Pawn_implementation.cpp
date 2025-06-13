#include "Pawn_declaration.h"
#include "Parser_declaration.h"
#include "Board_declaration.h"

Pawn::Pawn(const ColorType& color, wchar_t icon, const FigureType& type) :Figure(color, icon, type), hasMoved(false), hasRushed(false)
{

};

bool Pawn::getHasMoved() const
{
    return this->hasMoved;
}

bool Pawn::getHasRushed() const
{
    return this->hasRushed;
}

void Pawn::setHasMoved(bool hasMoved)
{
    this->hasMoved = hasMoved;
}

void Pawn::setHasRushed(bool hasRushed)
{
    this->hasRushed = hasRushed;
}

void Pawn::collectBlackPawnMoves(MyVector<String>& moves, const Board& board, size_t currentRow, size_t currentCol) const
{
    if (currentRow + 1 < 8 && !board.getFigure(currentRow + 1, currentCol))
    {
        moves.pushBack(Parser::indexToChess(currentRow + 1, currentCol));

        if (!this->hasMoved && !this->hasRushed &&!board.getFigure(currentRow + 2, currentCol)) 
        {
            moves.pushBack(Parser::indexToChess(currentRow + 2, currentCol));
        }
    }

    if (currentRow + 1 < 8 && currentCol > 0)
    {
        const Figure* leftFigure = board.getFigure(currentRow + 1, currentCol - 1);
        if (leftFigure && leftFigure->getColor() != this->getColor())
        {
            moves.pushBack(Parser::indexToChess(currentRow + 1, currentCol - 1));
        }
    }

    if (currentRow + 1 < 8 && currentCol < 7)
    {
        const Figure* rightFigure = board.getFigure(currentRow + 1, currentCol + 1);
        if (rightFigure && rightFigure->getColor() != this->getColor())
        {
            moves.pushBack(Parser::indexToChess(currentRow + 1, currentCol + 1));
        }
    }

    if (currentRow == 4 && currentCol < 7)
    {
        const Figure* rightFigure = board.getFigure(currentRow, currentCol + 1);

        if (rightFigure && (rightFigure->getFigureType() == FigureType::PAWN) && (rightFigure->getColor() != this->getColor()))
        {
            const Pawn* p = dynamic_cast<const Pawn*>(rightFigure);
            if (p && p->getHasRushed() && !board.getFigure(currentRow + 1, currentCol + 1))
            {
                moves.pushBack(Parser::indexToChess(currentRow + 1, currentCol + 1));
            }
        }
    }

    if (currentRow == 4 && currentCol > 0)
    {
        const Figure* leftFigure = board.getFigure(currentRow, currentCol - 1);

        if (leftFigure && (leftFigure->getFigureType() == FigureType::PAWN) && (leftFigure->getColor() != this->getColor()))
        {
            const Pawn* p = dynamic_cast<const Pawn*>(leftFigure);
            if (p && p->getHasRushed() && !board.getFigure(currentRow + 1, currentCol - 1))
            {
                moves.pushBack(Parser::indexToChess(currentRow + 1, currentCol - 1));
            }
        }
    }

}

void Pawn::collectWhitePawnMoves(MyVector<String>& moves, const Board& board, size_t currentRow, size_t currentCol) const
{

    if (currentRow - 1 >= 0 && !board.getFigure(currentRow - 1, currentCol))
    {
        moves.pushBack(Parser::indexToChess(currentRow - 1, currentCol));

        if (!this->hasMoved && !this->hasRushed && !board.getFigure(currentRow - 2, currentCol))
        {
            moves.pushBack(Parser::indexToChess(currentRow - 2, currentCol));
        }
    }

    if (currentRow - 1 >= 0 && currentCol > 0)
    {
        const Figure* leftFigure = board.getFigure(currentRow - 1, currentCol - 1);

        if (leftFigure && leftFigure->getColor() != this->getColor())
        {
            moves.pushBack(Parser::indexToChess(currentRow - 1, currentCol - 1));
        }
    }

    if (currentRow - 1 >= 0 && currentCol < 7)
    {
        const Figure* rightRight = board.getFigure(currentRow - 1, currentCol + 1);

        if (rightRight && rightRight->getColor() != this->getColor())
        {
            moves.pushBack(Parser::indexToChess(currentRow - 1, currentCol + 1));
        }
    }

    if (currentRow == 3 && currentCol < 7)
    {
        const Figure* rightFigure = board.getFigure(currentRow, currentCol + 1);

        if (rightFigure && (rightFigure->getFigureType() == FigureType::PAWN) && (rightFigure->getColor() != this->getColor()))
        {
            const Pawn* p = dynamic_cast<const Pawn*>(rightFigure);
            if (p && p->getHasRushed() && !board.getFigure(currentRow - 1, currentCol + 1))
            {
                moves.pushBack(Parser::indexToChess(currentRow - 1, currentCol + 1));
            }
        }
    }

    if (currentRow == 3 && currentCol > 0)
    {
        const Figure* leftFigure = board.getFigure(currentRow, currentCol - 1);

        if (leftFigure && (leftFigure->getFigureType() == FigureType::PAWN) && (leftFigure->getColor() != this->getColor()))
        {
            const Pawn* p = dynamic_cast<const Pawn*>(leftFigure);
            if (p && p->getHasRushed() && !board.getFigure(currentRow - 1, currentCol - 1))
            {
                moves.pushBack(Parser::indexToChess(currentRow - 1, currentCol - 1));
            }
        }
    }
}

MyVector<String> Pawn::collectAllMoves(const Board& board, size_t currentRow, size_t currentCol) const
{
    MyVector<String> moves;

    switch (this->getColor())
    {
    case ColorType::WHITE: collectWhitePawnMoves(moves, board, currentRow, currentCol);
        break;
    case ColorType::BLACK: collectBlackPawnMoves(moves, board, currentRow, currentCol);
        break;
    default: break;
    }

    return moves;
}