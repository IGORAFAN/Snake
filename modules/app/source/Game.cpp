#include <iostream>
#include <thread>

#include "../include/Game.h"

namespace app
{

Game::Game()
	: isGameRunning_(false), currentStateOfGame_(utils::enums::GameState::PAUSEGAME), field_(),
	  food_(), snake_()
{}

void Game::GenerateNewGame()
{
	field_.ClearMatrix();
	field_.GenerateRandomWall();
	snake_.ClearMatrix();
	snake_.MakeRandomSpawnOfSnake();
	field_.InsertIntoMatrix(food_.GenerateRandomPositionOfFood(), utils::enums::Objects::FOOD);
	field_.InsertIntoMatrix(snake_);
}

[[noreturn]] void Game::Start()
{
	isGameRunning_ = true;
	std::cout << "Start game" << std::endl;

	while (isGameRunning_)
	{
		switch (currentStateOfGame_)
		{
			case utils::enums::GameState::PAUSEGAME:
				//------
				break;
			case utils::enums::GameState::STARTGAME:
				GenerateNewGame();
				field_.PrintCurrentPositions();
				currentStateOfGame_ = utils::enums::GameState::GAMEINPROCESS;
				break;
			case utils::enums::GameState::GAMEINPROCESS: {
				snake_.MakeMove();
				const auto res = field_.CheckSnakeCollision(snake_);
				if (res == utils::enums::CollisionWith::WALL ||
					res == utils::enums::CollisionWith::SNAKE)
				{
					currentStateOfGame_ = utils::enums::GameState::FINALGAME;
				}
				else if (res == utils::enums::CollisionWith::FOOD)
				{
					food_.IncrementCounterOfConsumedFood();
					food_.GenerateRandomPositionOfFood();
					field_.
				}
				field_.PrintCurrentPositions();
				food_.PrintCounterOfConsumedFood();
				break;
			}
			case utils::enums::GameState::FINALGAME:
				//------
				break;
		}

		std::this_thread::sleep_for(std::chrono::milliseconds(500));
		system("cls");
	}
}

void Game::Stop()
{
	isGameRunning_ = false;
	std::cout << "Stop game" << std::endl;
}

}// namespace app
