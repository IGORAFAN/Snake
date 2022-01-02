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
	utils::types::Coordinates GenerateRandomPositionOfFood();
	//!
	void IncrementCounterOfConsumedFood();
	//!
	void PrintCounterOfConsumedFood() const;
	//!
	const utils::types::Coordinates GetMatrixOfFood() const;

private:
	//!
	utils::types::Coordinates currentPositionOfFood_;
	//!
	uint32_t countOfConsumedFood_;
};

}//namespace app
