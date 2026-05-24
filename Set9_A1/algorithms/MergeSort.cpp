#include "../MergeSort.h"
#include <iostream>
#include <chrono>

pair<int, int> MergeSort::apply(vector<string>& data, int len) {
  cnt = 0;
  vector<pair<string, int> > cur(len);
  for (int i = 0; i < len; ++i) {
    cur[i].second = 0;
    cur[i].first = data[i];
  }
  auto start = std::chrono::high_resolution_clock::now();
  merge_sort(cur, 0, len - 1);
  auto end = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
  return make_pair(duration, cnt);
}

pair<bool, int> MergeSort::LCPCompare(string& s1, string& s2, int k) {
  for (int i = k; i < min(s1.size(), s2.size()); ++i) {
    ++cnt;
    if (s1[i] < s2[i]) {
      return make_pair(false, i);
    }
    if (s1[i] > s2[i]) {
      return make_pair(true, i);
    }
  }
  if (s1.size() < s2.size()) {
    return make_pair(false, s1.size());
  }
  return make_pair(true, s2.size());
}

void MergeSort::merge_sort(vector<pair<string, int> >& data, int l, int r) {
  if (r == l) {
    return;
  }
  int m = l + (r - l)/2;
  merge_sort(data, l, m);
  merge_sort(data, m + 1, r);
  int i = l;
  int j = m + 1;
  int ind = 0;
  vector<pair<string, int> > buff(r - l + 1);
  while (i <= m && j <= r) {
    if (data[i].second > data[j].second) {
      swap(buff[ind], data[i]);
      ++i;
    } else if (data[i].second < data[j].second) {
      swap(buff[ind], data[j]);
      ++j;
    }
    else {
      auto&& ans = LCPCompare(data[i].first, data[j].first, data[i].second);
      if (!ans.first) {
        swap(buff[ind], data[i]);
        ++i;
        data[j].second = ans.second;
      } else {
        swap(buff[ind], data[j]);
        ++j;
        data[i].second = ans.second;
      }
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