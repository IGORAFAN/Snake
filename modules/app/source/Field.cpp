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
			matrixOfField_.at(pos.X * pos.Y) = app::enums::Objects::NONE;
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
		}
	}
}

void Field::ClearMatrix() { Field(); }

bool Field::InsertIntoMatrix(const utils::types::Coordinates &pos, const app::enums::Objects &obj)
{
	if (matrixOfField_.at(pos.X * pos.Y) == app::enums::Objects::NONE)
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
			if (coordinatesOfSnake.at(pos.X * pos.Y) == app::enums::Objects::SNAKE)
			{
				matrixOfField_.at(pos.X * pos.Y) = coordinatesOfSnake.at(pos.X * pos.Y);
			}
		}
	}
}

bool Field::InsertIntoMatrix(const Food &food)
{
	const auto coordinatesOfFood = food.GetMatrixOfFood();
	matrixOfField_.at(coordinatesOfFood.X * coordinatesOfFood.Y) = app::enums::Objects::FOOD;

}

void Field::GenerateRandomWall()
{
	const auto firstPoint = utils::RandomGenerator::GetRandomCoordinates(0, constants::GameSize);
}

const app::enums::CollisionWith Field::CheckSnakeCollision(const Snake &snake)
{
	const auto snakePosition = snake.GetMatrixOfSnake();
	utils::types::Coordinates pos;
	for (pos.X = 0; pos.X != constants::GameSize - 1; ++pos.X)
	{
		for (pos.Y = 0; pos.Y != constants::GameSize - 1; ++pos.Y)
		{
			if (snakePosition.at(pos.X * pos.Y) == app::enums::Objects::SNAKE)
			{
				switch (matrixOfField_.at(pos.X * pos.Y))
				{
					case app::enums::Objects::FOOD:
						return app::enums::CollisionWith::FOOD;
					case app::enums::Objects::WALL:
						return app::enums::CollisionWith::WALL;
					case app::enums::Objects::SNAKE:
						return app::enums::CollisionWith::SNAKE;
				}
			}
		}
	}
}

}// namespace app