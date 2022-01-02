#include "../include/Food.h"
#include "../include/Constants.h"

#include "../../utils/include/RandomGenerator.h"

#include <iostream>

namespace app
{

Food::Food()
	: currentPositionOfFood_(constants::GameSize / 2, constants::GameSize / 2),
	  countOfConsumedFood_(0)
{}

utils::types::Coordinates Food::GenerateRandomPositionOfFood()
{
	return utils::RandomGenerator::GetRandomCoordinates(0, constants::GameSize);
}

void Food::IncrementCounterOfConsumedFood() { ++countOfConsumedFood_; }

void Food::PrintCounterOfConsumedFood() const
{
	std::cout << "Score: " << countOfConsumedFood_ << std::endl;
}

const utils::types::Coordinates Food::GetMatrixOfFood() const { return currentPositionOfFood_; }

}// namespace app