#include "../include/Score.h"

namespace app
{

Score::Score() : score_(0) {}

Score::Score(size_t score) : score_(score) {}

void Score::IncrementScore() { ++score_; }

void Score::Set(size_t score) { score_ = score; }

size_t Score::GetScore() const { return score_; }

}// namespace app
