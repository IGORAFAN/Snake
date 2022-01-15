#pragma once

#include "../../utils/include/Types.h"

#include "Constants.h"
#include "Enums.h"


#include <array>

namespace app
{

class Wall
{
	//
	// Public interface
	//
public:
	//! Constructor
	Wall();
	//!
	void GenerateRandomWall();
	//!
	const std::array<std::array<enums::Objects, constants::GameSize>, constants::GameSize> &
	GetMatrixOfWall() const;

	//
	//! Private members
	//
private:
	//!
	std::array<std::array<enums::Objects, constants::GameSize>, constants::GameSize> matrixOfWall_;
};

}// namespace app