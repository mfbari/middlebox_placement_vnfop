#ifndef MIDDLEBOX_PLACEMENT_SRC_UTIL_H_
#define MIDDLEBOX_PLACEMENT_SRC_UTIL_H_

#include <stdarg.h>
#include <stdio.h>
#include <string>
#include <time.h>

#define ONE_GIG 1000000000ULL
#define STRINGIFY(x) #x
#define TOSTRING(x) STRINGIFY(x)
#define AT __FILE__ ":" TOSTRING(__LINE__) " "

#ifdef DBG
#define DEBUG(...) PrintDebugMessage(AT, __VA_ARGS__)
#else
#define DEBUG(...)
#endif

void PrintDebugMessage(const char* location, const char* fmt_string, ...) {
  va_list args;
  va_start(args, fmt_string);
  std::string str = location;
  str += fmt_string;
  vprintf(str.c_str(), args);
  fflush(stdout);
  va_end(args);
}

inline unsigned long long CurrentTimeNanos() {
  timespec ts;
  clock_gettime(CLOCK_MONOTONIC, &ts);
  return static_cast<unsigned long long>(ts.tv_sec) + 
           static_cast<unsigned long long>(ts.tv_nsec);
}

#endif  // MIDDLEBOX_PLACEMENT_SRC_UTIL_H_