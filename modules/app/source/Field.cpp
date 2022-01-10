#include <cstdint>
#include <iostream>
#include <memory>
#include <queue>
#include <stdexcept>

#include "../include/Constants.h"
#include "../include/Field.h"
#include "../include/Snake.h"

#include "../../utils/include/RandomGenerator.h"
#include "../../utils/include/Types.h"

namespace app
{

Field::Field() { ClearMatrix(); }

void Field::PrintCurrentPositions()
{
	utils::types::Coordinates pos;
	for (pos.Y = 0; pos.Y != constants::GameSize; ++pos.Y)
	{
		for (pos.X = 0; pos.X != constants::GameSize; ++pos.X)
		{
			switch (matrixOfField_.at(pos.Y).at(pos.X))
			{
				case app::enums::Objects::NONE:
					std::cout << constants::VoidSymbol;
					break;
				case app::enums::Objects::FOOD:
					std::cout << constants::FoodSymbol;
					break;
				case app::enums::Objects::SNAKE:
					std::cout << constants::SnakeSymbol;
					break;
				case app::enums::Objects::WALL:
					std::cout << constants::WallSymbol;
					break;
			}
			if (pos.X == constants::GameSize - 1) std::cout << std::endl;
		}
	}
}

void Field::ClearMatrix()
{
	utils::types::Coordinates pos;
	for (pos.Y = 0; pos.Y != constants::GameSize; ++pos.Y)
	{
		for (pos.X = 0; pos.X != constants::GameSize; ++pos.X)
		{
			matrixOfField_.at(pos.Y).at(pos.X) = app::enums::Objects::NONE;
		}
	}
}

bool Field::InsertIntoMatrix(const Snake &snake)
{
	utils::types::Coordinates pos;
	for (pos.Y = 0; pos.Y != constants::GameSize; ++pos.Y)
	{
		for (pos.X = 0; pos.X != constants::GameSize; ++pos.X)
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

bool Field::InsertIntoMatrix(const Food &food)
{
	const auto coordinatesOfFood = food.GetPositionOfFood();
	matrixOfField_.at(coordinatesOfFood.Y).at(coordinatesOfFood.X) = app::enums::Objects::FOOD;
}

void Field::GenerateRandomWall()
{
	//const auto firstPoint = utils::RandomGenerator::GetRandomCoordinates(0, constants::GameSize);
}


enums::CollisionWith Field::CheckSnakeCollision(const Snake &snake)
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
	}
	return enums::CollisionWith::NONE;
}

enums::CollisionWith Field::CheckFoodCollision(const Food &food)
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
	}
	return enums::CollisionWith::NONE;
}

}// namespace app