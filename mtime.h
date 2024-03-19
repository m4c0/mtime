// mtime.h
// single-file C wrapper for retrieving the modification time of a file by
// Eduardo Costa
//
// LICENSE - see end of file
//
// to create implementation, add
// #define MTIME_IMPLEMENTATION
// in one C/CPP file that includes this file
//

#ifdef __cplusplus
extern "C" {
#endif
#include <stdint.h>

/// Returns a platform-dependent timestamp of the file or zero if there was any
/// error (eg: file not found).
///
/// This should be fine to check when a file was modified, but it is not
/// portable between platforms. Therefore, if you read this in a Linux server,
/// you can't compare with a value read in a Windows client.
///
/// This API is suited for same-machine comparisons, like checking if a file was
/// modified after reading it.
extern uint64_t mtime_of(const char *filename);
#ifdef __cplusplus
}
#endif

#ifdef MTIME_IMPLEMENTATION
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

#endif // MTIME_IMPLEMENTATION

// MIT License
//
// Copyright (c) 2024 Eduardo Costa
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
