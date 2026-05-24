
#ifndef RADIXSORT_H
#define RADIXSORT_H

#include <vector>
#include <string>
#include <random>

#include "../SortAlgorithm.h"

struct MSBRadixSort : Algorithm {
  pair<int, int> apply(vector<string>& data, int len) override;
private:
  void msb_radix_sort(vector<string>*, int l);
  int cnt = 0;
};


#endif //RADIXSORT_H
