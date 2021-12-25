#include <iostream>
#include <thread>

#include "../include/Game.h"

Game::Game()
	: isGameRunning_(false),
	  currentStateOfGame_(GameState::BREAKGAME),
	  field_(),
	  snake_()
{}

[[noreturn]] void Game::Start()
{
	isGameRunning_ = true;
	std::cout << "Start game" << std::endl;

	while (isGameRunning_)
	{
		switch (currentStateOfGame_)
		{
			case GameState::BREAKGAME:;
				break;
			case GameState::STARTGAME:
					snake_.MakeRandomSpawn();
					field_.PrintCurrentPosition();
					currentStateOfGame_ = GameState::GAMEINPROCESS;
				break;
			case GameState::GAMEINPROCESS:
				field_.PrintCurrentPosition();
				break;
			case GameState::FINALGAME:;
				break;
			default:
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