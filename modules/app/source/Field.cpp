#include <cstdint>
#include <iostream>
#include <memory>
#include <stdexcept>

#include "../include/Constants.h"
#include "../include/Field.h"
#include "../include/Snake.h"

#include "../../utils/include/RandomGenerator.h"
#include "../../utils/include/Types.h"

namespace app
{

Field::Field()
{
	utils::types::Coordinates pos;
	for (pos.X = 0; pos.X != constants::GameSize - 1; ++pos.X)
	{
		for (pos.Y = 0; pos.Y != constants::GameSize - 1; ++pos.Y)
		{
			matrixOfField_.at(pos.X * pos.Y) = utils::enums::Objects::NONE;
		}
	}
}

void Field::PrintCurrentPositions()
{
	utils::types::Coordinates pos;
	for (pos.X = 0; pos.X != constants::GameSize - 1; ++pos.X)
	{
		for (pos.Y = 0; pos.Y != constants::GameSize - 1; ++pos.Y)
		{
			switch (matrixOfField_.at(pos.X * pos.Y))
			{
				case utils::enums::Objects::NONE:
					std::cout << constants::VoidSymbol;
					break;
				case utils::enums::Objects::FOOD:
					std::cout << constants::FoodSymbol;
					break;
				case utils::enums::Objects::SNAKE:
					std::cout << constants::SnakeSymbol;
					break;
				case utils::enums::Objects::WALL:
					std::cout << constants::WallSymbol;
					break;
			}
		}
	}
}

void Field::ClearMatrix() { Field(); }

bool Field::InsertIntoMatrix(const utils::types::Coordinates &pos, const utils::enums::Objects &obj)
{
	if (matrixOfField_.at(pos.X * pos.Y) == utils::enums::Objects::NONE)
	{
		matrixOfField_.at(pos.X * pos.Y) = obj;
		return true;
	}
	else
	{
		return false;
	}
}

bool Field::InsertIntoMatrix(const Snake &snake)
{
	const auto coordinatesOfSnake = snake.GetMatrixOfSnake();
	utils::types::Coordinates pos;
	for (pos.X = 0; pos.X != constants::GameSize - 1; ++pos.X)
	{
		for (pos.Y = 0; pos.Y != constants::GameSize - 1; ++pos.Y)
		{
			if (coordinatesOfSnake.at(pos.X * pos.Y) == utils::enums::Objects::SNAKE)
			{
				matrixOfField_.at(pos.X * pos.Y) = coordinatesOfSnake.at(pos.X * pos.Y);
			}
		}
	}
}

bool Field::InsertIntoMatrix(const Food &food)
{
	const auto coordinatesOfFood = food.GetMatrixOfFood();
	matrixOfField_.at(coordinatesOfFood.X * coordinatesOfFood.Y) = utils::enums::Objects::FOOD;

}

void Field::GenerateRandomWall()
{
	const auto firstPoint = utils::RandomGenerator::GetRandomCoordinates(0, constants::GameSize);
}

const utils::enums::CollisionWith Field::CheckSnakeCollision(const Snake &snake)
{
	const auto snakePosition = snake.GetMatrixOfSnake();
	utils::types::Coordinates pos;
	for (pos.X = 0; pos.X != constants::GameSize - 1; ++pos.X)
	{
		for (pos.Y = 0; pos.Y != constants::GameSize - 1; ++pos.Y)
		{
			if (snakePosition.at(pos.X * pos.Y) == utils::enums::Objects::SNAKE)
			{
				switch (matrixOfField_.at(pos.X * pos.Y))
				{
					case utils::enums::Objects::FOOD:
						return utils::enums::CollisionWith::FOOD;
					case utils::enums::Objects::WALL:
						return utils::enums::CollisionWith::WALL;
					case utils::enums::Objects::SNAKE:
						return utils::enums::CollisionWith::SNAKE;
				}
			}
		}
	}
}

}// namespace app