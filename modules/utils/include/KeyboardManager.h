#pragma once
#include "Types.h"

namespace utils
{

class KeyboardManager
{
public:
	//!
	static utils::enums::KeyboardKeys GetPressedKey();
	//!
	static utils::enums::Directions GetDirectionFromPressedKeys(const utils::enums::KeyboardKeys& key);
};

}// namespace utils
