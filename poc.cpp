#pragma leco tool
import silog;

#define MTIME_IMPLEMENTATION
#define MTIME_ERROR(x) silog::log(silog::error, "Error: %s", (x))
#include "mtime.h"

void test(const char *file) {
  auto m = mtime_of(file);
  silog::log(silog::info, "Modification time of [%s]: %llu", file, m);
}

int main() {
  test("poc.cpp");
  test("mtime.h");
  test("non-existent");
  test(".");
}
