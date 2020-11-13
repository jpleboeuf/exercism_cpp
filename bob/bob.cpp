#include "bob.h"

#include <cctype>     // isspace, isalpha
#include <algorithm>  // all_of, find_if
#include <map>
//#include <iostream>
using namespace std;

namespace stdp {

  inline bool isspace_char(char c) {
    return isspace(static_cast<unsigned char>(c));
  }

  inline string ltrimmed(const string & s) {
    string s_cp = const_cast<string &>(s);
    s_cp.erase(s_cp.begin(),
               find_if_not(s_cp.begin(), s_cp.end(), [](unsigned char c) {
                   return stdp::isspace_char(c);
                 })
              );
    return s_cp;
  }
  inline string rtrimmed(const string & s) {
    string s_cp = const_cast<string &>(s);
    s_cp.erase(find_if_not(s_cp.rbegin(), s_cp.rend(), [](unsigned char c) {
                   return stdp::isspace_char(c);
                 }).base(),
               s_cp.end()
              );
    return s_cp;
  }
  inline string trimmed(const string & s) {
    return rtrimmed(ltrimmed(s));
  }

  inline bool ends_with(const string & s, const string & ending) {
    if (s.length() >= ending.length()) {
      return s.compare(s.length() - ending.length(), ending.length(), ending) == 0;
    } else {
      return false;
    }
  }

  inline bool isalpha_char(char c) {
    return isalpha(static_cast<unsigned char>(c));
  }

  inline bool contains_alpha(const string & s) {
    return find_if(s.begin(), s.end(), [](unsigned char c) {
               return stdp::isalpha_char(c);
             }) != s.end();
  }

  inline char to_upper(char c) {
    return static_cast<char>(toupper(static_cast<unsigned char>(c)));
  }

  inline string to_upper(const string & s) {
    string s_upper;
    for (const char & c : s) {
      char c_upper = stdp::to_upper(c);
      s_upper += c_upper;
    }
    return s_upper;
  }
  inline bool is_upper(const string & s) {
    return stdp::to_upper(s) == s;
  }

}  // namespace stdp

namespace bob {

  #if defined __has_attribute
  #  if __has_attribute(flag_enum)
  #    define ATTR__FLAG_ENUM __attribute__((flag_enum))
  #  endif
  #endif
  enum class ATTR__FLAG_ENUM MsgKind: uint8_t {
      mkA = (1 << 1),  // Asking      10 = 2
      mkY = (1 << 2),  // Yelling    100 = 4
      mkN = (1 << 3),  // Nothing   1000 = 8
    };
  constexpr enum MsgKind operator | (const enum MsgKind lhsValue, const enum MsgKind rhsValue) {
    return static_cast<MsgKind>(static_cast<uint8_t>(lhsValue) | static_cast<uint8_t>(rhsValue));
  }
  constexpr enum MsgKind & operator |= (enum MsgKind & lhsValue, const enum MsgKind rhsValue) {
    return lhsValue = lhsValue | rhsValue;
  }

  MsgKind msg_kind(const string & msg) {
    MsgKind msg_kind = static_cast<MsgKind>(0);
    //cout << "msg_kind (mk0) = (" << +static_cast<underlying_type<MsgKind>::type>(msg_kind) << ")" << endl;
    string msg_trimmed = stdp::trimmed(msg);
    if (msg_trimmed.empty()) {
      msg_kind |= MsgKind::mkN;
    } else {
      if (stdp::ends_with(msg_trimmed, "?")) {
        msg_kind |= MsgKind::mkA;
      }
      if (stdp::contains_alpha(msg_trimmed) and stdp::is_upper(msg_trimmed)) {
        msg_kind |= MsgKind::mkY;
      }
    }
    return msg_kind;
  }

  string hey(const string & message) {
    const map<string, string> reply_to = {
        { "asking_question",  "Sure." },
        { "yelling",          "Whoa, chill out!" },
        { "yelling_question", "Calm down, I know what I'm doing!" },
        { "saying_nothing",   "Fine. Be that way!" },
        { "default",          "Whatever." }
      };
    switch (msg_kind(message)) {
      case MsgKind::mkA:
        return reply_to.at("asking_question");
      case MsgKind::mkY:
        return reply_to.at("yelling");
      case MsgKind::mkA | MsgKind::mkY:
        return reply_to.at("yelling_question");
      case MsgKind::mkN:
        return reply_to.at("saying_nothing");
      default:
        return reply_to.at("default");
    }
  }

}  // namespace bob
