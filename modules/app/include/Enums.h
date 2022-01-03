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
	LEFT
};

enum class KeyboardKeys
{
	W,
	A,
	S,
	D,
	P
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
