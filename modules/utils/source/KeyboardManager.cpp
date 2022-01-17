#include "../../app/include/Enums.h"

#include "../include/KeyboardManager.h"

#include <cstdio>
#include <iostream>

namespace utils
{

app::enums::KeyboardKeys KeyboardManager::GetPressedKey()
{
	std::lock_guard<std::mutex> lock{mutex_};
	const auto inputSignal = std::cin.get();
	std::cin.clear();
	switch (inputSignal)
	{
		case 'w':
			lastPressedKey_ = app::enums::KeyboardKeys::W;
			break;
		case 'a':
			lastPressedKey_ = app::enums::KeyboardKeys::A;
			break;
		case 's':
			lastPressedKey_ = app::enums::KeyboardKeys::S;
			break;
		case 'd':
			lastPressedKey_ = app::enums::KeyboardKeys::D;
			break;
		case 'p':
			lastPressedKey_ = app::enums::KeyboardKeys::P;
			break;
		case 'n':
			lastPressedKey_ = app::enums::KeyboardKeys::N;
			break;
		case 'y':
			lastPressedKey_ = app::enums::KeyboardKeys::Y;
			break;
		default:
			return app::enums::KeyboardKeys::NONE;
	}
	return lastPressedKey_;
}

app::enums::KeyboardKeys KeyboardManager::GetPressedKeyV2()
{
	std::lock_guard<std::mutex> lock{mutex_};
	app::enums::KeyboardKeys temp;
	const auto inputSignal = getchar();
	switch (inputSignal)
	{
		case (static_cast<int>('y')):
			temp = app::enums::KeyboardKeys::Y;
			break;
		case (static_cast<int>('n')):
			temp = app::enums::KeyboardKeys::N;
			break;
		case (static_cast<int>('w')):
			temp = app::enums::KeyboardKeys::W;
			break;
		case (static_cast<int>('a')):
			temp = app::enums::KeyboardKeys::A;
			break;
		case (static_cast<int>('s')):
			temp = app::enums::KeyboardKeys::S;
			break;
		case (static_cast<int>('d')):
			temp = app::enums::KeyboardKeys::D;
			break;
		case (static_cast<int>('p')):
			temp = app::enums::KeyboardKeys::P;
			break;
		default:
			return lastPressedKey_;
	}
	lastPressedKey_ = temp;
	return temp;
}

app::enums::KeyboardKeys KeyboardManager::GetLastPressedKey() { return lastPressedKey_; }

}// namespace utils
