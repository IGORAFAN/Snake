#include <cstdint>
#include <iostream>
#include <memory>

#include "../include/Field.h"

namespace app
{

Field::Field()
{
	for (uint8_t y = 0; y != fieldSize_; ++y)
	{
		for (uint8_t x = 0; x != fieldSize_; ++x)
		{
			matrixOfField_[y][x] = voidSymbol_;
		}
	}
}

void Field::PrintCurrentPositions()
{
	for (uint8_t y = 0; y != fieldSize_; ++y)
	{
		for (uint8_t x = 0; x != fieldSize_; ++x)
		{
			std::cout << matrixOfField_[y][x] << std::endl;
		}
	}
}

void Field::ClearAllPositions()
{
	Field();
}

void Field::InsertIntoField(const std::pair<uint8_t, uint8_t> &coordinates, const char &symbol)
{
	matrixOfField_[coordinates.first][coordinates.second] = symbol;
}

}// namespace app