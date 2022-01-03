#include "../../app/include/Enums.h"

#include "../include/KeyboardManager.h"

#include <cstdio>

namespace utils
{

app::enums::KeyboardKeys KeyboardManager::GetPressedKey()
{
	switch (getchar())
	{
		case static_cast<int>('w'):
			return app::enums::KeyboardKeys::W;
		case static_cast<int>('s'):
			return app::enums::KeyboardKeys::S;
		case static_cast<int>('d'):
			return app::enums::KeyboardKeys::D;
		case static_cast<int>('a'):
			return app::enums::KeyboardKeys::A;
		case static_cast<int>('p'):
			return app::enums::KeyboardKeys::P;
	}
}

app::enums::Directions
KeyboardManager::GetDirectionFromPressedKey(const app::enums::KeyboardKeys &key)
{
	switch (key)
	{
		case app::enums::KeyboardKeys::W:
			return app::enums::Directions::UP;
		case app::enums::KeyboardKeys::S:
			return app::enums::Directions::DOWN;
		case app::enums::KeyboardKeys::D:
			return app::enums::Directions::RIGHT;
		case app::enums::KeyboardKeys::A:
			return app::enums::Directions::LEFT;
	}
}

}// namespace utils
