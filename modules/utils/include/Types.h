#pragma once

#include <stdint.h>

namespace utils
{

namespace types
{

struct Coordinates {
	//
	//! Constructors
	//
public:
	//!
	Coordinates();
	//!
	Coordinates(int32_t CorX, int32_t CorY) : X(CorX), Y(CorY) {}

	//
	//! Public fields
	//
public:
	//! Horizontal coordinate
	int32_t X;
	//! Vertical coordinate
	int32_t Y;
};

}//namespace types

namespace enums
{

enum class Objects
{
	FOOD,
	NONE,
	SNAKE,
	WALL
};

enum class CollisionWith
{
	FOOD,
	NONE,
	SNAKE,
	WALL
};

enum class Directions
{
	UP,
	DOWN,
	RIGHT,
	LEFT
};

enum class KeyboardKeys
{
	W,
	A,
	S,
	D
};

enum class GameState
{
	PAUSEGAME,
	STARTGAME,
	GAMEINPROCESS,
	FINALGAME
};


}// namespace enums

}//namespace utils