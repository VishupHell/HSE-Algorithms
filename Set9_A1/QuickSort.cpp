#include "QuickSort.h"
#include <chrono>

QuickSort::QuickSort() : rd(), gen(rd()) {}


pair<int, int> QuickSort::apply(vector<string> &data, int len) {
    cnt = 0;
  vector<string> cur(len);
  for (int i = 0; i < len; ++i) {
    cur[i] = data[i];
  }
  auto start = std::chrono::high_resolution_clock::now();
  quick_sort(&cur, 0);
  auto end = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
  return make_pair(duration, cnt);
}

void QuickSort::quick_sort(vector<string> *data, int L) {
  if (data->size() <= 1) {
        return;
    }
    std::uniform_int_distribution<> distr(0, data->size() - 1);
    int pivot = distr(gen);
    while (data->at(pivot).size() == L) {
        pivot = distr(gen);
    }
    string s = data->at(pivot);
    vector<string>* R_excl = new vector<string>(); R_excl->reserve(data->size());
    vector<string>* R_less = new vector<string>(); R_less->reserve(data->size());
    vector<string>* R_eq = new vector<string>(); R_eq->reserve(data->size());
    vector<string>* R_great = new vector<string>(); R_great->reserve(data->size());
    for (int i = 0; i < data->size(); ++i) {
        if (data->at(i).size() == L) {
            R_excl->push_back(std::move(data->at(i)));
            continue;
        }
        ++cnt;
        if (data->at(i)[L] < s[L]) {
            R_less->push_back(std::move(data->at(i)));
            continue;
        }
        if (data->at(i)[L] == s[L]) {
            R_eq->push_back(std::move(data->at(i)));
            continue;
        }
        if (data->at(i)[L] > s[L]) {
            R_great->push_back(std::move(data->at(i)));
            continue;
        }
    }
    quick_sort(R_less, L);
    quick_sort(R_eq, L + 1);
    quick_sort(R_great, L);
    int ind = 0;
    for (int i = 0; i < R_excl->size(); ++i) {
        data->at(ind) = std::move(R_excl->at(i));
        ++ind;
    }
    for (int i = 0; i < R_less->size(); ++i) {
        data->at(ind) = std::move(R_less->at(i));
        ++ind;
    }
    for (int i = 0; i < R_eq->size(); ++i) {
        data->at(ind) = std::move(R_eq->at(i));
        ++ind;
    }
    for (int i = 0; i < R_great->size(); ++i) {
        data->at(ind) = std::move(R_great->at(i));
        ++ind;
    }
    delete R_excl;
    delete R_less;
    delete R_eq;
    delete R_great;
}

