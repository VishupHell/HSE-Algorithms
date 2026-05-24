
#ifndef BASICMERGESORT_H
#define BASICMERGESORT_H


#include <vector>
#include "SortAlgorithm.h"

using namespace std;

struct BasicMergeSort : Algorithm {
  pair<int, int> apply(vector<string>& data, int len) override;
private:
  void merge_sort(vector<string>&, int l, int r);
  int cnt = 0;
  bool compare(string& s1, string& s2);
};


#endif //BASICMERGESORT_H
