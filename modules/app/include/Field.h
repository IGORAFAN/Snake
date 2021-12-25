#pragma once

class Field
{
public:
	Field()
private:
	static const uint8_t fieldSize_ = 16;
	char field_[fieldSize_][fieldSize_];
};