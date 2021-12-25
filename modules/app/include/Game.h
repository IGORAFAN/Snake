#pragma once

#include "Field.h"
#include "Snake.h"

enum class GameState {
	BREAKGAME,
	STARTGAME,
	GAMEINPROCESS,
	FINALGAME
};

class Game final
{
public:
	Game();
	[[noreturn]] void Start();
	void Stop();

private:
	bool isGameRunning_;
	GameState currentStateOfGame_;
	Field field_;
	Snake snake_;
};
