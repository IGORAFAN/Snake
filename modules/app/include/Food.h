#pragma once

namespace app
{

class Food
{
	//
	//! Public interface
	//
public:
	//! Constructor
	Food();
	//!
	std::pair<int, int> GerenateRandomFood();
};

}//namespace app
