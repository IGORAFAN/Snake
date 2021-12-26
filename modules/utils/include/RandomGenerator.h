#pragma once

#include <memory>

namespace utils
{

class RandomGenerator
{
	//
	// Public interface
	//
public:
	static std::pair<uint8_t, uint8_t> GetRandomCoordinates(int32_t rangeFrom, int32_t rangeTo);
};

}//namespace utils
