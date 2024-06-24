#pragma leco tool
import mtime;
import silog;

void test(const char *file) {
  auto m = mtime::of(file);
  silog::log(silog::info, "Modification time of [%s]: %llu", file, m);
}

int main() {
  test("poc.cpp");
  test("mtime.h");
  test("non-existent");
  test(".");
}
