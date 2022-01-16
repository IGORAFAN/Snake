#pragma once

#include <stdint.h>
#include <string>

namespace app
{

namespace constants
{
static const uint8_t WaitSecBeforeGameIsStart = 3;
static const uint8_t MinGameSpeed = 4;
static const uint8_t MaxGameSpeed = 20;
static const uint8_t GameSize = 16;


static const std::string FoodSymbol{'?'};
static const std::string SnakeSymbol{'*'};
static const std::string VoidSymbol{'.'};
static const std::string WallSymbol{'#'};

}// namespace constants

}// namespace app