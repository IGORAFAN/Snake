#include "../include/Level.h"
#include "../include/Constants.h"

namespace app
{

Level::Level() : currentLevelOfGame_(1), currentSpeedOfGame_(constants::MinGameSpeed) {}

bool Level::SetCurrentLevelOfGame(size_t level)
{
	if ((0 < level) && (level < constants::MaxLevelOfGame))
	{
		currentLevelOfGame_ = level;
		return true;
	}
	return false;
}

void Level::CalculateCurrentLevel(const app::Score &score)
{
	if (((score.GetScore() % 10) == 0) && (score.GetScore() != 0))
	{
		if (currentLevelOfGame_ < constants::MaxLevelOfGame) { ++currentLevelOfGame_; }
		CalculateCurrentSpeed();
	}
}

void Level::CalculateCurrentSpeed()
{
	currentSpeedOfGame_ = currentLevelOfGame_ * constants::stepOfRiseUpOfDifficulty;
	if (currentSpeedOfGame_ >= constants::MaxGameSpeed)
	{
		currentSpeedOfGame_ = constants::MaxGameSpeed;
	}
}

size_t Level::GetCurrentSpeedOfGame() const { return currentSpeedOfGame_; }

size_t Level::GetCuurentLevelOfGame() const { return currentLevelOfGame_; }

}// namespace app
