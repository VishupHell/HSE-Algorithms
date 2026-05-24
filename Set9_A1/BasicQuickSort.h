#ifndef BASICQUICKSORT_H
#define BASICQUICKSORT_H

#include <vector>
#include <string>
#include <random>

#include "SortAlgorithm.h"

struct BasicQuickSort : Algorithm {
  pair<int, int> apply(vector<string>& data, int len) override;
  BasicQuickSort();
private:
  void quick_sort(vector<string>*);
  int compare(string& s1, string& s2);
  int cnt = 0;
  std::random_device rd;
  std::mt19937 gen;
};


#endif //BASICQUICKSORT_H
