#pragma once

namespace app
{

class IObject
{
public:
	//! Assign the object new random coordinates in a game space
	virtual void MakeRandomSpawn() = 0;
	//! Clear memory of the location of object points in a game space
	virtual void ClearMatrix() = 0;
	//!
	virtual ~IObject() {}
};

}// namespace app
