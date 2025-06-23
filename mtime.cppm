module;
#define MCT_STAT_IMPLEMENTATION
#include "../mct/mct-stat.h"

export module mtime;

export namespace mtime {
using t = uint64_t;
constexpr const auto of = mct_stat_mtime;
}; // namespace mtime
