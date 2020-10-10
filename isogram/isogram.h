#pragma once

#define EXERCISM_RUN_ALL_TESTS

#include <string>

namespace isogram {

  bool is_isogram(std::string);

}  // namespace isogram

namespace stdp {  // "std prime"

  bool isalnum_char(char);
  char tolower_char(char);

}  // namespace stdp
