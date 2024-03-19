#include <stdint.h>
#include <sys/stat.h>

uint64_t mtime_of(const char *filename) {
#if _WIN32
  struct __stat64 s {};
  _stat64(filename, &s);
  return s.st_mtime;
#elif __APPLE__
  struct stat s {};
  stat(filename, &s);
  auto mtime = s.st_mtimespec;
  return static_cast<uint64_t>(mtime.tv_sec) * 1000000000ul +
         static_cast<uint64_t>(mtime.tv_nsec);
#else
  struct stat s {};
  stat(filename, &s);
  auto mtime = s.st_mtim;
  return static_cast<uint64_t>(mtime.tv_sec) * 1000000000ul +
         static_cast<uint64_t>(mtime.tv_nsec);
#endif
}
