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
	snake_.ClearElementsOfSnake();
	field_.GenerateRandomWall();
	snake_.MakeRandomSpawnOfSnake();
	while (field_.CheckSnakeCollision(snake_) != enums::CollisionWith::NONE)
	{
		snake_.MakeRandomSpawnOfSnake();
	}
	field_.InsertIntoMatrix(snake_);
	food_.MakeRandomSpawnOfFood();
	while (field_.CheckFoodCollision(food_) != enums::CollisionWith::NONE)
	{
		food_.MakeRandomSpawnOfFood();
	}
	field_.InsertIntoMatrix(food_);
}

using namespace utils;

[[noreturn]] void Game::Start()
{
	isGameRunning_ = true;
	std::cout << "Start game" << std::endl;

	while (isGameRunning_)
	{
		switch (currentStateOfGame_)
		{
			case enums::GameState::PAUSEGAME:
			{
				std::cout << "PAUSEGAME" << std::endl;
				////////////////////////////////////
				break;
			}
			case enums::GameState::STARTGAME:
			{
				std::cout << "STARTGAME" << std::endl;
				GenerateNewGame();
				field_.PrintCurrentPositions();
				currentStateOfGame_ = app::enums::GameState::GAMEINPROCESS;
				break;
			}
			case enums::GameState::GAMEINPROCESS:
			{
				std::cout << "GAMEINPROCESS" << std::endl;
				//const auto pressedKey = KeyboardManager::GetPressedKey();
				//if (pressedKey == enums::KeyboardKeys::P)
				//{
				//	currentStateOfGame_ = enums::GameState::PAUSEGAME;
				//	break;
				//}
				snake_.MakeMove(enums::Directions::DOWN);
				//KeyboardManager::GetDirectionFromPressedKey(pressedKey));
				const auto collisionResult = field_.CheckSnakeCollision(snake_);
				if (collisionResult == enums::CollisionWith::WALL)
				{
					std::cout << "Collision with Wall" << std::endl;
					currentStateOfGame_ = enums::GameState::FINALGAME;
					break;
				}
				if (collisionResult == enums::CollisionWith::SNAKE)
				{
					std::cout << "Collision with Snake" << std::endl;
					currentStateOfGame_ = enums::GameState::FINALGAME;
					break;
				}
				else if (collisionResult == enums::CollisionWith::FOOD)
				{
					food_.IncrementCounterOfConsumedFood();
					food_.MakeRandomSpawnOfFood();
					field_.InsertIntoMatrix(food_);
				}
				field_.InsertIntoMatrix(snake_);
				field_.PrintCurrentPositions();
				food_.PrintCounterOfConsumedFood();
				break;
			}
			case enums::GameState::FINALGAME:
				std::cout << "FINALGAME" << std::endl;
				isGameRunning_ = false;
				break;
		}

		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		std::system("clear");
	}
}

void Game::Stop()
{
	isGameRunning_ = false;
	std::cout << "Stop game" << std::endl;
}

}// namespace app
