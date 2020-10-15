#include "reverse_string.h"

#include <vector>
#include <numeric>
using namespace std;

namespace reverse_string {

  string reverse_string(const string & str) {
    string str2 = str;
    const int str2_len = str2.length();
    int j = str2_len - 1;
    vector<int> iv(str2_len / 2);
    iota(iv.begin(), iv.end(), 0);
    for (const int & i : iv) {
      swap(str2[i], str2[j--]);
    }
    return str2;
  }
  
}  // namespace reverse_string
