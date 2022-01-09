//                //
//                //
//                //
//       ?        //
//       *        //
//       ***      //
//         *      //
//         *      //
//    ******      //
//    *           //
//    *           //
//    *           //
//                //
//                //
//                //
//                //

#pragma once

#include "../../utils/include/Types.h"
#include "Constants.h"
#include "Food.h"
#include "Snake.h"

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
	void PrintCurrentPositions();
	//!
	bool InsertIntoMatrix(const Snake &snake);
	//!
	bool InsertIntoMatrix(const Food &food);
	//!
	void GenerateRandomWall();
	//!
	enums::CollisionWith CheckSnakeCollision(const Snake &snake);
	//!
	enums::CollisionWith CheckFoodCollision(const Food &food);

private:
	//!
	std::array<std::array<enums::Objects, constants::GameSize>, constants::GameSize> matrixOfField_;
};

}//namespace app
