#pragma once

#include "../../app/include/Enums.h"

#include <string>

namespace utils
{

class Convertor
{
public:
	//!
	static std::string GetStateOfGameAsStr(const app::enums::GameState &gameState);
};

}// namespace utils
