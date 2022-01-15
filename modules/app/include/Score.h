#pragma once

#include <cstdlib>

namespace app
{

class Score
{
public:
	//!
	Score();
	//!
	Score(size_t score);
	//!
	void IncrementScore();
	//!
	void Set(size_t score);
	//!
	size_t GetScore() const;

private:
	//!
	size_t score_;
};

}// namespace app
