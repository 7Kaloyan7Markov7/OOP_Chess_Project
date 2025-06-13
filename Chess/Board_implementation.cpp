#include <iostream>
#include "Board_declaration.h"

void Board::fillPawns()
{
	for (int i = 0; i < 8; ++i)
	{
		board[1][i] = new Pawn(ColorType::BLACK, PAWN, FigureType::PAWN);
		board[6][i] = new Pawn(ColorType::WHITE, PAWN, FigureType::PAWN);
	}
}

void Board::fillRooks()
{
	board[0][0] = new Rook(ColorType::BLACK, BLACK_ROOK, FigureType::ROOK);
	board[0][7] = new Rook(ColorType::BLACK, BLACK_ROOK, FigureType::ROOK);
	board[7][0] = new Rook(ColorType::WHITE, WHITE_ROOK, FigureType::ROOK);
	board[7][7] = new Rook(ColorType::WHITE, WHITE_ROOK, FigureType::ROOK);
}

void Board::fillKnights()
{
	board[0][1] = new Knight(ColorType::BLACK, BLACK_KNIGHT, FigureType::KNIGHT);
	board[0][6] = new Knight(ColorType::BLACK, BLACK_KNIGHT, FigureType::KNIGHT);
	board[7][1] = new Knight(ColorType::WHITE, WHITE_KNIGHT, FigureType::KNIGHT);
	board[7][6] = new Knight(ColorType::WHITE, WHITE_KNIGHT, FigureType::KNIGHT);
}

void Board::fillBishops()
{
	board[0][2] = new Bishop(ColorType::BLACK, BLACK_BISHOP, FigureType::BISHOP);
	board[0][5] = new Bishop(ColorType::BLACK, BLACK_BISHOP, FigureType::BISHOP);
	board[7][2] = new Bishop(ColorType::WHITE, WHITE_BISHOP, FigureType::BISHOP);
	board[7][5] = new Bishop(ColorType::WHITE, WHITE_BISHOP, FigureType::BISHOP);
}

void Board::fillQueens()
{
	board[0][4] = new Queen(ColorType::BLACK, BLACK_QUEEN, FigureType::QUEEM);
	board[7][4] = new Queen(ColorType::WHITE, BLACK_QUEEN, FigureType::QUEEM);
}

void Board::fillKings()
{
	board[0][3] = new King(ColorType::BLACK, BLACK_KING, FigureType::KING);
	board[7][3] = new King(ColorType::WHITE, WHITE_KING, FigureType::KING);
}

void Board::fillEmptySpaces()
{
	for (int i = 2; i < 6; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			board[i][j] = nullptr;
		}
	}
}



Board::Board()
{
	fillEmptySpaces();
	fillPawns();
	fillRooks();
	fillKnights();
	fillBishops();
	fillQueens();
	fillKings();
}

Board::~Board()
{
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			if (board[i][j]) delete board[i][j];
		}
	}
}



void Board::printBoard() const
{
	for (int i = 0; i < 8; ++i)
	{
		std::wcout << (wchar_t)(L'0' + (8 - i)) << L" ";

		for (int j = 0; j < 8; ++j)
		{
			if (board[i][j])
			{
				std::wcout << board[i][j]->getIcon();
			}
			else
			{
				std::wcout << L'.';
			}
			std::wcout << L' ';
		}
		std::wcout << L"\n";
	}

	std::wcout << L"  ";
	for (int i = 0; i < 8; ++i)
	{
		std::wcout << (wchar_t)(L'a' + i) << L' ';
	}
	std::wcout << L"\n";
}

const Figure* Board::getFigure(size_t row, size_t col) const
{
	return board[row][col];
}

void Board::moveCoordinates(size_t prevRow, size_t prevCol, size_t newRow, size_t newCol)
{
	if (board[newRow][newCol]) delete board[newRow][newCol];

	board[newRow][newCol] = board[prevRow][prevCol];
	board[prevRow][prevCol] = nullptr;
}

void Board::move(const String& from, const String& to)
{
	MyVector<size_t> prevCoordinates = Parser::stringToIndex(from);
	MyVector<size_t> newCoordinates = Parser::stringToIndex(to);

	Figure* tempFigure = this->board[prevCoordinates[0]][prevCoordinates[1]];
	moveCoordinates(prevCoordinates[0], prevCoordinates[1], newCoordinates[0], newCoordinates[1]);

	if (tempFigure->getFigureType() == FigureType::KING ||
		tempFigure->getFigureType() == FigureType::ROOK ||
		tempFigure->getFigureType() == FigureType::PAWN)
		tempFigure->setHasMoved(true);

	if (tempFigure->getFigureType() == FigureType::PAWN && abs((int)newCoordinates[0] - (int)prevCoordinates[0]) == 2)
	{
		Pawn* p = dynamic_cast<Pawn*>(tempFigure);
		p->setHasRushed(true);
	}
}