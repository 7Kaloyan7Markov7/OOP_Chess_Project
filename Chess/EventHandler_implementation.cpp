#include "EventHandler_declaration.h"

EventHandler::EventHandler()
{
	this->isRunning = true;
	this->isFigureSelected = false;
	this->turn = false;
}

EventHandler::~EventHandler() = default;



bool EventHandler::getTurn() const
{
	return this->turn;
}

bool EventHandler::getIsRunning() const
{
	return this->isRunning;
}

bool EventHandler::getIsFigureSelected() const
{
	return this->isFigureSelected;
}

void EventHandler::setTurn(bool turn)
{
	this->turn = turn;
}

void EventHandler::setFigureSelection(bool isFigureSelected)
{
	this->isFigureSelected = isFigureSelected;
}

void EventHandler::setGameRun(bool isRunning)
{
	this->isRunning = isRunning;
}

bool EventHandler::validateString(const String& input) const
{
	if (input.getLen() != 2) return false;
	if ((input[0] < 'a' || input[0] > 'h')) return false;
	if ((input[1] < '1' || input[1] > '8')) return false;

	return true;
}

bool EventHandler::validateInputFrom(const String& input, const Board& board) const
{
	if (!validateString(input)) return false;
	MyVector<size_t> coordinates = Parser::stringToIndex(input);

	const Figure* tempFigure = board.getFigure(coordinates[0], coordinates[1]);

	if (!tempFigure) return false;
	if ((bool)tempFigure->getColor() != this->getTurn()) return false;

	MyVector<String> moves = tempFigure->collectAllMoves(board, coordinates[0], coordinates[1]);
	if (moves.empty()) return false;

	return true;
}

bool EventHandler::validateInputTo(const String& from, const String& to,const Board& board) const
{
	if (!validateString(to)) return false;
	MyVector<size_t> coordinates = Parser::stringToIndex(from);

	const Figure* tempFigure = board.getFigure(coordinates[0], coordinates[1]);
	MyVector<String> possibleMoves = tempFigure->collectAllMoves(board, coordinates[0], coordinates[1]);

	if (!possibleMoves.size()) return false;

	for (int i = 0; i < possibleMoves.size(); ++i)
	{
		if (possibleMoves[i] == to) return true;
	}

	return false;
}