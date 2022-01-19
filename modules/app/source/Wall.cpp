#include "../include/Wall.h"

#include "../../utils/include/RandomGenerator.h"

#include <array>

namespace app
{

Wall::Wall() { ClearMatrix(); }

Wall::~Wall() {}

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
	const auto point = utils::RandomGenerator::GetRandomCoordinates(
			(constants::GameSize / 4), constants::GameSize - (constants::GameSize / 4) - 1);

	if ((point.Y <= point.X) && (point.Y <= (constants::GameSize / 2) - 1))
	{
		for (size_t iter = point.Y; iter != 0; --iter) { matrixOfWall_.at(iter).at(point.X) = enums::Objects::WALL; }
	}
	if ((point.X <= point.Y) && (point.X <= (constants::GameSize / 2) - 1))
	{
		for (size_t iter = point.X; iter != 0; --iter) { matrixOfWall_.at(point.Y).at(iter) = enums::Objects::WALL; }
	}
	if ((point.Y <= point.X) && ((constants::GameSize / 2) - 1) <= point.Y)
	{
		for (size_t iter = point.Y; iter != (constants::GameSize - 1); ++iter)
		{
			matrixOfWall_.at(iter).at(point.X) = enums::Objects::WALL;
		}
	}
	if ((point.X <= point.Y) && ((constants::GameSize / 2) - 1) <= point.X)
	{
		for (size_t iter = point.X; iter != (constants::GameSize - 1); ++iter)
		{
			matrixOfWall_.at(point.Y).at(iter) = enums::Objects::WALL;
		}
	}
}

const std::array<std::array<enums::Objects, constants::GameSize>, constants::GameSize> &Wall::GetMatrixOfWall() const
{
	return matrixOfWall_;
}

}// namespace app
