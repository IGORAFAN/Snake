#pragma once

#include "Field.h"
#include "Food.h"
#include "Snake.h"

namespace app
{

enum class GameState {
	BREAKGAME,
	STARTGAME,
	GAMEINPROCESS,
	FINALGAME
};



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

private:
	//!
	static constexpr uint8_t gameSize_ = 16;
	//!
	bool isGameRunning_;
	//!
	GameState currentStateOfGame_;
	//!
	Field field_;
	//!
	Food food_;
	//!
	Snake snake_;
};

}// namespace app
