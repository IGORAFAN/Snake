#include "../include/Snake.h"
#include "../include/Enums.h"

#include "../../utils/include/RandomGenerator.h"
#include "../../utils/include/Types.h"

#include <stdint.h>

namespace app
{

Snake::Snake() : currentDirection_(enums::Directions::UP) { ClearMatrix(); }

void Snake::ClearMatrix()
{
	utils::types::Coordinates pos;
	for (pos.Y = 0; pos.Y != constants::GameSize; ++pos.Y)
	{
		for (pos.X = 0; pos.X != constants::GameSize; ++pos.X)
		{
			matrixOfSnake_.at(pos.Y).at(pos.X) = enums::Objects::NONE;
		}
	}
}

void Snake::MakeRandomSpawnOfSnake()
{
	currentPositionOfHeadOfSnake_ =
			utils::RandomGenerator::GetRandomCoordinates(0, constants::GameSize);
	InsertIntoSnakeMatrix(currentPositionOfHeadOfSnake_, enums::Objects::SNAKE);

	currentPositionOfTailOfSnake_ = currentPositionOfHeadOfSnake_;
	currentPositionOfTailOfSnake_.Y -= 1;
	InsertIntoSnakeMatrix(currentPositionOfTailOfSnake_, enums::Objects::SNAKE);
}

void Snake::MakeMove(const enums::Directions &direction)
{
	currentDirection_ = direction;
	int shiftY = 0;
	int shiftX = 0;
	switch (currentDirection_)
	{
		case enums::Directions::UP:
			shiftY -= 1;
			break;
		case enums::Directions::DOWN:
			shiftY += 1;
			break;
		case enums::Directions::LEFT:
			shiftX -= 1;
			break;
		case enums::Directions::RIGHT:
			shiftX += 1;
			break;
	}
	//! Move the head of the snake
	currentPositionOfHeadOfSnake_.Y += shiftY;
	currentPositionOfHeadOfSnake_.X += shiftX;
	InsertIntoSnakeMatrix(currentPositionOfHeadOfSnake_, enums::Objects::SNAKE);

	//! Move the tail of the snake
	InsertIntoSnakeMatrix(currentPositionOfTailOfSnake_, enums::Objects::NONE);
	currentPositionOfTailOfSnake_.Y += shiftY;
	currentPositionOfTailOfSnake_.X += shiftX;
}

const std::array<std::array<enums::Objects, constants::GameSize>, constants::GameSize> &
Snake::GetMatrixOfSnake() const
{
	return matrixOfSnake_;
}

const utils::types::Coordinates &Snake::GetHeadOfSnake() const
{
	return currentPositionOfHeadOfSnake_;
}

void Snake::InsertIntoSnakeMatrix(const utils::types::Coordinates &pos, const enums::Objects &obj)
{
	matrixOfSnake_.at(pos.Y).at(pos.X) = obj;
}

}// namespace app