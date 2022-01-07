#pragma once

#include "Field.h"
#include "Food.h"
#include "Snake.h"

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
	[[noreturn]] void Start();
	//!
	void Stop();

	//
	//! Private methods
	//
private:
	//!
	void GenerateNewGame();

private:
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
};

}// namespace app
