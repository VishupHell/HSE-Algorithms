

#ifndef SORTALGORITHM_H
#define SORTALGORITHM_H

#include <vector>
#include <string>

using namespace std;

struct Algorithm {
  virtual pair<int, int> apply(vector<string>& data, int len) = 0;
};

#endif //SORTALGORITHM_H
