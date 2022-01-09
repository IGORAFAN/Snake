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
	void MakeRandomSpawnOfFood();
	//!
	void IncrementCounterOfConsumedFood();
	//!
	void PrintCounterOfConsumedFood() const;
	//!
	const utils::types::Coordinates GetPositionOfFood() const;

private:
	//!
	utils::types::Coordinates currentPositionOfFood_;
	//!
	uint32_t countOfConsumedFood_;
};

}//namespace app
