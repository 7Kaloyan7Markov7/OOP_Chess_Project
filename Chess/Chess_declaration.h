#pragma once
#include "EventHandler_declaration.h"

class Chess
{
private:
	Board board;
	EventHandler handler;
	Player white;
	Player black;

	Chess();
	~Chess();
	Chess(const Chess&) = delete;
	Chess& operator=(const Chess& other) = delete;

public:
	static Chess& getInstance();
	
	void gameOn();
};