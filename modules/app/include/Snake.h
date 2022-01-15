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
	void MakeRandomSpawn();
	//!
	void MakeMove(const enums::Directions &direction);
	//!
	void GrowUpNow();
	//!
	const enums::Directions&GetLastDirections() const;
	//!
	const std::queue<utils::types::Coordinates> &GetElementsOfSnake() const;
	//!
	const utils::types::Coordinates &GetHeadOfSnake() const;


private:
	bool isGrowUpNow_;
	enums::Directions lastDirection_;
	utils::types::Coordinates currentHeadOfSnake_;
	std::queue<utils::types::Coordinates> snakeElements_;
};

}// namespace app
