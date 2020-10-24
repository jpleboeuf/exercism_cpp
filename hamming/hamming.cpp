#include "hamming.h"

using namespace std;

namespace hamming {

  int compute(const string & s1, const string & s2) {
    if (s1.length() != s2.length()) {
      throw domain_error("sequences not of equal length");
    }
    vector<bool> hamming_vec;
    transform(s1.begin(), s1.end(), s2.begin(),
	      back_inserter(hamming_vec),
	      [](const char & c1, const char & c2) {
                return c1 == c2;
	      }
              );
    int hamming_sum = count_if(hamming_vec.begin(), hamming_vec.end(),
	                      [](bool hamming_v) {
                                return hamming_v == false;
	                      }
	                      );
    return hamming_sum;
  }

}  // namespace hamming
