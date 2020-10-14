#pragma once

#define EXERCISM_RUN_ALL_TESTS

namespace leap {

  typedef int year_t;

  bool is_leap_year(const year_t);

}  // namespace leap

namespace stdp {  // "std prime"

  inline bool divbl(const int, const int);

}  // namespace stdp
