#include "../include/Food.h"
#include "../include/Constants.h"

#include "../../utils/include/RandomGenerator.h"

#include <iostream>

namespace app
{

Food::Food() : currentPositionOfFood_(constants::GameSize / 2, constants::GameSize / 2) {}

void Food::MakeRandomSpawn()
{
	currentPositionOfFood_ =
			utils::RandomGenerator::GetRandomCoordinates(0, constants::GameSize - 1);
}


const utils::types::Coordinates Food::GetPositionOfFood() const { return currentPositionOfFood_; }

}// namespace app