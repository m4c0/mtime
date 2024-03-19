#include <stdint.h>
#include <sys/stat.h>

uint64_t mtime_of(const char *filename) {
#if _WIN32
  struct __stat64 s;
  _stat64(filename, &s);
  return s.st_mtime;
#elif __APPLE__
  struct stat s;
  stat(filename, &s);
  uint64_t sec = s.st_mtimespec.tv_sec;
  uint64_t nsec = s.st_mtimespec.tv_nsec;
  return sec * 1000000000ul + nsec;
#else // Assume POSIX
  struct stat s;
  stat(filename, &s);
  uint64_t sec = s.st_mtim.tv_sec;
  uint64_t nsec = s.st_mtim.tv_nsec;
  return sec * 1000000000ul + nsec;
#endif
}
