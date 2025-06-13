#include "Player_declartion.h"

Player::Player() : fromInput(""), toInput("")
{
	this->color = ColorType::WHITE;
}

Player::~Player() = default;

Player::Player(const ColorType& color) : fromInput(""), toInput("")
{
	this->color = color;
}



const ColorType& Player::getColor() const
{
	return this->color;
}

const String& Player::getFromInput() const
{
	return this->fromInput;
}

const String& Player::getToInput() const
{
	return this->toInput;
}



const String& Player::readFromInput()
{
	std::cin >> this->fromInput;
	return this->fromInput;
}

const String& Player::readToInput()
{
	std::cin >> this->toInput;
	return this->toInput;
}