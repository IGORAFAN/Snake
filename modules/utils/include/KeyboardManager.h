#pragma once

#include "Types.h"

#include "../../app/include/Enums.h"

namespace utils
{

class KeyboardManager
{
public:
	//!
	static app::enums::KeyboardKeys GetPressedKey();
	//!
	static app::enums::Directions
	GetDirectionFromPressedKey(const app::enums::KeyboardKeys& key);
};

}// namespace utils
