#include "../include/Food.h"
#include "../../utils/include/RandomGenerator.h"
#include "../include/Constants.h"

#include <memory>

namespace app
{

Food::Food() {}

std::pair<int, int> Food::GerenateRandomFood()
{
	return utils::RandomGenerator::GetRandomCoordinates(0, constants::gameSize_);
}

}// namespace app