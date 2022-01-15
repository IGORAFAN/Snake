
#pragma once

#include "../../utils/include/Types.h"

#include "Constants.h"
#include "Food.h"
#include "Snake.h"
#include "Wall.h"

namespace app
{

class Field final
{
	//
	//! Public interface
	//
public:
	//! Constructor
	Field();
	//!
	void ClearMatrix();
	//!
	const std::array<std::array<enums::Objects, constants::GameSize>, constants::GameSize> &
	GetMatrixOfFields() const;
	//!
	void InsertIntoMatrix(const Food &food);
	//!
	void InsertIntoMatrix(const Snake &snake);
	//!
	void InsertIntoMatrix(const Wall &wall);
	//!
	enums::CollisionWith CheckCollision(const Snake &snake);
	//!
	enums::CollisionWith CheckCollision(const Food &food);
	//!
	enums::CollisionWith CheckCollision(const Wall &wall);

private:
	//!
	std::array<std::array<enums::Objects, constants::GameSize>, constants::GameSize> matrixOfField_;
};

}//namespace app
