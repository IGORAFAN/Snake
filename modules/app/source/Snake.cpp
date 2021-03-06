#include "../include/Snake.h"

#include "../../utils/include/RandomGenerator.h"

namespace app
{

Snake::Snake() : isGrowUpNow_(false), lastDirection_(enums::Directions::UP)
{
	ClearMatrix();
}

Snake::~Snake() noexcept {}

void Snake::ClearMatrix()
{
	while (!snakeElements_.empty()) { snakeElements_.pop(); }
}

void Snake::MakeRandomSpawn()
{
	const auto headOfSnake = utils::RandomGenerator::GetRandomCoordinates(
			2, constants::GameSize - 2);
	auto tailOfSnake = headOfSnake;
	tailOfSnake.Y += 1;
	snakeElements_.emplace(tailOfSnake);
	snakeElements_.emplace(headOfSnake);
	currentHeadOfSnake_ = headOfSnake;
}

void Snake::MakeMove(const enums::Directions &direction)
{
	lastDirection_ = direction;
	int shiftY = 0;
	int shiftX = 0;
	switch (lastDirection_)
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
	else if (newPositionOfHeadOfSnake.Y + shiftY > (constants::GameSize - 1))
	{
		newPositionOfHeadOfSnake.Y += shiftY - constants::GameSize;
		newPositionOfHeadOfSnake.X += shiftX;
	}
	else if (newPositionOfHeadOfSnake.X + shiftX > (constants::GameSize - 1))
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
	if (!isGrowUpNow_) { snakeElements_.pop(); }
	isGrowUpNow_ = false;
}

void Snake::GrowUpNow() { isGrowUpNow_ = true; }

const enums::Directions &Snake::GetLastDirections() const
{
	return lastDirection_;
}

const std::queue<utils::types::Coordinates> &Snake::GetElementsOfSnake() const
{
	return snakeElements_;
}

const utils::types::Coordinates &Snake::GetHeadOfSnake() const
{
	return currentHeadOfSnake_;
}

}// namespace app