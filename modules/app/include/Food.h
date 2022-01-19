#pragma once

#include "../../utils/include/Types.h"

#include "IObject.h"

#include <memory>

namespace app
{

class Food : public IObject
{
	//
	//! Public interface
	//
public:
	//! Constructor
	Food();
	//!
	void ClearMatrix() override;
	//!
	void MakeRandomSpawn() override;
	//!
	const utils::types::Coordinates GetPositionOfFood() const;

private:
	//!
	utils::types::Coordinates currentPositionOfFood_;
};

}//namespace app
