#include "Figure_declaration.h"

const ColorType& Figure::getColor() const
{
	return this->color;
}

Figure::Figure(const ColorType& color, wchar_t icon,const FigureType& type)
{
	this->color = color;
	this->icon = icon;
	this->type = type;
}

const FigureType& Figure::getFigureType() const
{
	return this->type;
}

wchar_t Figure::getIcon() const
{
	return this->icon;
}

Figure::~Figure() = default;