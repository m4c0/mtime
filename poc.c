#include <stdio.h>

#define MTIME_IMPLEMENTATION
#define MTIME_ERROR(x) puts
#include "mtime.h"

void test(const char * file){
  uint64_t m = mtime_of(file);
  printf("Modification time of [%s]: %llu\n", file, m);
}

int main() {
  test("poc.cpp");
  test("mtime.h");
  test("non-existent");
  test(".");
  return 0;
}
