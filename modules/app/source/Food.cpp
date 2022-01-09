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

void Food::MakeRandomSpawnOfFood()
{
	currentPositionOfFood_ = utils::RandomGenerator::GetRandomCoordinates(0, constants::GameSize);
}

void Food::IncrementCounterOfConsumedFood() { ++countOfConsumedFood_; }

void Food::PrintCounterOfConsumedFood() const
{
	std::cout << "Score: " << countOfConsumedFood_ << std::endl;
}

const utils::types::Coordinates Food::GetPositionOfFood() const { return currentPositionOfFood_; }

}// namespace app