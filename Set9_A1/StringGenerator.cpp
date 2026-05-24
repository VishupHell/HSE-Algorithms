#include "StringGenerator.h"
#include <string>
#include <iostream>


StringGenerator::StringGenerator() : rd(), gen(rd()), distr_for_chars(0, LEN - 1), distr_for_lens(10, 200) {
  chars = {'!', '@', '#', '%', ':', ';', '^', '&', '*', '(', ')', '-', '.'};
  for (int i = 0; i < 26; ++i) {
    chars.push_back('a' + i);
    chars.push_back('A' + i);
  }
  for (int i = 0; i < 10; ++i) {
    chars.push_back(i + '0');
  }
}

string StringGenerator::GetString(int len) {
  string s = "";
  for (int i = 0; i < len; ++i) {
    s += chars[distr_for_chars(gen)];
  }
  return s;
}

vector<string> StringGenerator::GetFirstTypeVector(int len) {
  vector<string> ans(len);
  for (int i = 0; i < len; ++i) {
    ans[i] = GetString(distr_for_lens(gen));
  }
  return ans;
}

vector<string> StringGenerator::GetSecondTypeVector(int len) {
  vector<string> ans(len);
  for (int i = 0; i < len; ++i) {
    ans[i] = GetString(distr_for_lens(gen));
  }
  sort(ans.rbegin(), ans.rend());
  return ans;
}

vector<string> StringGenerator::GetThirdTypeVector(int len) {
  vector<string> ans(len);
  for (int i = 0; i < len; ++i) {
    ans[i] = GetString(distr_for_lens(gen));
  }
  sort(ans.begin(), ans.end());
  std::uniform_int_distribution<> distr(0, len - 1);
  for (int i = 0; i < (len / 10); ++i) {
    int i1 = distr(gen);
    int i2 = distr(gen);
    swap(ans[i1], ans[i2]);
  }
  return ans;
}

vector<string> StringGenerator::GetTestsVectors(int type, int len) {
  if (type == 1) {
    return GetFirstTypeVector(len);
  }
  if (type == 2) {
    return GetSecondTypeVector(len);
  }
  if (type == 3) {
    return GetThirdTypeVector(len);
  }
}
