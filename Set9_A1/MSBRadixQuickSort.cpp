#include "MSBRadixQuickSort.h"
#include <chrono>

MSBRadixQuickSort::MSBRadixQuickSort() : rd(), gen(rd()) {}


pair<int, int> MSBRadixQuickSort::apply(vector<string> &data, int len) {
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

void MSBRadixQuickSort::msb_radix_sort(vector<string> *data, int L) {
    if (data->size() <= 74) {
        quick_sort(data, L);
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


void MSBRadixQuickSort::quick_sort(vector<string> *data, int L) {
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

