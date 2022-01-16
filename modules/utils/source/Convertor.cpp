#include "../include/Convertor.h"

namespace utils
{

std::string Convertor::GetStateOfGameAsStr(const app::enums::GameState &gameState)
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

}// namespace utils
