#pragma once

#include "../../app/include/Enums.h"

#include "Types.h"
#include <mutex>

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
	app::enums::KeyboardKeys GetPressedKeyV2();
	//!
	app::enums::KeyboardKeys GetLastPressedKey();

	//
	//! Private fields
	//
private:
	std::mutex mutex_;
	//!
	app::enums::KeyboardKeys lastPressedKey_;
};

}// namespace utils