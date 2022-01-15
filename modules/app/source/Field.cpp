#include "../include/Field.h"
#include "../include/Constants.h"
#include "../include/Snake.h"

#include <cstdint>
#include <iostream>
#include <memory>
#include <queue>
#include <stdexcept>

#include "../../utils/include/RandomGenerator.h"
#include "../../utils/include/Types.h"

namespace app
{

Field::Field() { ClearMatrix(); }

void Field::ClearMatrix()
{
	for (utils::types::Coordinates pos; pos.Y != constants::GameSize; ++pos.Y)
	{
		for (; pos.X != constants::GameSize; ++pos.X)
		{
			matrixOfField_.at(pos.Y).at(pos.X) = app::enums::Objects::NONE;
		}
	}
}

const std::array<std::array<enums::Objects, constants::GameSize>, constants::GameSize> &
Field::GetMatrixOfFields() const
{
	return matrixOfField_;
}

void Field::InsertIntoMatrix(const Snake &snake)
{
	for (utils::types::Coordinates pos; pos.Y != constants::GameSize; ++pos.Y)
	{
		for (; pos.X != constants::GameSize; ++pos.X)
		{
			if (matrixOfField_.at(pos.Y).at(pos.X) == enums::Objects::SNAKE)
			{
				matrixOfField_.at(pos.Y).at(pos.X) = enums::Objects::NONE;
			}
		}
	}

	auto snakeCoordinatesCopy = snake.GetElementsOfSnake();
	while (!snakeCoordinatesCopy.empty())
	{
		const auto &element = snakeCoordinatesCopy.front();
		matrixOfField_.at(element.Y).at(element.X) = enums::Objects::SNAKE;
		snakeCoordinatesCopy.pop();
	}
}

void Field::InsertIntoMatrix(const Food &food)
{
	const auto coordinatesOfFood = food.GetPositionOfFood();
	matrixOfField_.at(coordinatesOfFood.Y).at(coordinatesOfFood.X) = app::enums::Objects::FOOD;
}

enums::CollisionWith Field::CheckCollision(const Snake &snake)
{
	const auto headOfSnakePosition = snake.GetHeadOfSnake();

	switch (matrixOfField_.at(headOfSnakePosition.Y).at(headOfSnakePosition.X))
	{
		case app::enums::Objects::FOOD:
			return app::enums::CollisionWith::FOOD;
		case app::enums::Objects::WALL:
			return app::enums::CollisionWith::WALL;
		case app::enums::Objects::SNAKE:
			return app::enums::CollisionWith::SNAKE;
		case app::enums::Objects::NONE:
			return app::enums::CollisionWith::NONE;
		default:
			return app::enums::CollisionWith::NONE;
	}
}

enums::CollisionWith Field::CheckCollision(const Food &food)
{
	const auto foodPosition = food.GetPositionOfFood();
	switch (matrixOfField_.at(foodPosition.Y).at(foodPosition.X))
	{
		case app::enums::Objects::FOOD:
			return app::enums::CollisionWith::FOOD;
		case app::enums::Objects::WALL:
			return app::enums::CollisionWith::WALL;
		case app::enums::Objects::SNAKE:
			return app::enums::CollisionWith::SNAKE;
		case app::enums::Objects::NONE:
			return enums::CollisionWith::NONE;
		default:
			return enums::CollisionWith::NONE;
	}
}

}// namespace app