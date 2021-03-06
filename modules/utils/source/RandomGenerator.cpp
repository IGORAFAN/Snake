#include "../include/RandomGenerator.h"

#include <stdint.h>

namespace utils
{

utils::types::Coordinates RandomGenerator::GetRandomCoordinates(int32_t rangeFrom, int32_t rangeTo)
{
	srand(time(NULL));
	const auto x = (rangeFrom + rand() % (rangeTo - rangeFrom));
	const auto y = (rangeFrom + rand() % (rangeTo - rangeFrom));
	return utils::types::Coordinates(x, y);
}

}// namespace utils
