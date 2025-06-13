#include "King_declaration.h"

King::King(const ColorType& color, wchar_t icon, const FigureType& type) :Figure(color, icon, type), hasMoved(false)
{
	//std::cout << "King was instanced\n";
};

bool King::getHasMoved() const
{
    return this->hasMoved;
}

void King::setHasMoved(bool hasMoved)
{
    this->hasMoved = hasMoved;
}

void King::findEnemyKing(const Board& board, size_t& enemyKingRow, size_t& enemyKingCol) const
{
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            const Figure* tempFigure = board.getFigure(i, j);
            if (tempFigure && tempFigure->getFigureType() == FigureType::KING && tempFigure->getColor() != this->color)
            {
                enemyKingRow = i;
                enemyKingCol = j;
                return;
            }
        }
    }
}

MyVector<String> King::collectAllMoves(const Board& board, size_t currentRow, size_t currentCol) const
{
    MyVector<String> moves;

    const int offSetRow[8] = { -1,-1,-1,0,1,1,1,0 };
    const int offSetCol[8] = { -1,0,1,1,1,0,-1,-1 };

    size_t enemyKingRow = 0;
    size_t enemyKingCol = 0;
    findEnemyKing(board, enemyKingRow, enemyKingCol);

    for (int i = 0; i < 8; ++i)
    {
        int newRow = (int)currentRow + offSetRow[i];
        int newCol = (int)currentCol + offSetCol[i];

        if (newRow < 0 || newRow >= 8 || newCol < 0 || newCol >= 8)
            continue;

        if (abs(newRow - (int)enemyKingRow) <= 1 && abs(newCol - (int)enemyKingCol) <= 1)
            continue;

        const Figure* targetFigure = board.getFigure(newRow, newCol);
        if (targetFigure && targetFigure->getColor() == this->color)
            continue;

        moves.pushBack(Parser::indexToChess(newRow, newCol));
    }


    return moves;
}