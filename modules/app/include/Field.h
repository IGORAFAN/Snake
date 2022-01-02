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
#include "Snake.h"
#include "Food.h"

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
	bool InsertIntoMatrix(const utils::types::Coordinates &pos, const utils::enums::Objects &obj);
	//!
	bool InsertIntoMatrix(const Snake &snake);
	//!
	bool InsertIntoMatrix(const Food &food);
	//!
	void GenerateRandomWall();
	//!
	const utils::enums::CollisionWith CheckSnakeCollision(const Snake &snake);

private:
	//!
	std::array<utils::enums::Objects, constants::GameSize * constants::GameSize> matrixOfField_;
};

}//namespace app
