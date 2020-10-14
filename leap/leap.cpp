#include "leap.h"

namespace stdp {

  inline bool divbl(const int a, const int b) {
    return a % b == 0;
  }

}  // namespace stdp

namespace leap {

  bool is_leap_year(const year_t y) {
    auto is_y_div_by = [y](year_t d) { return stdp::divbl(y, d); };
    return is_y_div_by(4) and (not is_y_div_by(100) or is_y_div_by(400));
  }

}  // namespace leap
