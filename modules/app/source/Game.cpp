#include <iostream>
#include <thread>

#include "../../utils/include/KeyboardManager.h"
#include "../include/Game.h"

namespace app
{

Game::Game()
	: isGameRunning_(false), currentStateOfGame_(app::enums::GameState::STARTGAME), field_(),
	  food_(), snake_()
{}

void Game::GenerateNewGame()
{
	field_.ClearMatrix();
	field_.GenerateRandomWall();
	snake_.ClearMatrix();
	snake_.MakeRandomSpawnOfSnake();
	field_.InsertIntoMatrix(food_.GenerateRandomPositionOfFood(), app::enums::Objects::FOOD);
	field_.InsertIntoMatrix(snake_);
}

using namespace utils;

[[noreturn]] void Game::Start()
{
	isGameRunning_ = true;
	std::cout << "Start game" << std::endl;

	while (isGameRunning_)
	{
		std::cout << "currentStateOfGame: " << static_cast<int>(currentStateOfGame_) << std::endl;
		switch (currentStateOfGame_)
		{
			case enums::GameState::PAUSEGAME:
				////////////////////////////////////
				break;
			case enums::GameState::STARTGAME:
				GenerateNewGame();
				field_.PrintCurrentPositions();
				currentStateOfGame_ = app::enums::GameState::GAMEINPROCESS;
				break;
			case enums::GameState::GAMEINPROCESS:
			{
				const auto pressedKey = KeyboardManager::GetPressedKey();
				if (pressedKey == enums::KeyboardKeys::P)
				{
					currentStateOfGame_ = enums::GameState::PAUSEGAME;
					break;
				}
				snake_.MakeMove(KeyboardManager::GetDirectionFromPressedKey(pressedKey));
				const auto collisionResult = field_.CheckSnakeCollision(snake_);
				if (collisionResult == enums::CollisionWith::WALL ||
					collisionResult == enums::CollisionWith::SNAKE)
				{
					currentStateOfGame_ = enums::GameState::FINALGAME;
					break;
				}
				else if (collisionResult == enums::CollisionWith::FOOD)
				{
					food_.IncrementCounterOfConsumedFood();
					food_.GenerateRandomPositionOfFood();
					field_.InsertIntoMatrix(food_);
				}
				field_.PrintCurrentPositions();
				food_.PrintCounterOfConsumedFood();
				break;
			}
			case enums::GameState::FINALGAME:
				////////////////////////////////////
				break;
		}

		std::this_thread::sleep_for(std::chrono::milliseconds(500));
		system("clear");
	}
}

void Game::Stop()
{
	isGameRunning_ = false;
	std::cout << "Stop game" << std::endl;
}

}// namespace app
