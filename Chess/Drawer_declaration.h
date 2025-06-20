#pragma once
#include "Board_declaration.h"
#include <windows.h>
#include <io.h>
#include <fcntl.h>

class Drawer
{
private:

public:

	void clearCMD() const;
	void drawBoard(const Board& board) const;
	void stalemateMessage() const;
	void invalidFigureMessage() const;
	void invalidSquareMessage() const;
	void displayTurnColor(bool turn) const;
	void displayCheckmated(bool turn) const;
	void mainMenu() const;
};