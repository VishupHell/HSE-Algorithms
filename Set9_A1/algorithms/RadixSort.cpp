#include "RadixSort.h"

pair<int, int> MSBRadixSort::apply(vector<string> &data, int len) {
  cnt = 0;
  vector<string> cur(len);
  for (int i = 0; i < len; ++i) {
    cur[i] = data[i];
  }
  auto start = std::chrono::high_resolution_clock::now();
  msb_radix_sort(&cur, 0);
  auto end = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
  return make_pair(duration, cnt);
}

void MSBRadixSort::msb_radix_sort(vector<string> *data, int L) {
  if (data->size() <= 1) {
    return;
  }
  vector<vector<string>*> cur(128);
  for (int i = 0; i < 128; ++i) {
    cur[i] = new vector<string>();
    cur[i]->reserve(data->size());
  }
  vector<string>* R = new vector<string>();
  R->reserve(data->size());
  for (int i = 0; i < data->size(); ++i) {
    if (data->at(i).size() == L) {
      R->push_back(std::move(data->at(i)));
      continue;
    }
    ++cnt;
    cur[data->at(i)[L]]->push_back(std::move(data->at(i)));
  }
  for (int i = 0; i < cur.size(); ++i) {
    msb_radix_sort(cur[i], L + 1);
  }
  int ind = 0;
  for (int i = 0; i < R->size(); ++i) {
    data->at(ind) = std::move(R->at(i));
    ++ind;
  }
  for (int i = 0; i < 128; ++i) {
    for (int j = 0; j < cur[i]->size(); ++j) {
      data->at(ind) = std::move(cur[i]->at(j));
      ++ind;
    }
    delete cur[i];
  }
}

