#include "../include/Field.h"

#include <memory>

namespace app
{

Field::Field() { ClearMatrix(); }

Field::~Field() {}

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

void Field::MakeRandomSpawn() {}

const std::array<std::array<enums::Objects, constants::GameSize>, constants::GameSize> &
Field::GetMatrixOfFields() const
{
	return matrixOfField_;
}

void Field::InsertIntoMatrix(const Snake &snake)
{
	//Clearing old positions of the snake on field before set new positions
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

void Field::InsertIntoMatrix(const Food &food)
{
	const auto coordinatesOfFood = food.GetPositionOfFood();
	matrixOfField_.at(coordinatesOfFood.Y).at(coordinatesOfFood.X) = app::enums::Objects::FOOD;
}

void Field::InsertIntoMatrix(const Wall &wall)
{
	const auto &matrixOfWall = wall.GetMatrixOfWall();
	utils::types::Coordinates pos;
	for (pos.Y = 0; pos.Y != constants::GameSize; ++pos.Y)
	{
		for (pos.X = 0; pos.X != constants::GameSize; ++pos.X)
		{
			if (matrixOfWall.at(pos.Y).at(pos.X) == app::enums::Objects::WALL)
			{
				matrixOfField_.at(pos.Y).at(pos.X) = app::enums::Objects::WALL;
			}
		}
	}
}

enums::CollisionWith Field::CheckCollision(const Snake &snake)
{
	const auto headOfSnakePosition = snake.GetHeadOfSnake();
	return CheckCollision(matrixOfField_.at(headOfSnakePosition.Y).at(headOfSnakePosition.X));
}

enums::CollisionWith Field::CheckCollision(const Food &food)
{
	const auto foodPosition = food.GetPositionOfFood();
	return CheckCollision(matrixOfField_.at(foodPosition.Y).at(foodPosition.X));
}

enums::CollisionWith Field::CheckCollision(const Wall &wall)
{
	const auto &matrixOfWall = wall.GetMatrixOfWall();
	utils::types::Coordinates pos;
	for (pos.Y = 0; pos.Y != constants::GameSize; ++pos.Y)
	{
		for (pos.X = 0; pos.X != constants::GameSize; ++pos.X)
		{
			if (matrixOfWall.at(pos.Y).at(pos.X) == enums::Objects::WALL)
			{
				return CheckCollision(matrixOfField_.at(pos.Y).at(pos.X));
			}
		}
	}
	return enums::CollisionWith::NONE;
}

enums::CollisionWith Field::CheckCollision(enums::Objects obj)
{
	switch (obj)
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