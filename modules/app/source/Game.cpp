#include "../include/Game.h"

#include <condition_variable>
#include <iostream>
#include <thread>

#include "../../utils/include/Convertor.h"
#include "../../utils/include/RenderManager.h"

namespace app
{

Game::Game()
	: isGameRunning_(false), field_(), food_(), snake_(), wall_(), score_(0), level_(),
	  currentStateOfGame_(enums::GameState::STARTGAME), currentPressedKey_(enums::KeyboardKeys::W),
	  currentDirection_(enums::Directions::UP), keyManager_()
{}

app::enums::Directions Game::GetDirectionFromPressedKey(const app::enums::KeyboardKeys &key)
{
	switch (key)
	{
		case app::enums::KeyboardKeys::W:
			if (currentDirection_ != app::enums::Directions::DOWN)
				currentDirection_ = app::enums::Directions::UP;
			break;
		case app::enums::KeyboardKeys::S:
			if (currentDirection_ != app::enums::Directions::UP)
				currentDirection_ = app::enums::Directions::DOWN;
			break;
		case app::enums::KeyboardKeys::D:
			if (currentDirection_ != app::enums::Directions::LEFT)
				currentDirection_ = app::enums::Directions::RIGHT;
			break;
		case app::enums::KeyboardKeys::A:
			if (currentDirection_ != app::enums::Directions::RIGHT)
				currentDirection_ = app::enums::Directions::LEFT;
			break;
		default:
			return currentDirection_;
	}
	return currentDirection_;
}

void Game::GenerateNewGame()
{
	std::thread{[&]() {
		field_.ClearMatrix();
		mutexForField_.lock();
		while (field_.CheckCollision(wall_) != enums::CollisionWith::NONE)
		{
			mutexForField_.unlock();
			field_.ClearMatrix();
			wall_.MakeRandomSpawn();
			mutexForField_.lock();
		}
		field_.InsertIntoMatrix(wall_);
		mutexForField_.unlock();
	}}.detach();

	std::thread{[&]() {
		wall_.ClearMatrix();
		mutexForField_.lock();
		wall_.MakeRandomSpawn();
		while (field_.CheckCollision(wall_) != enums::CollisionWith::NONE)
		{
			mutexForField_.unlock();
			wall_.ClearMatrix();
			wall_.MakeRandomSpawn();
			mutexForField_.lock();
		}
		field_.InsertIntoMatrix(wall_);
		mutexForField_.unlock();
	}}.detach();

	std::thread([&]() {
		mutexForField_.lock();
		food_.MakeRandomSpawn();
		while (field_.CheckCollision(food_) != enums::CollisionWith::NONE)
		{
			mutexForField_.unlock();
			food_.MakeRandomSpawn();
			mutexForField_.lock();
		}
		field_.InsertIntoMatrix(food_);
		mutexForField_.unlock();
	}).detach();

	std::thread{[&]() {
		snake_.ClearMatrix();
		mutexForField_.lock();
		snake_.MakeRandomSpawn();
		while (field_.CheckCollision(snake_) != enums::CollisionWith::NONE)
		{
			mutexForField_.unlock();
			snake_.ClearMatrix();
			snake_.MakeRandomSpawn();
			mutexForField_.lock();
		}
		field_.InsertIntoMatrix(snake_);
		mutexForField_.unlock();
	}}.detach();
}

void Game::Start()
{
	isGameRunning_ = true;
	std::cout << "The game is started" << std::endl;

	while (isGameRunning_)
	{
		switch (currentStateOfGame_)
		{
			case enums::GameState::STARTGAME:
			{
				GenerateNewGame();
				std::this_thread::sleep_for(std::chrono::milliseconds(500));
				for (auto sec = constants::WaitSecBeforeGameIsStart; sec != 0; --sec)
				{
					mutexForField_.lock();
					utils::RenderManager::PrintMessage(
							utils::Convertor::GetStateOfGameAsStr(currentStateOfGame_));
					utils::RenderManager::PrintWaiting(sec);
					utils::RenderManager::PrintField(field_);
					mutexForField_.unlock();
					std::this_thread::sleep_for(std::chrono::seconds(1));
					utils::RenderManager::ClearScreen();
				}

				currentStateOfGame_ = app::enums::GameState::GAMEINPROCESS;
				break;
			}
			case enums::GameState::GAMEINPROCESS:
			{
				utils::RenderManager::PrintMessage(
						utils::Convertor::GetStateOfGameAsStr(currentStateOfGame_));
				mutexForField_.lock();
				utils::RenderManager::PrintField(field_);
				utils::RenderManager::PrintScore(score_);
				utils::RenderManager::PrintLevel(level_);
				mutexForField_.unlock();

				std::thread{[&]() {
					currentPressedKey_ = keyManager_.GetPressedKey();
					currentDirection_ = GetDirectionFromPressedKey(currentPressedKey_);
				}}.detach();
				if (currentPressedKey_ == enums::KeyboardKeys::P)
				{
					currentStateOfGame_ = enums::GameState::PAUSEGAME;
					break;
				}
				if (currentPressedKey_ == enums::KeyboardKeys::N)
				{
					Game::Stop();
					break;
				}
				snake_.MakeMove(currentDirection_);
				mutexForField_.lock();
				const auto collisionResult = field_.CheckCollision(snake_);
				mutexForField_.unlock();
				if (collisionResult == enums::CollisionWith::WALL)
				{
					reasonOfFail_ = "Collision with the Wall...";
					currentStateOfGame_ = enums::GameState::FINALGAME;
					break;
				}
				if (collisionResult == enums::CollisionWith::SNAKE)
				{
					reasonOfFail_ = "Collision with the Snake...";
					currentStateOfGame_ = enums::GameState::FINALGAME;
					break;
				}
				if (collisionResult == enums::CollisionWith::FOOD)
				{
					std::thread([&]() {
						food_.MakeRandomSpawn();
						mutexForField_.lock();
						while (field_.CheckCollision(food_) != enums::CollisionWith::NONE)
						{
							mutexForField_.unlock();
							food_.MakeRandomSpawn();
							mutexForField_.lock();
						}
						field_.InsertIntoMatrix(food_);
						mutexForField_.unlock();
					}).detach();
					std::thread{[&]() { snake_.GrowUpNow(); }}.detach();
					std::thread{[&]() {
						score_.IncrementScore();
						level_.CalculateCurrentLevel(score_);
					}}.detach();
				}
				mutexForField_.lock();
				field_.InsertIntoMatrix(snake_);
				mutexForField_.unlock();
				break;
			}
			case enums::GameState::PAUSEGAME:
			{
				utils::RenderManager::PrintMessage(
						utils::Convertor::GetStateOfGameAsStr(currentStateOfGame_));
				mutexForField_.lock();
				utils::RenderManager::PrintField(field_);
				utils::RenderManager::PrintScore(score_);
				utils::RenderManager::PrintLevel(level_);
				utils::RenderManager::PrintReturnToGame();

				currentPressedKey_ = keyManager_.GetPressedKey();
				if (currentPressedKey_ == enums::KeyboardKeys::Y)
				{
					currentStateOfGame_ = enums::GameState::GAMEINPROCESS;
					break;
				}
				if (currentPressedKey_ == enums::KeyboardKeys::N)
				{
					Game::Stop();
					break;
				}
				mutexForField_.unlock();
				break;
			}
			case enums::GameState::FINALGAME:
			{
				utils::RenderManager::PrintMessage(
						utils::Convertor::GetStateOfGameAsStr(currentStateOfGame_));
				mutexForField_.lock();
				utils::RenderManager::PrintField(field_);
				utils::RenderManager::PrintLose(reasonOfFail_);
				utils::RenderManager::PrintScore(score_);
				utils::RenderManager::PrintLevel(level_);
				utils::RenderManager::PrintSuggestNewGame();

				currentPressedKey_ = keyManager_.GetPressedKey();
				if (currentPressedKey_ == enums::KeyboardKeys::Y)
				{
					currentStateOfGame_ = enums::GameState::STARTGAME;
					break;
				}
				if (currentPressedKey_ == enums::KeyboardKeys::N)
				{
					Game::Stop();
					break;
				}
				mutexForField_.unlock();
				break;
			}
		}

		std::this_thread::sleep_for(
				std::chrono::milliseconds(1000 / level_.GetCurrentSpeedOfGame()));
		utils::RenderManager::ClearScreen();
	}
}

void Game::Stop()
{
	isGameRunning_ = false;
	std::cout << "The game is stopped" << std::endl;
}

}// namespace app
