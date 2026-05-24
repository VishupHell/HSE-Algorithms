#ifndef QUICKSORT_H
#define QUICKSORT_H
#include <vector>
#include <string>
#include <random>

#include "SortAlgorithm.h"

struct QuickSort : Algorithm {
  pair<int, int> apply(vector<string>& data, int len) override;
  QuickSort();
private:
  void quick_sort(vector<string>*, int l);
  int cnt = 0;
  std::random_device rd;
  std::mt19937 gen;
};

#endif //QUICKSORT_H
