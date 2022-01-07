#include "../include/Types.h"

#include <stdint.h>

namespace utils
{

namespace types
{

Coordinates::Coordinates() : X(0), Y(0) {}

Coordinates::Coordinates(int32_t CorX, int32_t CorY) : X(CorX), Y(CorY) {}

}// namespace types

}// namespace utils