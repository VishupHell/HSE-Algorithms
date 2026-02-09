#include "RandomStreamGen.h"

RandomStreamGen::RandomStreamGen(size_t sub_counts) {
  this->sub_stream_count = sub_counts;
  for (char a = 'a'; a <= 'z'; a++) {
    alphabet.push_back(a);
  }
  for (char a = 'A'; a <= 'Z'; a++) {
    alphabet.push_back(a);
  }
  for (char a = '0'; a <= '9'; a++) {
    alphabet.push_back(a);
  }
  alphabet.push_back('-');
}

std::string RandomStreamGen::Next() {
  size_t len = distrib_len(gen);
  std::string ans = "";
  for (size_t i = 0; i < len; i++) {
    ans += alphabet[distrib_char(gen)];
  }
  return ans;
}

std::vector<std::string> RandomStreamGen::NextSubStream() {
  std::vector<std::string> ans(sub_stream_count);
  for (size_t i = 0; i < sub_stream_count; i++) {
    ans[i] = Next();
  }
  return ans;
}

size_t RandomStreamGen::GetSubStreamCount() const {
  return sub_stream_count;
}

