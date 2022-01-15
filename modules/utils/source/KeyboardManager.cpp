#include "../../app/include/Enums.h"

#include "../include/KeyboardManager.h"

#include <cstdio>

namespace utils
{

void KeyboardManager::GetPressedKey(app::enums::KeyboardKeys &key)
{
	switch (getchar())
	{
		case (static_cast<int>('w')):
			key = app::enums::KeyboardKeys::W;
			break;
		case (static_cast<int>('s')):
			key = app::enums::KeyboardKeys::S;
			break;
		case (static_cast<int>('d')):
			key = app::enums::KeyboardKeys::D;
			break;
		case (static_cast<int>('a')):
			key = app::enums::KeyboardKeys::A;
			break;
		case (static_cast<int>('p')):
			key = app::enums::KeyboardKeys::P;
			break;
		default:
			break;
	}
}

void KeyboardManager::GetDirectionFromPressedKey(const app::enums::KeyboardKeys &key,
												 app::enums::Directions &dir)
{
	switch (key)
	{
		case app::enums::KeyboardKeys::W:
			dir = app::enums::Directions::UP;
			break;
		case app::enums::KeyboardKeys::S:
			dir = app::enums::Directions::DOWN;
			break;
		case app::enums::KeyboardKeys::D:
			dir = app::enums::Directions::RIGHT;
			break;
		case app::enums::KeyboardKeys::A:
			dir = app::enums::Directions::LEFT;
			break;
		default:
			break;
	}
}

}// namespace utils
