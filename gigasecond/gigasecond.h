#pragma once

#define EXERCISM_RUN_ALL_TESTS

#include "boost/date_time/posix_time/posix_time.hpp"

namespace gigasecond {

  const boost::posix_time::ptime advance(const boost::posix_time::ptime &);
  
}  // namespace gigasecond
