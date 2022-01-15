#pragma once

#include "../../app/include/Enums.h"

#include "Types.h"

namespace utils
{

class KeyboardManager
{
public:
	//!
	static void GetPressedKey(app::enums::KeyboardKeys &key);
	//!
	static void GetDirectionFromPressedKey(const app::enums::KeyboardKeys &key,
										   app::enums::Directions &dir);
};

}// namespace utils
