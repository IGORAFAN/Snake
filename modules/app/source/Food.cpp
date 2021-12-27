#include "../include/Food.h"
#include "../include/Constants.h"

#include "../../utils/include/RandomGenerator.h"
#include "../../utils/include/Types.h"

#include <iostream>
#include <memory>

namespace app
{

Food::Food() : countOfConsumedFood_(0) {}

utils::types::Coordinates Food::GenerateRandomPositionOfFood()
{
	return utils::RandomGenerator::GetRandomCoordinates(0, constants::GameSize);
}

void Food::IncrementCounterOfConsumedFood() { ++countOfConsumedFood_; }

void Food::PrintCounterOfConsumedFood() const
{
	std::cout << "Score: " << countOfConsumedFood_ << std::endl;
}

}// namespace app