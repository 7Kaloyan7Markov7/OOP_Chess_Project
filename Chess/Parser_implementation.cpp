#include "Parser_declaration.h"

String Parser::indexToChess(size_t row, size_t col)
{

	String res("st"); //fictive start;

	res[0] = (char)('a' + col);
	res[1] = (char)('8' - row);

	return res;
}

MyVector<size_t> Parser::stringToIndex(const String& str)
{
	MyVector<size_t> coordinates;

	size_t col = str[0] - 'a';             
	size_t row = '8' - str[1];              

	coordinates.pushBack(row);
	coordinates.pushBack(col);

	return coordinates;
}

Parser::Parser() = default;

Parser::~Parser() = default;