#pragma once
#include "String_declaration.h"
#include "Vector.h"

class Parser
{
private:

public:

	 String static indexToChess(size_t row, size_t col);
	 MyVector<size_t> static stringToIndex(const String& str);

	Parser();
	~Parser();
};