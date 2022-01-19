#include "../include/RenderManager.h"

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
			if (pos.X == (app::constants::GameSize - 1)) std::cout << std::endl;
		}
	}
}

void RenderManager::PrintScore(const app::Score &score) { std::cout << "Score: " << score.GetScore() << std::endl; }

void RenderManager::PrintLevel(const app::Level &level)
{
	std::cout << "Level: " << level.GetCuurentLevelOfGame() << std::endl;
}

void RenderManager::PrintLose(const std::string &reason)
{
	std::cout << "YOU LOSE!" << std::endl;
	std::cout << "Reason: " << reason << std::endl;
}

void RenderManager::PrintSuggestNewGame()
{
	std::cout << std::endl << "Do you want to start a new game?" << std::endl << "Press: Yes (y) or Exit (n)" << std::endl;
}

void RenderManager::PrintMessage(const std::string &msg) { std::cout << msg << std::endl; }


void RenderManager::PrintReturnToGame()
{
	std::cout << std::endl << "Do you want return to the game?" << std::endl << "Press: Yes (y) or Exit (n)" << std::endl;
}

void RenderManager::PrintWaiting(int sec)
{
	std::cout << "Get ready!!! " << sec << "sec" << std::endl;
}
}// namespace utils
