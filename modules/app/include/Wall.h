#pragma once

#include "../../utils/include/Types.h"

#include "IObject.h"
#include "Constants.h"
#include "Enums.h"


#include <array>

namespace app
{

class Wall : public IObject
{
	//
	// Public interface
	//
public:
	//! Constructor
	Wall();
	//!
	~Wall() noexcept;
	//!
	void ClearMatrix() override;
	//!
	void MakeRandomSpawn() override;
	//!
	const std::array<std::array<enums::Objects, constants::GameSize>, constants::GameSize> &
	GetMatrixOfWall() const;

	//
	//! Private members
	//
private:
	//!
	std::array<std::array<enums::Objects, constants::GameSize>, constants::GameSize> matrixOfWall_;
};

}// namespace app