#include "../include/RandomGenerator.h"

#include <random>
#include <stdint.h>

namespace utils
{

std::pair<uint8_t, uint8_t>
RandomGenerator::GetRandomCoordinates(int32_t rangeFrom, int32_t rangeTo)
{
	const auto x = (rangeFrom + rand() % (rangeTo - rangeFrom));
	const auto y = (rangeFrom + rand() % (rangeTo - rangeFrom));
	return std::make_pair(x, y);
}

}// namespace utils
