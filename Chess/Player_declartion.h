#pragma once
#include "String_declaration.h"
#include "Constnats_and_Enums.h"

class Player
{
private:
	String fromInput;
	String toInput;
	ColorType color;

public:

	Player();
	Player(const ColorType& color);
	~Player();

	const ColorType& getColor() const;
	const String& getFromInput() const;
	const String& getToInput() const;

	const String& readFromInput();
	const String& readToInput();

};