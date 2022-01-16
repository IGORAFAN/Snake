#include "../include/Game.h"
#include "../include/Enums.h"

#include <atomic>
#include <condition_variable>
#include <iostream>
#include <thread>

#include "../../utils/include/Convertor.h"
#include "../../utils/include/KeyboardManager.h"
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

void Game::GenerateNewGame()
{
	//std::thread{[&]() {
	field_.ClearMatrix();
	//mutex_.lock();
	while (field_.CheckCollision(wall_) != enums::CollisionWith::NONE) { wall_.MakeRandomSpawn(); }
	field_.InsertIntoMatrix(wall_);
	//mutex_.unlock();
	//}}.detach();

	//std::thread{[&]() {
	wall_.ClearMatrix();
	//mutex_.lock();
	wall_.MakeRandomSpawn();
	while (field_.CheckCollision(wall_) != enums::CollisionWith::NONE) { wall_.MakeRandomSpawn(); }
	field_.InsertIntoMatrix(wall_);
	//mutex_.unlock();
	//}}.detach();

	//std::thread([&]() {
	//mutex_.lock();
	food_.MakeRandomSpawn();
	while (field_.CheckCollision(food_) != enums::CollisionWith::NONE) { food_.MakeRandomSpawn(); }
	field_.InsertIntoMatrix(food_);
	//mutex_.unlock();
	//}).detach();

	//std::thread{[&]() {
	snake_.ClearElementsOfSnake();
	//mutex_.lock();
	snake_.MakeRandomSpawn();
	while (field_.CheckCollision(snake_) != enums::CollisionWith::NONE) { snake_.MakeRandomSpawn(); }
	field_.InsertIntoMatrix(snake_);
	//mutex_.unlock();
	//}}.detach();
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
				utils::RenderManager::PrintMessage(utils::Convertor::GetStateOfGameAsStr(currentStateOfGame_));
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
				break;
			}
			case enums::GameState::FINALGAME:
			{
				utils::RenderManager::PrintMessage(utils::Convertor::GetStateOfGameAsStr(currentStateOfGame_));

				utils::RenderManager::PrintField(field_);
				utils::RenderManager::PrintLose(reasonOfFail, score_);
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
				break;
			}
			case enums::GameState::STARTGAME:
			{
				GenerateNewGame();
				//std::this_thread::sleep_for(std::chrono::milliseconds(500));
				//mutex_.lock();
				for (int sec = constants::WaitSecBeforeGameIsStart; sec > 0; --sec)
				{
					utils::RenderManager::PrintMessage(utils::Convertor::GetStateOfGameAsStr(currentStateOfGame_));
					utils::RenderManager::PrintWaiting(sec);
					utils::RenderManager::PrintField(field_);
					std::this_thread::sleep_for(std::chrono::seconds(1));
					std::system("clear");
				}
				//mutex_.unlock();

				currentStateOfGame_ = app::enums::GameState::GAMEINPROCESS;
				break;
			}
			case enums::GameState::GAMEINPROCESS:
			{
				utils::RenderManager::PrintMessage(utils::Convertor::GetStateOfGameAsStr(currentStateOfGame_));
				utils::RenderManager::PrintField(field_);
				utils::RenderManager::PrintScore(score_);
				utils::RenderManager::PrintLevel(level_);

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
				const auto collisionResult = field_.CheckCollision(snake_);
				if (collisionResult == enums::CollisionWith::WALL)
				{
					reasonOfFail = "Collision with the Wall...";
					currentStateOfGame_ = enums::GameState::FINALGAME;
					break;
				}
				if (collisionResult == enums::CollisionWith::SNAKE)
				{
					reasonOfFail = "Collision with the Snake...";
					currentStateOfGame_ = enums::GameState::FINALGAME;
					break;
				}
				if (collisionResult == enums::CollisionWith::FOOD)
				{
					//std::thread([&]() {
					food_.MakeRandomSpawn();
					//mutex_.lock();
					while (field_.CheckCollision(food_) != enums::CollisionWith::NONE) { food_.MakeRandomSpawn(); }
					field_.InsertIntoMatrix(food_);
					//mutex_.unlock();
					//}).detach();
					std::thread{[&]() { score_.IncrementScore(); }}.detach();
					std::thread{[&]() { snake_.GrowUpNow(); }}.detach();
				}
				//mutex_.lock();
				field_.InsertIntoMatrix(snake_);
				//mutex_.unlock();
				level_.CalculateCurrentLevel(score_);

				break;
			}
		}

		std::this_thread::sleep_for(std::chrono::milliseconds(1000 / level_.GetCurrentSpeedOfGame()));
		std::system("clear");
	}
}

void Game::Stop()
{
	isGameRunning_ = false;
	std::cout << "The game is stopped" << std::endl;
}

}// namespace app
