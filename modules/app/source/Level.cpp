#include "../include/Level.h"
#include "../include/Constants.h"

namespace app
{

Level::Level() : currentLevelOfGame_(1), currentSpeedOfGame_(constants::MinGameSpeed) {}

void Level::CalculateCurrentLevel(const app::Score &score)
{
	if (((score.GetScore() % 10) == 0) && (score.GetScore() != 0)) { ++currentLevelOfGame_; }
}

void Level::CalculateCurrentLevel()
{
	currentSpeedOfGame_ = currentLevelOfGame_ * 4;
	if (currentSpeedOfGame_ >= constants::MaxGameSpeed) { currentSpeedOfGame_ = constants::MaxGameSpeed; }
}

size_t Level::GetCurrentSpeedOfGame() const { return currentSpeedOfGame_; }

size_t Level::GetCuurentLevelOfGame() const { return currentLevelOfGame_; }

}// namespace app
