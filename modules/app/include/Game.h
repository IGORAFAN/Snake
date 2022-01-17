#pragma once

#include "Enums.h"
#include "Field.h"
#include "Food.h"
#include "Score.h"
#include "Snake.h"
#include "Wall.h"
#include "Level.h"

#include "../../utils/include/KeyboardManager.h"

#include <mutex>
#include <atomic>

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
	std::string reasonOfFail_;
	//! Synchronization to share the resource of class "Field" between threads.
	std::mutex mutexForField_;
	//! Synchronization to share the resource of class "Score" between threads.
	std::mutex mutexForScore_;
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
	Level level_;
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
