#include "../include/Convertor.h"

namespace utils
{

std::string Convertor::GetStateOfGameAsStr(app::enums::GameState gameState)
{
	switch (gameState)
	{
		case app::enums::GameState::PAUSEGAME:
			return "STATE: PAUSEGAME";
		case app::enums::GameState::STARTGAME:
			return "STATE: STARTGAME";
		case app::enums::GameState::GAMEINPROCESS:
			return "STATE: GAMEINPROCESS";
		case app::enums::GameState::FINALGAME:
			return "STATE: FINALGAME";
		default:
			return "STATE: UNKNOWN";
	}
}

std::string Convertor::GetPressedKeyAsStr(app::enums::KeyboardKeys key)
{
	switch (key)
	{
		case app::enums::KeyboardKeys::W:
			return "Pressed W";
		case app::enums::KeyboardKeys::A:
			return "Pressed A";
		case app::enums::KeyboardKeys::S:
			return "Pressed S";
		case app::enums::KeyboardKeys::D:
			return "Pressed D";
		case app::enums::KeyboardKeys::Y:
			return "Pressed Y";
		case app::enums::KeyboardKeys::N:
			return "Pressed N";
		case app::enums::KeyboardKeys::P:
			return "Pressed P";
		case app::enums::KeyboardKeys::NONE:
			return "Pressed NONE";
		default:
			return "Pressed UNKNOWN";
	}
}

}// namespace utils
