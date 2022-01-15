#include "../include/Game.h"

#include <iostream>
#include <thread>

#include "../../utils/include/KeyboardManager.h"
#include "../../utils/include/RenderManager.h"
#include "../../utils/include/ThreadManager.h"

namespace app
{

Game::Game()
	: isGameRunning_(false), currentStateOfGame_(app::enums::GameState::STARTGAME), field_(),
	  food_(), snake_(), wall_()
{}

void Game::GenerateNewGame()
{
	//Clear all matrix of objects after the last game
	std::thread{[&]() { wall_.ClearMatrix(); }}.detach();
	std::thread{[&]() { field_.ClearMatrix(); }}.detach();
	std::thread{[&]() { snake_.ClearElementsOfSnake(); }}.detach();

	//!Create a wall and insert it to the game field.
	wall_.MakeRandomSpawn();
	while (field_.CheckCollision(wall_) != enums::CollisionWith::NONE) { wall_.MakeRandomSpawn(); }
	field_.InsertIntoMatrix(wall_);

	//!Create a snake and insert it to the game field.
	snake_.MakeRandomSpawn();
	while (field_.CheckCollision(snake_) != enums::CollisionWith::NONE)
	{
		snake_.MakeRandomSpawn();
	}
	field_.InsertIntoMatrix(snake_);

	//!Create a food and insert it to the game field.
	food_.MakeRandomSpawn();
	while (field_.CheckCollision(food_) != enums::CollisionWith::NONE) { food_.MakeRandomSpawn(); }
	field_.InsertIntoMatrix(food_);
}

void Game::Start()
{
	isGameRunning_ = true;
	std::cout << "Start the game" << std::endl;

	app::enums::KeyboardKeys pressedKey = enums::KeyboardKeys::NONE;

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
				utils::RenderManager::PrintField(field_);
				currentStateOfGame_ = app::enums::GameState::GAMEINPROCESS;
				break;
			}
			case enums::GameState::GAMEINPROCESS:
			{
				std::cout << "GAMEINPROCESS" << std::endl;

				std::thread{[&]() {
					pressedKey = utils::KeyboardManager::GetPressedKey();
				}}.detach();
				if (pressedKey == enums::KeyboardKeys::P)
				{
					currentStateOfGame_ = enums::GameState::PAUSEGAME;
					break;
				}

				auto direction = utils::KeyboardManager::GetDirectionFromPressedKey(pressedKey);
				if (direction == app::enums::Directions::NONE)
				{
					direction = snake_.GetLastDirections();
				}
				snake_.MakeMove(direction);

				const auto collisionResult = field_.CheckCollision(snake_);
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
				if (collisionResult == enums::CollisionWith::FOOD)
				{
					score_.IncrementScore();
					food_.MakeRandomSpawn();
					snake_.GrowUpNow();
					field_.InsertIntoMatrix(food_);
				}
				field_.InsertIntoMatrix(snake_);
				utils::RenderManager::PrintField(field_);
				utils::RenderManager::PrintScore(score_);
				break;
			}
			case enums::GameState::FINALGAME:
				std::cout << "FINALGAME" << std::endl << std::endl;

				std::cout << "You are lose!" << std::endl;
				utils::RenderManager::PrintScore(score_);
				std::cout << "Do you want to start a new game?" << std::endl
						  << "Yes - press (y)" << std::endl
						  << "No  - press (n)" << std::endl;
				pressedKey = utils::KeyboardManager::GetPressedKey();
				if (pressedKey == enums::KeyboardKeys::Y)
				{
					currentStateOfGame_ = enums::GameState::STARTGAME;
					break;
				}
				else if (pressedKey == enums::KeyboardKeys::N)
				{
					isGameRunning_ = false;
					break;
				}
		}

		std::this_thread::sleep_for(std::chrono::milliseconds(1000 / constants::GameSpeed));
		std::system("clear");
	}
}

void Game::Stop()
{
	isGameRunning_ = false;
	std::cout << "Stop the game" << std::endl;
}

}// namespace app
