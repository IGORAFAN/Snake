#include "../../app/include/Enums.h"

#include "../include/KeyboardManager.h"

#include <cstdio>

#if (defined(_WIN32) || defined(_WIN64))
#include <Windows.h>
#include <conio.h>
#elif (defined(LINUX) || defined(__linux__))
#include <termios.h>
#include <unistd.h>
#endif

namespace utils
{

app::enums::KeyboardKeys KeyboardManager::GetPressedKey()
{

#if (defined(LINUX) || defined(__linux__))
	std::lock_guard<std::mutex> lock{mutex_};
	struct termios oldt, newt;
	int inputSignal;
	tcgetattr(STDIN_FILENO, &oldt);
	newt = oldt;
	newt.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &newt);
	inputSignal = getchar();
	tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
#elif (defined(_WIN32) || defined(_WIN64))
	if (_kbhit()) { const auto inputSignal = _getch(); }
#endif
	return DefinedKeys(inputSignal);
}

app::enums::KeyboardKeys KeyboardManager::GetPressedKeyViaConsole()
{
	std::lock_guard<std::mutex> lock{mutex_};
	const auto inputSignal = getchar();
	return DefinedKeys(inputSignal);
}

app::enums::KeyboardKeys KeyboardManager::DefinedKeys(int keyCode)
{
	switch (keyCode)
	{
		case (static_cast<int>('w')):
			return app::enums::KeyboardKeys::W;
		case (static_cast<int>('a')):
			return app::enums::KeyboardKeys::A;
		case (static_cast<int>('s')):
			return app::enums::KeyboardKeys::S;
		case (static_cast<int>('d')):
			return app::enums::KeyboardKeys::D;
		case (static_cast<int>('p')):
			return app::enums::KeyboardKeys::P;
		case (static_cast<int>('n')):
			return app::enums::KeyboardKeys::N;
		case (static_cast<int>('y')):
			return app::enums::KeyboardKeys::Y;
		default:
			return app::enums::KeyboardKeys::NONE;
	}
}

}// namespace utils
