#include "../include/Wall.h"
#include "../include/Enums.h"

#include <array>

namespace app
{

Wall::Wall()
{
	for (utils::types::Coordinates pos; pos.Y != constants::GameSize; ++pos.Y)
	{
		for (; pos.X != constants::GameSize; ++pos.X)
		{
			matrixOfWall_.at(pos.Y).at(pos.X) = app::enums::Objects::NONE;
		}
	}
}

void Wall::GenerateRandomWall()
{
	//const auto firstPoint = utils::RandomGenerator::GetRandomCoordinates(0, constants::GameSize);
}

const std::array<std::array<enums::Objects, constants::GameSize>, constants::GameSize> &
Wall::GetMatrixOfWall() const
{
	return matrixOfWall_;
}

}// namespace app
