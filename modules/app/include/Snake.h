#pragma once

#include "../../utils/include/Types.h"
#include "Constants.h"

#include <memory>

namespace app
{

class Snake final
{
	//
	//! Public interface
	//
public:
	//! Constructor
	Snake();
	//!
	void ClearMatrix();
	//!
	void MakeRandomSpawnOfSnake();
	//!
	void MakeMove();
	//!
	const std::array<utils::enums::Objects, constants::GameSize * constants::GameSize> &
	GetMatrixOfSnake() const;
	//!
	void InsertIntoMatrix(const utils::types::Coordinates &pos,
						  const utils::enums::Objects &obj);

private:
	utils::types::Coordinates currentPositionHeadOfSnake_;
	utils::enums::Directions currentDirection_;
	std::array<utils::enums::Objects, constants::GameSize * constants::GameSize> matrixOfSnake_;
};

}// namespace app
