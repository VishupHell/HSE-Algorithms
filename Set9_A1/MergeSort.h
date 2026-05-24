
#ifndef MERGESORT_H
#define MERGESORT_H

#include <vector>
#include "SortAlgorithm.h"
using namespace std;

struct MergeSort : Algorithm {
  pair<int, int> apply(vector<string>& data, int len) override;
private:
  void merge_sort(vector<pair<string, int>>&, int l, int r);
  pair<bool, int> LCPCompare(string& s1, string& s2, int k);
  int cnt = 0;
};

#endif //MERGESORT_H
