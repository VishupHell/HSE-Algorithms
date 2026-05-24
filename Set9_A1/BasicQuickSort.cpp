#include "BasicQuickSort.h"
#include <chrono>

BasicQuickSort::BasicQuickSort() : rd(), gen(rd()) {}


pair<int, int> BasicQuickSort::apply(vector<string> &data, int len) {
    cnt = 0;
  vector<string> cur(len);
  for (int i = 0; i < len; ++i) {
    cur[i] = data[i];
  }
  auto start = std::chrono::high_resolution_clock::now();
  quick_sort(&cur);
  auto end = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
  return make_pair(duration, cnt);
}

int BasicQuickSort::compare(string &s1, string &s2) {
    for (int i = 0; i < min(s1.size(), s2.size()); ++i) {
        ++cnt;
        if (s1[i] < s2[i]) {
            return -1;
        }
        if (s1[i] > s2[i]) {
            return 1;
        }
    }
    if (s1.size() < s2.size()) {
        return -1;
    }
    if (s1.size() > s2.size()) {
        return 1;
    }
    return 0;
}

void BasicQuickSort::quick_sort(vector<string> *data) {
  if (data->size() <= 1) {
        return;
    }
    std::uniform_int_distribution<> distr(0, data->size() - 1);
    int pivot = distr(gen);
    vector<string>* less = new vector<string>(); less->reserve(data->size());
    vector<string>* eq = new vector<string>(); eq->reserve(data->size());
    vector<string>* great = new vector<string>(); great->reserve(data->size());
    for (int i = 0; i < data->size(); ++i) {
        int ans = compare(data->at(i), data->at(pivot));
        if (ans < 0) {
            less->push_back(std::move(data->at(i)));
        } else if (ans > 0) {
            great->push_back(std::move(data->at(i)));
        } else {
            eq->push_back(std::move(data->at(i)));
        }
    }
    quick_sort(less);
    quick_sort(great);
    int ind = 0;
    for (int i = 0; i < less->size(); ++i) {
        data->at(ind) = std::move(less->at(i));
        ++ind;
    }
    for (int i = 0; i < eq->size(); ++i) {
        data->at(ind) = std::move(eq->at(i));
        ++ind;
    }
    for (int i = 0; i < great->size(); ++i) {
        data->at(ind) = std::move(great->at(i));
        ++ind;
    }
}

