#pragma once

#define EXERCISM_RUN_ALL_TESTS

#include <string>
#include <stdexcept>
#include <vector>
#include <algorithm>  // std::transform, std::count_if
#include <iterator>   // std::back_inserter

namespace hamming {

  int compute(const std::string &, const std::string &);

}  // namespace hamming
