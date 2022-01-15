#pragma once

#include "../../utils/include/Types.h"

#include <memory>

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
	void MakeRandomSpawn();
	//!
	const utils::types::Coordinates GetPositionOfFood() const;

private:
	//!
	utils::types::Coordinates currentPositionOfFood_;
};

}//namespace app
