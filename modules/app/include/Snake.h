#pragma once

#include "../../utils/include/Types.h"

#include "Constants.h"
#include "Enums.h"

#include <memory>
#include <queue>

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
	void ClearElementsOfSnake();
	//!
	void MakeRandomSpawnOfSnake();
	//!
	void MakeMove(const enums::Directions &direction);
	//!
	const enums::Directions& GetCurrentDirections() const;
	//!
	const std::queue<utils::types::Coordinates> &GetElementsOfSnake() const;
	//!
	const utils::types::Coordinates &GetHeadOfSnake() const;


private:
	enums::Directions currentDirection_;
	utils::types::Coordinates currentHeadOfSnake_;
	std::queue<utils::types::Coordinates> snakeElements_;
};

}// namespace app
