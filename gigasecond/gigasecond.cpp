#include "gigasecond.h"

using namespace boost::posix_time;

namespace gigasecond {

  constexpr unsigned long long int operator"" _G(unsigned long long int ulli) {
    return ulli * 1000 * 1000 * 1000;
  }

  const time_duration td_gigasecond = seconds(1_G);

  const ptime advance(const ptime & t) {
    return t + td_gigasecond;
  }

}  // namespace gigasecond
