#include "isogram.h"

#include <cctype>
using namespace std;

namespace stdp {
  
  bool isalnum_char(char c) {
    return isalnum(static_cast<unsigned char>(c));
  }  

  char tolower_char(char c) {
    return static_cast<char>(tolower(static_cast<unsigned char>(c)));
  }

}  // namespace stdp

namespace isogram {

  int alpha_pos(const char c) {
    return (int) c - (int) 'a';
  }

  bool is_isogram(string str) {
    int alphagram[26] = {};
    for (char& c : str) {
      if (stdp::isalnum_char(c)) {
        char lc = stdp::tolower_char(c);
        int lc_ap = alpha_pos(lc);
        alphagram[lc_ap]++;
        if (alphagram[lc_ap] > 1) {
          return false;
        }
      }
    }
    return true;
  }

}  // namespace isogram
