#include "../include/Snake.h"
#include "../../utils/include/RandomGenerator.h"
#include "../../utils/include/Types.h"

#include <stdint.h>

namespace app
{

Snake::Snake() : currentDirection_(utils::enums::Directions::UP)
{
	utils::types::Coordinates pos;
	for (pos.X = 0; pos.X != constants::GameSize - 1; ++pos.X)
	{
		for (pos.Y = 0; pos.Y != constants::GameSize - 1; ++pos.Y)
		{
			matrixOfSnake_.at(pos.X * pos.Y) = utils::enums::Objects::NONE;
		}
	}
}

void Snake::ClearMatrix() { Snake(); }

void Snake::MakeRandomSpawnOfSnake()
{
	currentPositionHeadOfSnake_ =
			utils::RandomGenerator::GetRandomCoordinates(0, constants::GameSize);
	InsertIntoMatrix(currentPositionHeadOfSnake_, utils::enums::Objects::SNAKE);
}

void Snake::MakeMove()
{
	switch (currentDirection_)
	{
		case utils::enums::Directions::UP:
			currentPositionHeadOfSnake_.Y = currentPositionHeadOfSnake_.Y - 1;
			break;
		case utils::enums::Directions::DOWN:
			currentPositionHeadOfSnake_.Y = currentPositionHeadOfSnake_.Y + 1;
			break;
		case utils::enums::Directions::LEFT:
			currentPositionHeadOfSnake_.X = currentPositionHeadOfSnake_.X - 1;
			break;
		case utils::enums::Directions::RIGHT:
			currentPositionHeadOfSnake_.X = currentPositionHeadOfSnake_.X + 1;
			break;
	}
}

const std::array<utils::enums::Objects, constants::GameSize * constants::GameSize> &Snake::GetMatrixOfSnake() const
{
	return matrixOfSnake_;
}

void Snake::InsertIntoMatrix(const utils::types::Coordinates &pos, const utils::enums::Objects& obj)
{
	matrixOfSnake_.at(pos.X * pos.Y) = obj;
}

}// namespace app