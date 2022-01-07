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
	Coordinates(int32_t CorX, int32_t CorY);

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

}//namespace utils