#pragma once

#include "Constants.h"
#include "Enums.h"

#include "../../utils/include/Types.h"

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
	void MakeMove(const enums::Directions &direction);
	//!
	const std::array<std::array<enums::Objects, constants::GameSize>, constants::GameSize> &
	GetMatrixOfSnake() const;
	//!
	const utils::types::Coordinates &GetHeadOfSnake() const;

private:
	//!
	void InsertIntoSnakeMatrix(const utils::types::Coordinates &pos, const enums::Objects &obj);

private:
	utils::types::Coordinates currentPositionOfHeadOfSnake_;
	utils::types::Coordinates currentPositionOfTailOfSnake_;
	enums::Directions currentDirection_;
	std::array<std::array<enums::Objects, constants::GameSize>, constants::GameSize> matrixOfSnake_;
};

}// namespace app
