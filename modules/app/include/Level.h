#pragma once

#include <stdint.h>

#include "Score.h"

namespace app
{

class Level
{
	//
	//! Public interface
	//
public:
	//
	Level();
	//!
	size_t GetCurrentSpeedOfGame() const;
	//!
	size_t GetCuurentLevelOfGame() const;
	//!
	void CalculateCurrentLevel(const app::Score& score);

	//
	//! Private methods
	//
private:
	//!
	void CalculateCurrentLevel();

	//
	// Private members
	//
private:
	//!
	size_t currentLevelOfGame_;
	//!
	size_t currentSpeedOfGame_;
};

}// namespace app