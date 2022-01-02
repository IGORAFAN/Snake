#include "../include/KeyboardManager.h"
#include <cstdio>

namespace utils
{

utils::enums::KeyboardKeys KeyboardManager::GetPressedKey()
{
	switch (getchar())
	{
		case 119:
			return utils::enums::KeyboardKeys::W;
		case 115:
			return utils::enums::KeyboardKeys::S;
		case 100:
			return utils::enums::KeyboardKeys::D;
		case 97:
			return utils::enums::KeyboardKeys::A;
	}
}

utils::enums::Directions
KeyboardManager::GetDirectionFromPressedKeys(const utils::enums::KeyboardKeys &key)
{
	switch (key)
	{
		case utils::enums::KeyboardKeys::W:
			return utils::enums::Directions::UP;
		case utils::enums::KeyboardKeys::S:
			return utils::enums::Directions::DOWN;
		case utils::enums::KeyboardKeys::D:
			return utils::enums::Directions::RIGHT;
		case utils::enums::KeyboardKeys::A:
			return utils::enums::Directions::LEFT;
	}
}

}// namespace utils
