#pragma once

#include "Field.h"
#include "Food.h"
#include "Enums.h"
#include "Score.h"
#include "Snake.h"
#include "Wall.h"

#include "../../utils/include/KeyboardManager.h"

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
	//!
	app::enums::Directions GetDirectionFromPressedKey(const app::enums::KeyboardKeys &key);

	//
	//! Private members
	//
private:
	//!
	bool isGameRunning_;
	//!
	std::string reasonOfFail;
	//!
	std::mutex mutex_;
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
	//!
	enums::GameState currentStateOfGame_;
	//!
	enums::KeyboardKeys currentPressedKey_;
	//!
	enums::Directions currentDirection_;
	//!
	utils::KeyboardManager keyManager_;
};


}// namespace app
