#include "../include/Types.h"

#include <stdint.h>

namespace utils::types
{

Coordinates::Coordinates() : X(0), Y(0) {}

Coordinates::Coordinates(int32_t CorX, int32_t CorY) : X(CorX), Y(CorY) {}

}// namespace utils::types