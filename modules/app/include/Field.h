#pragma once

class Field final
{
	//
	// Public interface
	//
public:
	//! Constructor
	Field();
	//!
	bool CheckSnakeCollision(const Snake& snake);
	//!
	void GenerateRandomWalls();
	//!
	void PrintCurrentPosition();

private:
	static constexpr char16_t voidSymbol_ = ' ';
	static constexpr char16_t foodSymbol_ = '?';
	static constexpr char16_t snakeSymbol_ = '*';
	static constexpr uint8_t fieldSize_ = 16;
	char matrixOfField_[fieldSize_][fieldSize_];
};