module;
#define MTIME_IMPLEMENTATION
#include "mtime.h"

export module mtime;

export namespace mtime {
using t = uint64_t;
constexpr const auto of = mtime_of;
}; // namespace mtime
