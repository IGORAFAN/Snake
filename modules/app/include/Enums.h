#pragma once

namespace app
{

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
	LEFT,
	NONE
};

enum class KeyboardKeys
{
	A,
	D,
	N,
	P,
	S,
	W,
	Y,
	NONE
};

enum class GameState
{
	PAUSEGAME,
	STARTGAME,
	GAMEINPROCESS,
	FINALGAME
};

}// namespace enums

}// namespace app
