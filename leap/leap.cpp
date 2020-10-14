#include "leap.h"

namespace stdp {

  inline bool divbl(const int a, const int b) {
    return a % b == 0;
  }

}

namespace leap {

  bool is_leap_year(const int y) {
    return stdp::divbl(y, 4) and (not stdp::divbl(y, 100) or stdp::divbl(y, 400));
  }

}  // namespace leap
