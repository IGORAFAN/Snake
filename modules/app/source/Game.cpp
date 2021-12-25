#include <iostream>

#include "../include/Game.h"

Game::Game()
	: isRunning_(false)
{
}
Game::~Game()
{
}

void Game::Start()
{
	isRunning_ = true;
	std::cout << "Start game" << std::endl;

	while (isRunning_)
	{
	}
}

void Game::Stop()
{
	isRunning_ = false;
	std::cout << "Stop game" << std::endl;
}