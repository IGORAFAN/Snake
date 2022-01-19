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
	app::enums::KeyboardKeys GetPressedKeyLinuxPlatform();
	//!
	app::enums::KeyboardKeys GetPressedKeyWindowsPlatform();
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