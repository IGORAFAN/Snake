#pragma once

#include <string>
#include <stdint.h>

namespace app
{

namespace constants
{

static const uint8_t GameSize{16};

static const std::string FoodSymbol{'?'};
static const std::string SnakeSymbol{'*'};
static const std::string VoidSymbol{'.'};
static const std::string WallSymbol{'|'};

}// namespace constants

}// namespace app