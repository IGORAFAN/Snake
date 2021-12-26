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
	bool CheckSnakeCollision();
	//!
	void ClearAllPositions();
	//!
	void PrintCurrentPositions();
	//!
	void InsertIntoField(const std::pair<uint8_t, uint8_t> &coordinates, const char &symbol);


	//
	// Private methods
	//
private:
	//!
	void GenerateRandomWalls();


private:
	static constexpr char16_t voidSymbol_ = ' ';
	static constexpr char16_t foodSymbol_ = '?';
	static constexpr char16_t snakeSymbol_ = '*';
	static constexpr uint8_t fieldSize_ = 16;
	char matrixOfField_[fieldSize_][fieldSize_];
};

}//namespace app
