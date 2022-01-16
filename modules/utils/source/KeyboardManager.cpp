#include "../../app/include/Enums.h"

#include "../include/KeyboardManager.h"

#include <cstdio>

namespace utils
{

app::enums::KeyboardKeys KeyboardManager::GetPressedKey()
{
	app::enums::KeyboardKeys temp;
	switch (getchar())
	{
		case (static_cast<int>('w')):
			temp = app::enums::KeyboardKeys::W;
			break;
		case (static_cast<int>('s')):
			temp = app::enums::KeyboardKeys::S;
			break;
		case (static_cast<int>('d')):
			temp = app::enums::KeyboardKeys::D;
			break;
		case (static_cast<int>('a')):
			temp = app::enums::KeyboardKeys::A;
			break;
		case (static_cast<int>('p')):
			temp = app::enums::KeyboardKeys::P;
			break;
		case (static_cast<int>('n')):
			temp = app::enums::KeyboardKeys::N;
			break;
		case (static_cast<int>('y')):
			temp = app::enums::KeyboardKeys::Y;
			break;
		default:
			return lastPressedKey_;
	}
	lastPressedKey_ = temp;
	return temp;
}

app::enums::KeyboardKeys KeyboardManager::GetLastPressedKey() { return lastPressedKey_; }

}// namespace utils
