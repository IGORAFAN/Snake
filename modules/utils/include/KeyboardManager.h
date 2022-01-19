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
	app::enums::KeyboardKeys GetPressedKeyViaConsole();

	//
	//! Private methods
	//
private:
	static app::enums::KeyboardKeys DefinedKeys(int keyCode);

	//
	//! Private fields
	//
private:
	//!
	std::mutex mutex_;

};

}// namespace utils