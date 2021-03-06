#pragma once

#include "../../app/include/Field.h"
#include "../../app/include/Score.h"
#include "../../app/include/Level.h"

namespace utils
{

class RenderManager
{
public:
	//!
	static void PrintField(const app::Field &field);
	//!
	static void PrintScore(const app::Score &score);
	//!
	static void PrintLevel(const app::Level &level);
	//!
	static void PrintLose(const std::string &reason);
	//!
	static void PrintSuggestNewGame();
	//!
	static void PrintMessage(const std::string& msg);
	//!
	static void PrintReturnToGame();
	//!
	static void PrintWaiting(int sec);
	//!
	static void ClearScreen();
};

}// namespace utils
