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
	static utils::types::Coordinates GetRandomCoordinates(int32_t rangeFrom, int32_t rangeTo);
};

}//namespace utils
