#pragma once

#include "../../app/include/Enums.h"

#include <string>

namespace utils
{

class Convertor
{
public:
	//!
	static std::string GetStateOfGameAsStr(app::enums::GameState gameState);
	//!
	static std::string GetPressedKeyAsStr(app::enums::KeyboardKeys key);
};

}// namespace utils
