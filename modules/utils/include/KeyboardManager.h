#pragma once

#include "../../app/include/Enums.h"

#include "Types.h"

namespace utils
{

class KeyboardManager
{
	//
	//! Public Interface
	//
public:
	//!
	app::enums::KeyboardKeys GetPressedKey();
	//!
	app::enums::KeyboardKeys GetLastPressedKey();

	//
	//! Private fields
	//
private:
	//!
	app::enums::KeyboardKeys lastPressedKey_;
};

}// namespace utils