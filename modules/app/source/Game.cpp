#include "../include/Game.h"
#include "../include/Enums.h"

#include <iostream>
#include <thread>

#include "../../utils/include/KeyboardManager.h"
#include "../../utils/include/RenderManager.h"

namespace app
{

Game::Game()
	: isGameRunning_(false), field_(), food_(), snake_(), wall_(), score_(0),
	  currentStateOfGame_(enums::GameState::STARTGAME), currentPressedKey_(enums::KeyboardKeys::W),
	  currentDirection_(enums::Directions::UP), keyManager_()
{}

void Game::GenerateNewGame()
{
	std::thread{[&]() {
		wall_.ClearMatrix();
		wall_.MakeRandomSpawn();
		mutex_.lock();
		while (field_.CheckCollision(wall_) != enums::CollisionWith::NONE) { wall_.MakeRandomSpawn(); }
		field_.InsertIntoMatrix(wall_);
		mutex_.unlock();
	}}.detach();

	std::thread{[&]() {
		field_.ClearMatrix();
		mutex_.lock();
		while (field_.CheckCollision(wall_) != enums::CollisionWith::NONE) { wall_.MakeRandomSpawn(); }
		field_.InsertIntoMatrix(wall_);
		mutex_.unlock();
	}}.detach();

	std::thread{[&]() {
		snake_.ClearElementsOfSnake();
		snake_.MakeRandomSpawn();
		mutex_.lock();
		while (field_.CheckCollision(snake_) != enums::CollisionWith::NONE) { snake_.MakeRandomSpawn(); }
		field_.InsertIntoMatrix(snake_);
		mutex_.unlock();
	}}.detach();

	std::thread([&]() {
		food_.MakeRandomSpawn();
		mutex_.lock();
		while (field_.CheckCollision(food_) != enums::CollisionWith::NONE) { food_.MakeRandomSpawn(); }
		field_.InsertIntoMatrix(food_);
		mutex_.unlock();
	}).detach();
}

app::enums::Directions Game::GetDirectionFromPressedKey(const app::enums::KeyboardKeys &key)
{
	switch (key)
	{
		case app::enums::KeyboardKeys::W:
			if (currentDirection_ != app::enums::Directions::DOWN) currentDirection_ = app::enums::Directions::UP;
			break;
		case app::enums::KeyboardKeys::S:
			if (currentDirection_ != app::enums::Directions::UP) currentDirection_ = app::enums::Directions::DOWN;
			break;
		case app::enums::KeyboardKeys::D:
			if (currentDirection_ != app::enums::Directions::LEFT) currentDirection_ = app::enums::Directions::RIGHT;
			break;
		case app::enums::KeyboardKeys::A:
			if (currentDirection_ != app::enums::Directions::RIGHT) currentDirection_ = app::enums::Directions::LEFT;
			break;
		default:
			return currentDirection_;
	}
	return currentDirection_;
}

void Game::Start()
{
	isGameRunning_ = true;
	std::cout << "The game is started" << std::endl;

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
				std::cout << "STATE: STARTGAME" << std::endl;

				GenerateNewGame();
				utils::RenderManager::PrintField(field_);
				utils::RenderManager::PrintScore(score_);
				currentStateOfGame_ = app::enums::GameState::GAMEINPROCESS;
				break;
			}
			case enums::GameState::GAMEINPROCESS:
			{
				std::cout << "STATE: GAMEINPROCESS" << std::endl;

				utils::RenderManager::PrintField(field_);
				utils::RenderManager::PrintScore(score_);

				std::thread{[&]() {
					currentPressedKey_ = keyManager_.GetPressedKey();
					currentDirection_ = GetDirectionFromPressedKey(currentPressedKey_);
				}}.detach();
				std::this_thread::sleep_for(std::chrono::milliseconds(10));
				if (currentPressedKey_ == enums::KeyboardKeys::P)
				{
					currentStateOfGame_ = enums::GameState::PAUSEGAME;
					break;
				}
				if (currentPressedKey_ == enums::KeyboardKeys::N)
				{
					isGameRunning_ = false;
					break;
				}
				snake_.MakeMove(currentDirection_);
				const auto collisionResult = field_.CheckCollision(snake_);
				if (collisionResult == enums::CollisionWith::WALL)
				{
					reasonOfFail = "Collision with Wall...";
					currentStateOfGame_ = enums::GameState::FINALGAME;
					break;
				}
				if (collisionResult == enums::CollisionWith::SNAKE)
				{
					reasonOfFail = "Collision with Snake...";
					currentStateOfGame_ = enums::GameState::FINALGAME;
					break;
				}
				if (collisionResult == enums::CollisionWith::FOOD)
				{
					std::thread{[&]() { score_.IncrementScore(); }}.detach();
					std::thread{[&]() { snake_.GrowUpNow(); }}.detach();
					std::thread([&]() {
						food_.MakeRandomSpawn();
						mutex_.lock();
						while (field_.CheckCollision(food_) != enums::CollisionWith::NONE) { food_.MakeRandomSpawn(); }
						field_.InsertIntoMatrix(food_);
						mutex_.unlock();
					}).detach();
				}
				field_.InsertIntoMatrix(snake_);
				break;
			}
			case enums::GameState::FINALGAME:
				std::cout << "STATE: FINALGAME" << std::endl;

				utils::RenderManager::PrintField(field_);
				utils::RenderManager::PrintLose(reasonOfFail, score_);
				utils::RenderManager::PrintSuggestNewGame();

				currentPressedKey_ = keyManager_.GetPressedKey();
				if (currentPressedKey_ == enums::KeyboardKeys::Y)
				{
					currentStateOfGame_ = enums::GameState::STARTGAME;
					break;
				}
				else if (currentPressedKey_ == enums::KeyboardKeys::N)
				{
					Game::Stop();
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
	std::cout << "The game is stopped" << std::endl;
}

}// namespace app
