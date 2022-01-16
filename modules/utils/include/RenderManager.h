#pragma once

#include "../../app/include/Field.h"
#include "../../app/include/Score.h"

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
	static void PrintLose(const std::string &reason, const app::Score &score);
	//!
	static void PrintSuggestNewGame();
};

}// namespace utils
