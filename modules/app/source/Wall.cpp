#include "../include/Wall.h"

#include <array>

namespace app
{

Wall::Wall() { ClearMatrix(); }

void Wall::ClearMatrix()
{
	utils::types::Coordinates pos;
	for (pos.Y = 0; pos.Y != constants::GameSize; ++pos.Y)
	{
		for (pos.X = 0; pos.X != constants::GameSize; ++pos.X)
		{
			matrixOfWall_.at(pos.Y).at(pos.X) = app::enums::Objects::NONE;
		}
	}
}

void Wall::MakeRandomSpawn()
{
	//const auto firstPoint = utils::RandomGenerator::GetRandomCoordinates(0, constants::GameSize);
}

const std::array<std::array<enums::Objects, constants::GameSize>, constants::GameSize> &
Wall::GetMatrixOfWall() const
{
	return matrixOfWall_;
}

}// namespace app
