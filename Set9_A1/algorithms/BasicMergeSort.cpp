#include "../BasicMergeSort.h"
#include <iostream>
#include <chrono>

pair<int, int> BasicMergeSort::apply(vector<string>& data, int len) {
  cnt = 0;
  vector<string> cur(len);
  for (int i = 0; i < len; ++i) {
    cur[i] = data[i];
  }
  auto start = std::chrono::high_resolution_clock::now();
  merge_sort(cur, 0, len - 1);
  auto end = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
  return make_pair(duration, cnt);
}

bool BasicMergeSort::compare(string &s1, string &s2) {
  for (int i = 0; i < min(s1.size(), s2.size()); ++i) {
    ++cnt;
    if (s1[i] < s2[i]) {
      return false;
    }
    if (s1[i] > s2[i]) {
      return true;
    }
  }
  if (s1.size() <= s2.size()) {
    return false;
  }
  return true;
}



void BasicMergeSort::merge_sort(vector<string>& data, int l, int r) {
  if (r == l) {
    return;
  }
  int m = l + (r - l)/2;
  merge_sort(data, l, m);
  merge_sort(data, m + 1, r);
  int i = l;
  int j = m + 1;
  int ind = 0;
  vector<string> buff(r - l + 1);
  while (i <= m && j <= r) {
    if (!compare(data[i], data[j])) {
      swap(buff[ind], data[i]);
      ++i;
    } else {
      swap(buff[ind], data[j]);
      ++j;
    }
    ++ind;
  }
  while (i <= m) {
    swap(buff[ind], data[i]);
    ++i;
    ++ind;
  }
  while (j <= r) {
    swap(buff[ind], data[j]);
    ++j;
    ++ind;
  }
  for (int i = l; i <= r; ++i) {
    swap(buff[i - l], data[i]);
  }
}