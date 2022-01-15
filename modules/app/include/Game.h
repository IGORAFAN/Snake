#pragma once

#include "Field.h"
#include "Food.h"
#include "Snake.h"
#include "Score.h"
#include "Wall.h"

#include <mutex>

namespace app
{

class Game final
{
	//
	// Public interface
	//
public:
	//!
	Game();
	//!
	void Start();
	//!
	void Stop();

	//
	//! Private methods
	//
private:
	//!
	void GenerateNewGame();

	//
	//! Private members
	//
private:
	//!
	std::mutex mutex_;
	//!
	bool isGameRunning_;
	//!
	app::enums::GameState currentStateOfGame_;
	//!
	Field field_;
	//!
	Food food_;
	//!
	Snake snake_;
	//!
	Wall wall_;
	//!
	Score score_;
};



}// namespace app
