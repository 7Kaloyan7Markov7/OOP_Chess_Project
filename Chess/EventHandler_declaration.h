#pragma once
#include "Board_declaration.h"
#include "Player_declartion.h"

class EventHandler
{
private:
	bool turn; // White = 0, Blakc = 1;
	bool isFigureSelected;
	bool isRunning;

public:
	EventHandler();
	~EventHandler();

	bool getTurn() const;
	bool getIsRunning() const;
	bool getIsFigureSelected() const;
	void setTurn(bool turn);
	void setFigureSelection(bool isSelected);
	void setGameRun(bool isRunning);

	bool validateString(const String& input) const;
	bool validateInputFrom(const String& input, const Board& board) const;
	bool validateInputTo(const String& from, const String& input, const Board& board) const;
};
