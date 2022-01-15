#include "../include/RenderManager.h"
#include "../../app/include/Constants.h"

#include <array>
#include <iostream>

namespace utils
{


void RenderManager::PrintField(const app::Field &field)
{
	const auto &matrixOfField = field.GetMatrixOfFields();
	utils::types::Coordinates pos;
	for (pos.Y = 0; pos.Y != app::constants::GameSize; ++pos.Y)
	{
		for (pos.X = 0; pos.X != app::constants::GameSize; ++pos.X)
		{
			switch (matrixOfField.at(pos.Y).at(pos.X))
			{
				case app::enums::Objects::NONE:
					std::cout << app::constants::VoidSymbol;
					break;
				case app::enums::Objects::FOOD:
					std::cout << app::constants::FoodSymbol;
					break;
				case app::enums::Objects::SNAKE:
					std::cout << app::constants::SnakeSymbol;
					break;
				case app::enums::Objects::WALL:
					std::cout << app::constants::WallSymbol;
					break;
			}
			if (pos.X == app::constants::GameSize - 1) std::cout << std::endl;
		}
	}
}

void RenderManager::PrintScore(const app::Score &score)
{
	std::cout << "Your score: " << score.GetScore() << std::endl;
}


}// namespace utils
