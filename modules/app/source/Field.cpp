#include <cstdint>
#include <iostream>

#include "../include/Field.h"

Field::Field()
	: snake_()
{
	for (uint8_t y = 0; y != fieldSize_; ++y)
	{
		for (uint8_t x = 0; x != fieldSize_; ++x)
		{
			matrixOfField_[y][x] = voidSymbol_;
		}
	}
}

void Field::PrintCurrentPosition()
{
	for (uint8_t y = 0; y != fieldSize_; ++y)
	{
		for (uint8_t x = 0; x != fieldSize_; ++x)
		{
			std::cout << matrixOfField_[y][x] << std::endl;
		}
	}
}