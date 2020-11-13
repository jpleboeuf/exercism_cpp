#pragma once

#define EXERCISM_RUN_ALL_TESTS

#include <string>

namespace bob {

  std::string hey(const std::string &);

}  // namespace bob

namespace stdp {  // "std prime"

  inline bool isspace_char(char);
  inline std::string ltrimmed(const std::string &);
  inline std::string rtrimmed(const std::string &);
  inline std::string trimmed(const std::string &);
  inline bool ends_with(const std::string &, const std::string &);
  inline bool isalpha_char(char);
  inline bool contains_alpha(const std::string &);
  inline char to_upper(char);
  inline std::string to_upper(const std::string &);
  inline bool is_upper(const std::string &);

}  // namespace stdp
