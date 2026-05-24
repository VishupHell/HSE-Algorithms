
#ifndef MSBRADIXQUICKSORT_H
#define MSBRADIXQUICKSORT_H

#include <vector>
#include <string>
#include <random>

#include "SortAlgorithm.h"

struct MSBRadixQuickSort : Algorithm {
  pair<int, int> apply(vector<string>& data, int len) override;
  MSBRadixQuickSort();
private:
  void msb_radix_sort(vector<string>*, int l);
  void quick_sort(vector<string>*, int l);
  int cnt = 0;
  std::random_device rd;
  std::mt19937 gen;
};



#endif //MSBRADIXQUICKSORT_H
