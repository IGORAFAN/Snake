#include "../include/Snake.h"
#include "../include/Enums.h"

#include "../../utils/include/RandomGenerator.h"
#include "../../utils/include/Types.h"

#include <stdint.h>

namespace app
{

Snake::Snake() : currentDirection_(enums::Directions::UP) { ClearElementsOfSnake(); }

void Snake::ClearElementsOfSnake()
{
	while (!snakeElements_.empty()) { snakeElements_.pop(); }
}

void Snake::MakeRandomSpawnOfSnake()
{
	const auto &headOfSnake =
			utils::RandomGenerator::GetRandomCoordinates(0, constants::GameSize - 1);
	auto tailOfSnake = headOfSnake;
	tailOfSnake.Y += 1;
	snakeElements_.emplace(tailOfSnake);
	snakeElements_.emplace(headOfSnake);
	currentHeadOfSnake_ = headOfSnake;
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

	utils::types::Coordinates newPositionOfHeadOfSnake = currentHeadOfSnake_;
	//! Move the head of the snake
	if (newPositionOfHeadOfSnake.Y + shiftY < 0)
	{
		newPositionOfHeadOfSnake.Y += shiftY + constants::GameSize;
		newPositionOfHeadOfSnake.X += shiftX;
	}
	else if (newPositionOfHeadOfSnake.X + shiftX < 0)
	{
		newPositionOfHeadOfSnake.Y += shiftY;
		newPositionOfHeadOfSnake.X += shiftX + constants::GameSize;
	}
	else if (newPositionOfHeadOfSnake.Y + shiftY > constants::GameSize)
	{
		newPositionOfHeadOfSnake.Y += shiftY - constants::GameSize;
		newPositionOfHeadOfSnake.X += shiftX;
	}
	else if (newPositionOfHeadOfSnake.X + shiftX > constants::GameSize)
	{
		newPositionOfHeadOfSnake.Y += shiftY;
		newPositionOfHeadOfSnake.X += shiftX - constants::GameSize;
	}
	else
	{
		newPositionOfHeadOfSnake.Y += shiftY;
		newPositionOfHeadOfSnake.X += shiftX;
	}
	snakeElements_.emplace(newPositionOfHeadOfSnake);
	currentHeadOfSnake_ = newPositionOfHeadOfSnake;

	//! Move the tail of the snake
	snakeElements_.pop();
}

const std::queue<utils::types::Coordinates> &Snake::GetElementsOfSnake() const
{
	return snakeElements_;
}

const utils::types::Coordinates &Snake::GetHeadOfSnake() const { return currentHeadOfSnake_; }

}// namespace app